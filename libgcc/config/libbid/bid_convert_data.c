/* Copyright (C) 2007-2018 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#include "bid_internal.h"

// convert_table[j][k][i] = digit i (base 10^8) of k*2^(26+7*j)
const UINT32 convert_table[5][128][2] = {
  {{0, 0}
   , {67108864, 0}
   , {34217728, 1}
   , {1326592, 2}
   , {68435456, 2}
   ,
   {35544320, 3}
   , {2653184, 4}
   , {69762048, 4}
   , {36870912, 5}
   , {3979776, 6}
   ,
   {71088640, 6}
   , {38197504, 7}
   , {5306368, 8}
   , {72415232, 8}
   , {39524096, 9}
   ,
   {6632960, 10}
   , {73741824, 10}
   , {40850688, 11}
   , {7959552, 12}
   , {75068416, 12}
   ,
   {42177280, 13}
   , {9286144, 14}
   , {76395008, 14}
   , {43503872, 15}
   , {10612736, 16}
   ,
   {77721600, 16}
   , {44830464, 17}
   , {11939328, 18}
   , {79048192, 18}
   , {46157056, 19}
   ,
   {13265920, 20}
   , {80374784, 20}
   , {47483648, 21}
   , {14592512, 22}
   , {81701376, 22}
   ,
   {48810240, 23}
   , {15919104, 24}
   , {83027968, 24}
   , {50136832, 25}
   , {17245696, 26}
   ,
   {84354560, 26}
   , {51463424, 27}
   , {18572288, 28}
   , {85681152, 28}
   , {52790016, 29}
   ,
   {19898880, 30}
   , {87007744, 30}
   , {54116608, 31}
   , {21225472, 32}
   , {88334336, 32}
   ,
   {55443200, 33}
   , {22552064, 34}
   , {89660928, 34}
   , {56769792, 35}
   , {23878656, 36}
   ,
   {90987520, 36}
   , {58096384, 37}
   , {25205248, 38}
   , {92314112, 38}
   , {59422976, 39}
   ,
   {26531840, 40}
   , {93640704, 40}
   , {60749568, 41}
   , {27858432, 42}
   , {94967296, 42}
   ,
   {62076160, 43}
   , {29185024, 44}
   , {96293888, 44}
   , {63402752, 45}
   , {30511616, 46}
   ,
   {97620480, 46}
   , {64729344, 47}
   , {31838208, 48}
   , {98947072, 48}
   , {66055936, 49}
   ,
   {33164800, 50}
   , {273664, 51}
   , {67382528, 51}
   , {34491392, 52}
   , {1600256, 53}
   ,
   {68709120, 53}
   , {35817984, 54}
   , {2926848, 55}
   , {70035712, 55}
   , {37144576, 56}
   ,
   {4253440, 57}
   , {71362304, 57}
   , {38471168, 58}
   , {5580032, 59}
   , {72688896, 59}
   ,
   {39797760, 60}
   , {6906624, 61}
   , {74015488, 61}
   , {41124352, 62}
   , {8233216, 63}
   ,
   {75342080, 63}
   , {42450944, 64}
   , {9559808, 65}
   , {76668672, 65}
   , {43777536, 66}
   ,
   {10886400, 67}
   , {77995264, 67}
   , {45104128, 68}
   , {12212992, 69}
   , {79321856, 69}
   ,
   {46430720, 70}
   , {13539584, 71}
   , {80648448, 71}
   , {47757312, 72}
   , {14866176, 73}
   ,
   {81975040, 73}
   , {49083904, 74}
   , {16192768, 75}
   , {83301632, 75}
   , {50410496, 76}
   ,
   {17519360, 77}
   , {84628224, 77}
   , {51737088, 78}
   , {18845952, 79}
   , {85954816, 79}
   ,
   {53063680, 80}
   , {20172544, 81}
   , {87281408, 81}
   , {54390272, 82}
   , {21499136, 83}
   ,
   {88608000, 83}
   , {55716864, 84}
   , {22825728, 85}
   ,
   }
  ,

  {{0, 0}
   , {89934592, 85}
   , {79869184, 171}
   , {69803776, 257}
   , {59738368, 343}
   ,
   {49672960, 429}
   , {39607552, 515}
   , {29542144, 601}
   , {19476736, 687}
   , {9411328, 773}
   ,
   {99345920, 858}
   , {89280512, 944}
   , {79215104, 1030}
   , {69149696, 1116}
   , {59084288, 1202}
   ,
   {49018880, 1288}
   , {38953472, 1374}
   , {28888064, 1460}
   , {18822656, 1546}
   , {8757248, 1632}
   ,
   {98691840, 1717}
   , {88626432, 1803}
   , {78561024, 1889}
   , {68495616, 1975}
   , {58430208, 2061}
   ,
   {48364800, 2147}
   , {38299392, 2233}
   , {28233984, 2319}
   , {18168576, 2405}
   , {8103168, 2491}
   ,
   {98037760, 2576}
   , {87972352, 2662}
   , {77906944, 2748}
   , {67841536, 2834}
   , {57776128, 2920}
   ,
   {47710720, 3006}
   , {37645312, 3092}
   , {27579904, 3178}
   , {17514496, 3264}
   , {7449088, 3350}
   ,
   {97383680, 3435}
   , {87318272, 3521}
   , {77252864, 3607}
   , {67187456, 3693}
   , {57122048, 3779}
   ,
   {47056640, 3865}
   , {36991232, 3951}
   , {26925824, 4037}
   , {16860416, 4123}
   , {6795008, 4209}
   ,
   {96729600, 4294}
   , {86664192, 4380}
   , {76598784, 4466}
   , {66533376, 4552}
   , {56467968, 4638}
   ,
   {46402560, 4724}
   , {36337152, 4810}
   , {26271744, 4896}
   , {16206336, 4982}
   , {6140928, 5068}
   ,
   {96075520, 5153}
   , {86010112, 5239}
   , {75944704, 5325}
   , {65879296, 5411}
   , {55813888, 5497}
   ,
   {45748480, 5583}
   , {35683072, 5669}
   , {25617664, 5755}
   , {15552256, 5841}
   , {5486848, 5927}
   ,
   {95421440, 6012}
   , {85356032, 6098}
   , {75290624, 6184}
   , {65225216, 6270}
   , {55159808, 6356}
   ,
   {45094400, 6442}
   , {35028992, 6528}
   , {24963584, 6614}
   , {14898176, 6700}
   , {4832768, 6786}
   ,
   {94767360, 6871}
   , {84701952, 6957}
   , {74636544, 7043}
   , {64571136, 7129}
   , {54505728, 7215}
   ,
   {44440320, 7301}
   , {34374912, 7387}
   , {24309504, 7473}
   , {14244096, 7559}
   , {4178688, 7645}
   ,
   {94113280, 7730}
   , {84047872, 7816}
   , {73982464, 7902}
   , {63917056, 7988}
   , {53851648, 8074}
   ,
   {43786240, 8160}
   , {33720832, 8246}
   , {23655424, 8332}
   , {13590016, 8418}
   , {3524608, 8504}
   ,
   {93459200, 8589}
   , {83393792, 8675}
   , {73328384, 8761}
   , {63262976, 8847}
   , {53197568, 8933}
   ,
   {43132160, 9019}
   , {33066752, 9105}
   , {23001344, 9191}
   , {12935936, 9277}
   , {2870528, 9363}
   ,
   {92805120, 9448}
   , {82739712, 9534}
   , {72674304, 9620}
   , {62608896, 9706}
   , {52543488, 9792}
   ,
   {42478080, 9878}
   , {32412672, 9964}
   , {22347264, 10050}
   , {12281856, 10136}
   , {2216448, 10222}
   ,
   {92151040, 10307}
   , {82085632, 10393}
   , {72020224, 10479}
   , {61954816, 10565}
   , {51889408, 10651}
   ,
   {41824000, 10737}
   , {31758592, 10823}
   , {21693184, 10909}
   ,
   }
  ,

  {{0, 0}
   , {11627776, 10995}
   , {23255552, 21990}
   , {34883328, 32985}
   , {46511104, 43980}
   ,
   {58138880, 54975}
   , {69766656, 65970}
   , {81394432, 76965}
   , {93022208, 87960}
   , {4649984, 98956}
   ,
   {16277760, 109951}
   , {27905536, 120946}
   , {39533312, 131941}
   , {51161088, 142936}
   , {62788864, 153931}
   ,
   {74416640, 164926}
   , {86044416, 175921}
   , {97672192, 186916}
   , {9299968, 197912}
   , {20927744, 208907}
   ,
   {32555520, 219902}
   , {44183296, 230897}
   , {55811072, 241892}
   , {67438848, 252887}
   , {79066624, 263882}
   ,
   {90694400, 274877}
   , {2322176, 285873}
   , {13949952, 296868}
   , {25577728, 307863}
   , {37205504, 318858}
   ,
   {48833280, 329853}
   , {60461056, 340848}
   , {72088832, 351843}
   , {83716608, 362838}
   , {95344384, 373833}
   ,
   {6972160, 384829}
   , {18599936, 395824}
   , {30227712, 406819}
   , {41855488, 417814}
   , {53483264, 428809}
   ,
   {65111040, 439804}
   , {76738816, 450799}
   , {88366592, 461794}
   , {99994368, 472789}
   , {11622144, 483785}
   ,
   {23249920, 494780}
   , {34877696, 505775}
   , {46505472, 516770}
   , {58133248, 527765}
   , {69761024, 538760}
   ,
   {81388800, 549755}
   , {93016576, 560750}
   , {4644352, 571746}
   , {16272128, 582741}
   , {27899904, 593736}
   ,
   {39527680, 604731}
   , {51155456, 615726}
   , {62783232, 626721}
   , {74411008, 637716}
   , {86038784, 648711}
   ,
   {97666560, 659706}
   , {9294336, 670702}
   , {20922112, 681697}
   , {32549888, 692692}
   , {44177664, 703687}
   ,
   {55805440, 714682}
   , {67433216, 725677}
   , {79060992, 736672}
   , {90688768, 747667}
   , {2316544, 758663}
   ,
   {13944320, 769658}
   , {25572096, 780653}
   , {37199872, 791648}
   , {48827648, 802643}
   , {60455424, 813638}
   ,
   {72083200, 824633}
   , {83710976, 835628}
   , {95338752, 846623}
   , {6966528, 857619}
   , {18594304, 868614}
   ,
   {30222080, 879609}
   , {41849856, 890604}
   , {53477632, 901599}
   , {65105408, 912594}
   , {76733184, 923589}
   ,
   {88360960, 934584}
   , {99988736, 945579}
   , {11616512, 956575}
   , {23244288, 967570}
   , {34872064, 978565}
   ,
   {46499840, 989560}
   , {58127616, 1000555}
   , {69755392, 1011550}
   , {81383168, 1022545}
   , {93010944, 1033540}
   ,
   {4638720, 1044536}
   , {16266496, 1055531}
   , {27894272, 1066526}
   , {39522048, 1077521}
   , {51149824, 1088516}
   ,
   {62777600, 1099511}
   , {74405376, 1110506}
   , {86033152, 1121501}
   , {97660928, 1132496}
   , {9288704, 1143492}
   ,
   {20916480, 1154487}
   , {32544256, 1165482}
   , {44172032, 1176477}
   , {55799808, 1187472}
   , {67427584, 1198467}
   ,
   {79055360, 1209462}
   , {90683136, 1220457}
   , {2310912, 1231453}
   , {13938688, 1242448}
   , {25566464, 1253443}
   ,
   {37194240, 1264438}
   , {48822016, 1275433}
   , {60449792, 1286428}
   , {72077568, 1297423}
   , {83705344, 1308418}
   ,
   {95333120, 1319413}
   , {6960896, 1330409}
   , {18588672, 1341404}
   , {30216448, 1352399}
   , {41844224, 1363394}
   ,
   {53472000, 1374389}
   , {65099776, 1385384}
   , {76727552, 1396379}
   ,
   }
  ,

  {{0, 0}
   , {88355328, 1407374}
   , {76710656, 2814749}
   , {65065984, 4222124}
   , {53421312, 5629499}
   ,
   {41776640, 7036874}
   , {30131968, 8444249}
   , {18487296, 9851624}
   , {6842624, 11258999}
   , {95197952, 12666373}
   ,
   {83553280, 14073748}
   , {71908608, 15481123}
   , {60263936, 16888498}
   , {48619264, 18295873}
   , {36974592, 19703248}
   ,
   {25329920, 21110623}
   , {13685248, 22517998}
   , {2040576, 23925373}
   , {90395904, 25332747}
   , {78751232, 26740122}
   ,
   {67106560, 28147497}
   , {55461888, 29554872}
   , {43817216, 30962247}
   , {32172544, 32369622}
   , {20527872, 33776997}
   ,
   {8883200, 35184372}
   , {97238528, 36591746}
   , {85593856, 37999121}
   , {73949184, 39406496}
   , {62304512, 40813871}
   ,
   {50659840, 42221246}
   , {39015168, 43628621}
   , {27370496, 45035996}
   , {15725824, 46443371}
   , {4081152, 47850746}
   ,
   {92436480, 49258120}
   , {80791808, 50665495}
   , {69147136, 52072870}
   , {57502464, 53480245}
   , {45857792, 54887620}
   ,
   {34213120, 56294995}
   , {22568448, 57702370}
   , {10923776, 59109745}
   , {99279104, 60517119}
   , {87634432, 61924494}
   ,
   {75989760, 63331869}
   , {64345088, 64739244}
   , {52700416, 66146619}
   , {41055744, 67553994}
   , {29411072, 68961369}
   ,
   {17766400, 70368744}
   , {6121728, 71776119}
   , {94477056, 73183493}
   , {82832384, 74590868}
   , {71187712, 75998243}
   ,
   {59543040, 77405618}
   , {47898368, 78812993}
   , {36253696, 80220368}
   , {24609024, 81627743}
   , {12964352, 83035118}
   ,
   {1319680, 84442493}
   , {89675008, 85849867}
   , {78030336, 87257242}
   , {66385664, 88664617}
   , {54740992, 90071992}
   ,
   {43096320, 91479367}
   , {31451648, 92886742}
   , {19806976, 94294117}
   , {8162304, 95701492}
   , {96517632, 97108866}
   ,
   {84872960, 98516241}
   , {73228288, 99923616}
   , {61583616, 1330991}
   , {49938944, 2738366}
   , {38294272, 4145741}
   ,
   {26649600, 5553116}
   , {15004928, 6960491}
   , {3360256, 8367866}
   , {91715584, 9775240}
   , {80070912, 11182615}
   ,
   {68426240, 12589990}
   , {56781568, 13997365}
   , {45136896, 15404740}
   , {33492224, 16812115}
   , {21847552, 18219490}
   ,
   {10202880, 19626865}
   , {98558208, 21034239}
   , {86913536, 22441614}
   , {75268864, 23848989}
   , {63624192, 25256364}
   ,
   {51979520, 26663739}
   , {40334848, 28071114}
   , {28690176, 29478489}
   , {17045504, 30885864}
   , {5400832, 32293239}
   ,
   {93756160, 33700613}
   , {82111488, 35107988}
   , {70466816, 36515363}
   , {58822144, 37922738}
   , {47177472, 39330113}
   ,
   {35532800, 40737488}
   , {23888128, 42144863}
   , {12243456, 43552238}
   , {598784, 44959613}
   , {88954112, 46366987}
   ,
   {77309440, 47774362}
   , {65664768, 49181737}
   , {54020096, 50589112}
   , {42375424, 51996487}
   , {30730752, 53403862}
   ,
   {19086080, 54811237}
   , {7441408, 56218612}
   , {95796736, 57625986}
   , {84152064, 59033361}
   , {72507392, 60440736}
   ,
   {60862720, 61848111}
   , {49218048, 63255486}
   , {37573376, 64662861}
   , {25928704, 66070236}
   , {14284032, 67477611}
   ,
   {2639360, 68884986}
   , {90994688, 70292360}
   , {79350016, 71699735}
   , {67705344, 73107110}
   , {56060672, 74514485}
   ,
   {44416000, 75921860}
   , {32771328, 77329235}
   , {21126656, 78736610}
   ,
   }
  ,

  {{0, 0}
   , {9481984, 80143985}
   , {18963968, 60287970}
   , {28445952, 40431955}
   , {37927936, 20575940}
   ,
   {47409920, 719925}
   , {56891904, 80863910}
   , {66373888, 61007895}
   , {75855872, 41151880}
   , {85337856, 21295865}
   ,
   {94819840, 1439850}
   , {4301824, 81583836}
   , {13783808, 61727821}
   , {23265792, 41871806}
   , {32747776, 22015791}
   ,
   {42229760, 2159776}
   , {51711744, 82303761}
   , {61193728, 62447746}
   , {70675712, 42591731}
   , {80157696, 22735716}
   ,
   {89639680, 2879701}
   , {99121664, 83023686}
   , {8603648, 63167672}
   , {18085632, 43311657}
   , {27567616, 23455642}
   ,
   {37049600, 3599627}
   , {46531584, 83743612}
   , {56013568, 63887597}
   , {65495552, 44031582}
   , {74977536, 24175567}
   ,
   {84459520, 4319552}
   , {93941504, 84463537}
   , {3423488, 64607523}
   , {12905472, 44751508}
   , {22387456, 24895493}
   ,
   {31869440, 5039478}
   , {41351424, 85183463}
   , {50833408, 65327448}
   , {60315392, 45471433}
   , {69797376, 25615418}
   ,
   {79279360, 5759403}
   , {88761344, 85903388}
   , {98243328, 66047373}
   , {7725312, 46191359}
   , {17207296, 26335344}
   ,
   {26689280, 6479329}
   , {36171264, 86623314}
   , {45653248, 66767299}
   , {55135232, 46911284}
   , {64617216, 27055269}
   ,
   {74099200, 7199254}
   , {83581184, 87343239}
   , {93063168, 67487224}
   , {2545152, 47631210}
   , {12027136, 27775195}
   ,
   {21509120, 7919180}
   , {30991104, 88063165}
   , {40473088, 68207150}
   , {49955072, 48351135}
   , {59437056, 28495120}
   ,
   {68919040, 8639105}
   , {78401024, 88783090}
   , {87883008, 68927075}
   , {97364992, 49071060}
   , {6846976, 29215046}
   ,
   {16328960, 9359031}
   , {25810944, 89503016}
   , {35292928, 69647001}
   , {44774912, 49790986}
   , {54256896, 29934971}
   ,
   {63738880, 10078956}
   , {73220864, 90222941}
   , {82702848, 70366926}
   , {92184832, 50510911}
   , {1666816, 30654897}
   ,
   {11148800, 10798882}
   , {20630784, 90942867}
   , {30112768, 71086852}
   , {39594752, 51230837}
   , {49076736, 31374822}
   ,
   {58558720, 11518807}
   , {68040704, 91662792}
   , {77522688, 71806777}
   , {87004672, 51950762}
   , {96486656, 32094747}
   ,
   {5968640, 12238733}
   , {15450624, 92382718}
   , {24932608, 72526703}
   , {34414592, 52670688}
   , {43896576, 32814673}
   ,
   {53378560, 12958658}
   , {62860544, 93102643}
   , {72342528, 73246628}
   , {81824512, 53390613}
   , {91306496, 33534598}
   ,
   {788480, 13678584}
   , {10270464, 93822569}
   , {19752448, 73966554}
   , {29234432, 54110539}
   , {38716416, 34254524}
   ,
   {48198400, 14398509}
   , {57680384, 94542494}
   , {67162368, 74686479}
   , {76644352, 54830464}
   , {86126336, 34974449}
   ,
   {95608320, 15118434}
   , {5090304, 95262420}
   , {14572288, 75406405}
   , {24054272, 55550390}
   , {33536256, 35694375}
   ,
   {43018240, 15838360}
   , {52500224, 95982345}
   , {61982208, 76126330}
   , {71464192, 56270315}
   , {80946176, 36414300}
   ,
   {90428160, 16558285}
   , {99910144, 96702270}
   , {9392128, 76846256}
   , {18874112, 56990241}
   , {28356096, 37134226}
   ,
   {37838080, 17278211}
   , {47320064, 97422196}
   , {56802048, 77566181}
   , {66284032, 57710166}
   , {75766016, 37854151}
   ,
   {85248000, 17998136}
   , {94729984, 98142121}
   , {4211968, 78286107}
   ,
   }
  ,
};

// for j>=min_j[i+1], there is k s.t. convert_table[i][j][k]>0
// int min_j[] = { 0, 0, 0, 3 };

// for even k, ((packed_10000_zeros[k>>3])>>(k&7))&3)=greatest(i) s.t. 10^i divides k
const UINT8 packed_10000_zeros[] = {

  0x3, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x20, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x3, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x2,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x20, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x3, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x20,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x2, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x3, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x20, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x3, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x2, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x2,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x3, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x20, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x20,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x3, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x20, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x3, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x2, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x2,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x3, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x20, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x20,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x1, 0x4, 0x10, 0x40, 0x0, 0x3, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10,
  0x40, 0x0, 0x1,
  0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40,
  0x0, 0x2, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40, 0x0, 0x1,
  0x4, 0x10, 0x40,
  0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4,
  0x10, 0x40, 0x0,
  0x2, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x20,
  0x40, 0x0, 0x1,
  0x4, 0x10, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0, 0x2, 0x4, 0x10, 0x40,
  0x0, 0x1, 0x4,
  0x10, 0x40, 0x0, 0x1, 0x4, 0x20, 0x40, 0x0, 0x1, 0x4, 0x10, 0x40, 0x0,
  0x1, 0x4, 0x10,
  0x40, 0x0,
};


const SINT8 factors[1024][2] = {
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 2}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {5, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 2}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {6, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 2}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {5, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 2}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 3}
  , {1, 0}
  , {0, 0}
  , {7, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 2}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {5, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 2}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {6, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 2}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {5, 0}
  , {0, 2}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 3}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {8, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 2}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {5, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 2}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {6, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 2}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 2}
  ,
  {0, 0}
  , {5, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 3}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {7, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 2}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {5, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 2}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {6, 0}
  , {0, 0}
  , {1, 2}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 2}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {5, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 3}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {9, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 2}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {5, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 2}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 2}
  , {6, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 2}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {5, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 4}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {7, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 2}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {5, 0}
  , {0, 0}
  , {1, 0}
  , {0, 2}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 2}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {6, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 2}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {5, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 3}
  ,
  {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {8, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 2}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {5, 2}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 2}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {6, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 2}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {5, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 3}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {7, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 2}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 2}
  , {1, 0}
  , {0, 0}
  , {5, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 2}
  ,
  {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {6, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 2}
  , {4, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {5, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {3, 3}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 0}
  , {0, 1}
  , {1, 0}
  , {0, 0}
  , {4, 0}
  , {0, 0}
  , {1, 1}
  ,
  {0, 0}
  , {2, 0}
  , {0, 0}
  , {1, 0}
  , {0, 1}
  , {3, 0}
  , {0, 0}
  , {1, 0}
  , {0, 0}
  , {2, 1}
  ,
  {0, 0}
  , {1, 0}
  , {0, 0}
  , {10, 0}
  ,
};
