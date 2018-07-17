#  Copyright (C) 2013-2018 Free Software Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 3, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING3.  If not see
# <http://www.gnu.org/licenses/>.

# This Awk script takes passes.def and writes pass-instances.def,
# counting the instances of each kind of pass, adding an instance number
# to everywhere that NEXT_PASS is used.
# Also handle INSERT_PASS_AFTER, INSERT_PASS_BEFORE and REPLACE_PASS
# directives.
#
# For example, the single-instanced pass:
#     NEXT_PASS (pass_warn_unused_result);
# becomes this in the output:
#     NEXT_PASS (pass_warn_unused_result, 1);
#
# The various instances of
#   NEXT_PASS (pass_copy_prop);
# become:
#   NEXT_PASS (pass_copy_prop, 1);
# through:
#   NEXT_PASS (pass_copy_prop, 8);
# (currently there are 8 instances of that pass)
#
#     INSERT_PASS_AFTER (pass_copy_prop, 1, pass_stv);
# will insert
#     NEXT_PASS (pass_stv, 1);
# immediately after the NEXT_PASS (pass_copy_prop, 1) line,
# similarly INSERT_PASS_BEFORE inserts immediately before that line.
#     REPLACE_PASS (pass_copy_prop, 1, pass_stv, true);
# will replace NEXT_PASS (pass_copy_prop, 1) line with
#     NEXT_PASS (pass_stv, 1, true);
# line and renumber all higher pass_copy_prop instances if any.

# Usage: awk -f gen-pass-instances.awk passes.def

BEGIN {
  print "/* This file is auto-generated by gen-pass-instances.awk";
  print "   from passes.def.  */";
  lineno = 1;
}

function parse_line(line, fnname,	len_of_call, len_of_start,
					len_of_open, len_of_close,
					len_of_args, args_start_at,
					args_str, len_of_prefix,
					call_starts_at,
					postfix_starts_at)
{
  # Find call expression.
  call_starts_at = match(line, fnname " \\(.+\\)");
  if (call_starts_at == 0)
    return 0;

  # Length of the call expression.
  len_of_call = RLENGTH;

  len_of_start = length(fnname " (");
  len_of_open = length("(");
  len_of_close = length(")");

  # Find arguments
  len_of_args = len_of_call - (len_of_start + len_of_close);
  args_start_at = call_starts_at + len_of_start;
  args_str = substr(line, args_start_at, len_of_args);
  split(args_str, args, ",");

  # Find call expression prefix
  len_of_prefix = call_starts_at - 1;
  prefix = substr(line, 1, len_of_prefix);

  # Find call expression postfix
  postfix_starts_at = call_starts_at + len_of_call;
  postfix = substr(line, postfix_starts_at);
  return 1;
}

function adjust_linenos(above, increment,	p, i)
{
  for (p in pass_lines)
    if (pass_lines[p] >= above)
      pass_lines[p] += increment;
  if (increment > 0)
    for (i = lineno - 1; i >= above; i--)
      lines[i + increment] = lines[i];
  else
    for (i = above; i < lineno; i++)
      lines[i + increment] = lines[i];
  lineno += increment;
}

function insert_remove_pass(line, fnname,	arg3)
{
  parse_line($0, fnname);
  pass_name = args[1];
  if (pass_name == "PASS")
    return 1;
  pass_num = args[2] + 0;
  arg3 = args[3];
  sub(/^[ \t]*/, "", arg3);
  new_line = prefix "NEXT_PASS (" arg3;
  if (args[4])
    new_line = new_line "," args[4];
  new_line = new_line ")" postfix;
  if (!pass_lines[pass_name, pass_num])
    {
      print "ERROR: Can't locate instance of the pass mentioned in " fnname;
      return 1;
    }
  return 0;
}

function insert_pass(line, fnname, after,		num)
{
  if (insert_remove_pass(line, fnname))
    return;
  num = pass_lines[pass_name, pass_num];
  adjust_linenos(num + after, 1);
  pass_name = args[3];
  # Set pass_counts
  if (args[3] in pass_counts)
    pass_counts[pass_name]++;
  else
    pass_counts[pass_name] = 1;

  pass_lines[pass_name, pass_counts[pass_name]] = num + after;
  lines[num + after] = new_line;
}

function replace_pass(line, fnname,			num, i)
{
  if (insert_remove_pass(line, "REPLACE_PASS"))
    return;
  num = pass_lines[pass_name, pass_num];
  for (i = pass_counts[pass_name]; i > pass_num; i--)
    pass_lines[pass_name, i - 1] = pass_lines[pass_name, i];
  delete pass_lines[pass_name, pass_counts[pass_name]];
  if (pass_counts[pass_name] == 1)
    delete pass_counts[pass_name];
  else
    pass_counts[pass_name]--;

  pass_name = args[3];
  # Set pass_counts
  if (args[3] in pass_counts)
    pass_counts[pass_name]++;
  else
    pass_counts[pass_name] = 1;

  pass_lines[pass_name, pass_counts[pass_name]] = num;
  lines[num] = new_line;
}

/INSERT_PASS_AFTER \(.+\)/ {
  insert_pass($0, "INSERT_PASS_AFTER", 1);
  next;
}

/INSERT_PASS_BEFORE \(.+\)/ {
  insert_pass($0, "INSERT_PASS_BEFORE", 0);
  next;
}

/REPLACE_PASS \(.+\)/ {
  replace_pass($0, "REPLACE_PASS");
  next;
}

{
  ret = parse_line($0, "NEXT_PASS");
  if (ret)
    {
      pass_name = args[1];

      # Set pass_counts
      if (pass_name in pass_counts)
	pass_counts[pass_name]++;
      else
	pass_counts[pass_name] = 1;

      pass_lines[pass_name, pass_counts[pass_name]] = lineno;
    }
  lines[lineno++] = $0;
}

END {
  for (i = 1; i < lineno; i++)
    {
      ret = parse_line(lines[i], "NEXT_PASS");
      if (ret)
	{
	  # Set pass_name argument, an optional with_arg argument
	  pass_name = args[1];
	  with_arg = args[2];

	  # Set pass_final_counts
	  if (pass_name in pass_final_counts)
	    pass_final_counts[pass_name]++;
	  else
	    pass_final_counts[pass_name] = 1;

	  pass_num = pass_final_counts[pass_name];

	  # Print call expression with extra pass_num argument
	  printf "%s", prefix;
	  if (with_arg)
	    printf "NEXT_PASS_WITH_ARG";
	  else
	    printf "NEXT_PASS";
	  printf " (%s, %s", pass_name, pass_num;
	  if (with_arg)
	    printf ",%s", with_arg;
	  printf ")%s\n", postfix;
	}
      else
	print lines[i];
    }
}

# Local Variables:
# mode:awk
# c-basic-offset:8
# End:
