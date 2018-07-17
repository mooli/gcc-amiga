// Copyright 2013 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// DO NOT EDIT.  GENERATED BY
//     go run makeisprint.go -output isprint.go

package strconv

// (456+140+86)*2 + (396)*4 = 2948 bytes

var isPrint16 = []uint16{
	0x0020, 0x007e,
	0x00a1, 0x0377,
	0x037a, 0x037f,
	0x0384, 0x0556,
	0x0559, 0x058a,
	0x058d, 0x05c7,
	0x05d0, 0x05ea,
	0x05f0, 0x05f4,
	0x0606, 0x061b,
	0x061e, 0x070d,
	0x0710, 0x074a,
	0x074d, 0x07b1,
	0x07c0, 0x07fa,
	0x0800, 0x082d,
	0x0830, 0x085b,
	0x085e, 0x086a,
	0x08a0, 0x08bd,
	0x08d4, 0x098c,
	0x098f, 0x0990,
	0x0993, 0x09b2,
	0x09b6, 0x09b9,
	0x09bc, 0x09c4,
	0x09c7, 0x09c8,
	0x09cb, 0x09ce,
	0x09d7, 0x09d7,
	0x09dc, 0x09e3,
	0x09e6, 0x09fd,
	0x0a01, 0x0a0a,
	0x0a0f, 0x0a10,
	0x0a13, 0x0a39,
	0x0a3c, 0x0a42,
	0x0a47, 0x0a48,
	0x0a4b, 0x0a4d,
	0x0a51, 0x0a51,
	0x0a59, 0x0a5e,
	0x0a66, 0x0a75,
	0x0a81, 0x0ab9,
	0x0abc, 0x0acd,
	0x0ad0, 0x0ad0,
	0x0ae0, 0x0ae3,
	0x0ae6, 0x0af1,
	0x0af9, 0x0b0c,
	0x0b0f, 0x0b10,
	0x0b13, 0x0b39,
	0x0b3c, 0x0b44,
	0x0b47, 0x0b48,
	0x0b4b, 0x0b4d,
	0x0b56, 0x0b57,
	0x0b5c, 0x0b63,
	0x0b66, 0x0b77,
	0x0b82, 0x0b8a,
	0x0b8e, 0x0b95,
	0x0b99, 0x0b9f,
	0x0ba3, 0x0ba4,
	0x0ba8, 0x0baa,
	0x0bae, 0x0bb9,
	0x0bbe, 0x0bc2,
	0x0bc6, 0x0bcd,
	0x0bd0, 0x0bd0,
	0x0bd7, 0x0bd7,
	0x0be6, 0x0bfa,
	0x0c00, 0x0c39,
	0x0c3d, 0x0c4d,
	0x0c55, 0x0c5a,
	0x0c60, 0x0c63,
	0x0c66, 0x0c6f,
	0x0c78, 0x0cb9,
	0x0cbc, 0x0ccd,
	0x0cd5, 0x0cd6,
	0x0cde, 0x0ce3,
	0x0ce6, 0x0cf2,
	0x0d00, 0x0d4f,
	0x0d54, 0x0d63,
	0x0d66, 0x0d7f,
	0x0d82, 0x0d96,
	0x0d9a, 0x0dbd,
	0x0dc0, 0x0dc6,
	0x0dca, 0x0dca,
	0x0dcf, 0x0ddf,
	0x0de6, 0x0def,
	0x0df2, 0x0df4,
	0x0e01, 0x0e3a,
	0x0e3f, 0x0e5b,
	0x0e81, 0x0e84,
	0x0e87, 0x0e8a,
	0x0e8d, 0x0e8d,
	0x0e94, 0x0ea7,
	0x0eaa, 0x0ebd,
	0x0ec0, 0x0ecd,
	0x0ed0, 0x0ed9,
	0x0edc, 0x0edf,
	0x0f00, 0x0f6c,
	0x0f71, 0x0fda,
	0x1000, 0x10c7,
	0x10cd, 0x10cd,
	0x10d0, 0x124d,
	0x1250, 0x125d,
	0x1260, 0x128d,
	0x1290, 0x12b5,
	0x12b8, 0x12c5,
	0x12c8, 0x1315,
	0x1318, 0x135a,
	0x135d, 0x137c,
	0x1380, 0x1399,
	0x13a0, 0x13f5,
	0x13f8, 0x13fd,
	0x1400, 0x169c,
	0x16a0, 0x16f8,
	0x1700, 0x1714,
	0x1720, 0x1736,
	0x1740, 0x1753,
	0x1760, 0x1773,
	0x1780, 0x17dd,
	0x17e0, 0x17e9,
	0x17f0, 0x17f9,
	0x1800, 0x180d,
	0x1810, 0x1819,
	0x1820, 0x1877,
	0x1880, 0x18aa,
	0x18b0, 0x18f5,
	0x1900, 0x192b,
	0x1930, 0x193b,
	0x1940, 0x1940,
	0x1944, 0x196d,
	0x1970, 0x1974,
	0x1980, 0x19ab,
	0x19b0, 0x19c9,
	0x19d0, 0x19da,
	0x19de, 0x1a1b,
	0x1a1e, 0x1a7c,
	0x1a7f, 0x1a89,
	0x1a90, 0x1a99,
	0x1aa0, 0x1aad,
	0x1ab0, 0x1abe,
	0x1b00, 0x1b4b,
	0x1b50, 0x1b7c,
	0x1b80, 0x1bf3,
	0x1bfc, 0x1c37,
	0x1c3b, 0x1c49,
	0x1c4d, 0x1c88,
	0x1cc0, 0x1cc7,
	0x1cd0, 0x1cf9,
	0x1d00, 0x1f15,
	0x1f18, 0x1f1d,
	0x1f20, 0x1f45,
	0x1f48, 0x1f4d,
	0x1f50, 0x1f7d,
	0x1f80, 0x1fd3,
	0x1fd6, 0x1fef,
	0x1ff2, 0x1ffe,
	0x2010, 0x2027,
	0x2030, 0x205e,
	0x2070, 0x2071,
	0x2074, 0x209c,
	0x20a0, 0x20bf,
	0x20d0, 0x20f0,
	0x2100, 0x218b,
	0x2190, 0x2426,
	0x2440, 0x244a,
	0x2460, 0x2b73,
	0x2b76, 0x2b95,
	0x2b98, 0x2bb9,
	0x2bbd, 0x2bd2,
	0x2bec, 0x2bef,
	0x2c00, 0x2cf3,
	0x2cf9, 0x2d27,
	0x2d2d, 0x2d2d,
	0x2d30, 0x2d67,
	0x2d6f, 0x2d70,
	0x2d7f, 0x2d96,
	0x2da0, 0x2e49,
	0x2e80, 0x2ef3,
	0x2f00, 0x2fd5,
	0x2ff0, 0x2ffb,
	0x3001, 0x3096,
	0x3099, 0x30ff,
	0x3105, 0x312e,
	0x3131, 0x31ba,
	0x31c0, 0x31e3,
	0x31f0, 0x4db5,
	0x4dc0, 0x9fea,
	0xa000, 0xa48c,
	0xa490, 0xa4c6,
	0xa4d0, 0xa62b,
	0xa640, 0xa6f7,
	0xa700, 0xa7b7,
	0xa7f7, 0xa82b,
	0xa830, 0xa839,
	0xa840, 0xa877,
	0xa880, 0xa8c5,
	0xa8ce, 0xa8d9,
	0xa8e0, 0xa8fd,
	0xa900, 0xa953,
	0xa95f, 0xa97c,
	0xa980, 0xa9d9,
	0xa9de, 0xaa36,
	0xaa40, 0xaa4d,
	0xaa50, 0xaa59,
	0xaa5c, 0xaac2,
	0xaadb, 0xaaf6,
	0xab01, 0xab06,
	0xab09, 0xab0e,
	0xab11, 0xab16,
	0xab20, 0xab65,
	0xab70, 0xabed,
	0xabf0, 0xabf9,
	0xac00, 0xd7a3,
	0xd7b0, 0xd7c6,
	0xd7cb, 0xd7fb,
	0xf900, 0xfa6d,
	0xfa70, 0xfad9,
	0xfb00, 0xfb06,
	0xfb13, 0xfb17,
	0xfb1d, 0xfbc1,
	0xfbd3, 0xfd3f,
	0xfd50, 0xfd8f,
	0xfd92, 0xfdc7,
	0xfdf0, 0xfdfd,
	0xfe00, 0xfe19,
	0xfe20, 0xfe6b,
	0xfe70, 0xfefc,
	0xff01, 0xffbe,
	0xffc2, 0xffc7,
	0xffca, 0xffcf,
	0xffd2, 0xffd7,
	0xffda, 0xffdc,
	0xffe0, 0xffee,
	0xfffc, 0xfffd,
}

var isNotPrint16 = []uint16{
	0x00ad,
	0x038b,
	0x038d,
	0x03a2,
	0x0530,
	0x0560,
	0x0588,
	0x0590,
	0x06dd,
	0x083f,
	0x085f,
	0x08b5,
	0x08e2,
	0x0984,
	0x09a9,
	0x09b1,
	0x09de,
	0x0a04,
	0x0a29,
	0x0a31,
	0x0a34,
	0x0a37,
	0x0a3d,
	0x0a5d,
	0x0a84,
	0x0a8e,
	0x0a92,
	0x0aa9,
	0x0ab1,
	0x0ab4,
	0x0ac6,
	0x0aca,
	0x0b00,
	0x0b04,
	0x0b29,
	0x0b31,
	0x0b34,
	0x0b5e,
	0x0b84,
	0x0b91,
	0x0b9b,
	0x0b9d,
	0x0bc9,
	0x0c04,
	0x0c0d,
	0x0c11,
	0x0c29,
	0x0c45,
	0x0c49,
	0x0c57,
	0x0c84,
	0x0c8d,
	0x0c91,
	0x0ca9,
	0x0cb4,
	0x0cc5,
	0x0cc9,
	0x0cdf,
	0x0cf0,
	0x0d04,
	0x0d0d,
	0x0d11,
	0x0d45,
	0x0d49,
	0x0d84,
	0x0db2,
	0x0dbc,
	0x0dd5,
	0x0dd7,
	0x0e83,
	0x0e89,
	0x0e98,
	0x0ea0,
	0x0ea4,
	0x0ea6,
	0x0eac,
	0x0eba,
	0x0ec5,
	0x0ec7,
	0x0f48,
	0x0f98,
	0x0fbd,
	0x0fcd,
	0x10c6,
	0x1249,
	0x1257,
	0x1259,
	0x1289,
	0x12b1,
	0x12bf,
	0x12c1,
	0x12d7,
	0x1311,
	0x1680,
	0x170d,
	0x176d,
	0x1771,
	0x191f,
	0x1a5f,
	0x1dfa,
	0x1f58,
	0x1f5a,
	0x1f5c,
	0x1f5e,
	0x1fb5,
	0x1fc5,
	0x1fdc,
	0x1ff5,
	0x208f,
	0x2bc9,
	0x2c2f,
	0x2c5f,
	0x2d26,
	0x2da7,
	0x2daf,
	0x2db7,
	0x2dbf,
	0x2dc7,
	0x2dcf,
	0x2dd7,
	0x2ddf,
	0x2e9a,
	0x3040,
	0x318f,
	0x321f,
	0x32ff,
	0xa7af,
	0xa9ce,
	0xa9ff,
	0xab27,
	0xab2f,
	0xfb37,
	0xfb3d,
	0xfb3f,
	0xfb42,
	0xfb45,
	0xfe53,
	0xfe67,
	0xfe75,
	0xffe7,
}

var isPrint32 = []uint32{
	0x010000, 0x01004d,
	0x010050, 0x01005d,
	0x010080, 0x0100fa,
	0x010100, 0x010102,
	0x010107, 0x010133,
	0x010137, 0x01019b,
	0x0101a0, 0x0101a0,
	0x0101d0, 0x0101fd,
	0x010280, 0x01029c,
	0x0102a0, 0x0102d0,
	0x0102e0, 0x0102fb,
	0x010300, 0x010323,
	0x01032d, 0x01034a,
	0x010350, 0x01037a,
	0x010380, 0x0103c3,
	0x0103c8, 0x0103d5,
	0x010400, 0x01049d,
	0x0104a0, 0x0104a9,
	0x0104b0, 0x0104d3,
	0x0104d8, 0x0104fb,
	0x010500, 0x010527,
	0x010530, 0x010563,
	0x01056f, 0x01056f,
	0x010600, 0x010736,
	0x010740, 0x010755,
	0x010760, 0x010767,
	0x010800, 0x010805,
	0x010808, 0x010838,
	0x01083c, 0x01083c,
	0x01083f, 0x01089e,
	0x0108a7, 0x0108af,
	0x0108e0, 0x0108f5,
	0x0108fb, 0x01091b,
	0x01091f, 0x010939,
	0x01093f, 0x01093f,
	0x010980, 0x0109b7,
	0x0109bc, 0x0109cf,
	0x0109d2, 0x010a06,
	0x010a0c, 0x010a33,
	0x010a38, 0x010a3a,
	0x010a3f, 0x010a47,
	0x010a50, 0x010a58,
	0x010a60, 0x010a9f,
	0x010ac0, 0x010ae6,
	0x010aeb, 0x010af6,
	0x010b00, 0x010b35,
	0x010b39, 0x010b55,
	0x010b58, 0x010b72,
	0x010b78, 0x010b91,
	0x010b99, 0x010b9c,
	0x010ba9, 0x010baf,
	0x010c00, 0x010c48,
	0x010c80, 0x010cb2,
	0x010cc0, 0x010cf2,
	0x010cfa, 0x010cff,
	0x010e60, 0x010e7e,
	0x011000, 0x01104d,
	0x011052, 0x01106f,
	0x01107f, 0x0110c1,
	0x0110d0, 0x0110e8,
	0x0110f0, 0x0110f9,
	0x011100, 0x011143,
	0x011150, 0x011176,
	0x011180, 0x0111cd,
	0x0111d0, 0x0111f4,
	0x011200, 0x01123e,
	0x011280, 0x0112a9,
	0x0112b0, 0x0112ea,
	0x0112f0, 0x0112f9,
	0x011300, 0x01130c,
	0x01130f, 0x011310,
	0x011313, 0x011339,
	0x01133c, 0x011344,
	0x011347, 0x011348,
	0x01134b, 0x01134d,
	0x011350, 0x011350,
	0x011357, 0x011357,
	0x01135d, 0x011363,
	0x011366, 0x01136c,
	0x011370, 0x011374,
	0x011400, 0x01145d,
	0x011480, 0x0114c7,
	0x0114d0, 0x0114d9,
	0x011580, 0x0115b5,
	0x0115b8, 0x0115dd,
	0x011600, 0x011644,
	0x011650, 0x011659,
	0x011660, 0x01166c,
	0x011680, 0x0116b7,
	0x0116c0, 0x0116c9,
	0x011700, 0x011719,
	0x01171d, 0x01172b,
	0x011730, 0x01173f,
	0x0118a0, 0x0118f2,
	0x0118ff, 0x0118ff,
	0x011a00, 0x011a47,
	0x011a50, 0x011a83,
	0x011a86, 0x011aa2,
	0x011ac0, 0x011af8,
	0x011c00, 0x011c45,
	0x011c50, 0x011c6c,
	0x011c70, 0x011c8f,
	0x011c92, 0x011cb6,
	0x011d00, 0x011d36,
	0x011d3a, 0x011d47,
	0x011d50, 0x011d59,
	0x012000, 0x012399,
	0x012400, 0x012474,
	0x012480, 0x012543,
	0x013000, 0x01342e,
	0x014400, 0x014646,
	0x016800, 0x016a38,
	0x016a40, 0x016a69,
	0x016a6e, 0x016a6f,
	0x016ad0, 0x016aed,
	0x016af0, 0x016af5,
	0x016b00, 0x016b45,
	0x016b50, 0x016b77,
	0x016b7d, 0x016b8f,
	0x016f00, 0x016f44,
	0x016f50, 0x016f7e,
	0x016f8f, 0x016f9f,
	0x016fe0, 0x016fe1,
	0x017000, 0x0187ec,
	0x018800, 0x018af2,
	0x01b000, 0x01b11e,
	0x01b170, 0x01b2fb,
	0x01bc00, 0x01bc6a,
	0x01bc70, 0x01bc7c,
	0x01bc80, 0x01bc88,
	0x01bc90, 0x01bc99,
	0x01bc9c, 0x01bc9f,
	0x01d000, 0x01d0f5,
	0x01d100, 0x01d126,
	0x01d129, 0x01d172,
	0x01d17b, 0x01d1e8,
	0x01d200, 0x01d245,
	0x01d300, 0x01d356,
	0x01d360, 0x01d371,
	0x01d400, 0x01d49f,
	0x01d4a2, 0x01d4a2,
	0x01d4a5, 0x01d4a6,
	0x01d4a9, 0x01d50a,
	0x01d50d, 0x01d546,
	0x01d54a, 0x01d6a5,
	0x01d6a8, 0x01d7cb,
	0x01d7ce, 0x01da8b,
	0x01da9b, 0x01daaf,
	0x01e000, 0x01e018,
	0x01e01b, 0x01e02a,
	0x01e800, 0x01e8c4,
	0x01e8c7, 0x01e8d6,
	0x01e900, 0x01e94a,
	0x01e950, 0x01e959,
	0x01e95e, 0x01e95f,
	0x01ee00, 0x01ee24,
	0x01ee27, 0x01ee3b,
	0x01ee42, 0x01ee42,
	0x01ee47, 0x01ee54,
	0x01ee57, 0x01ee64,
	0x01ee67, 0x01ee9b,
	0x01eea1, 0x01eebb,
	0x01eef0, 0x01eef1,
	0x01f000, 0x01f02b,
	0x01f030, 0x01f093,
	0x01f0a0, 0x01f0ae,
	0x01f0b1, 0x01f0f5,
	0x01f100, 0x01f10c,
	0x01f110, 0x01f16b,
	0x01f170, 0x01f1ac,
	0x01f1e6, 0x01f202,
	0x01f210, 0x01f23b,
	0x01f240, 0x01f248,
	0x01f250, 0x01f251,
	0x01f260, 0x01f265,
	0x01f300, 0x01f6d4,
	0x01f6e0, 0x01f6ec,
	0x01f6f0, 0x01f6f8,
	0x01f700, 0x01f773,
	0x01f780, 0x01f7d4,
	0x01f800, 0x01f80b,
	0x01f810, 0x01f847,
	0x01f850, 0x01f859,
	0x01f860, 0x01f887,
	0x01f890, 0x01f8ad,
	0x01f900, 0x01f90b,
	0x01f910, 0x01f94c,
	0x01f950, 0x01f96b,
	0x01f980, 0x01f997,
	0x01f9c0, 0x01f9c0,
	0x01f9d0, 0x01f9e6,
	0x020000, 0x02a6d6,
	0x02a700, 0x02b734,
	0x02b740, 0x02b81d,
	0x02b820, 0x02cea1,
	0x02ceb0, 0x02ebe0,
	0x02f800, 0x02fa1d,
	0x0e0100, 0x0e01ef,
}

var isNotPrint32 = []uint16{ // add 0x10000 to each entry
	0x000c,
	0x0027,
	0x003b,
	0x003e,
	0x018f,
	0x039e,
	0x0809,
	0x0836,
	0x0856,
	0x08f3,
	0x0a04,
	0x0a14,
	0x0a18,
	0x10bd,
	0x1135,
	0x11e0,
	0x1212,
	0x1287,
	0x1289,
	0x128e,
	0x129e,
	0x1304,
	0x1329,
	0x1331,
	0x1334,
	0x145a,
	0x145c,
	0x1a9d,
	0x1c09,
	0x1c37,
	0x1ca8,
	0x1d07,
	0x1d0a,
	0x1d3b,
	0x1d3e,
	0x246f,
	0x6a5f,
	0x6b5a,
	0x6b62,
	0xd455,
	0xd49d,
	0xd4ad,
	0xd4ba,
	0xd4bc,
	0xd4c4,
	0xd506,
	0xd515,
	0xd51d,
	0xd53a,
	0xd53f,
	0xd545,
	0xd551,
	0xdaa0,
	0xe007,
	0xe022,
	0xe025,
	0xee04,
	0xee20,
	0xee23,
	0xee28,
	0xee33,
	0xee38,
	0xee3a,
	0xee48,
	0xee4a,
	0xee4c,
	0xee50,
	0xee53,
	0xee58,
	0xee5a,
	0xee5c,
	0xee5e,
	0xee60,
	0xee63,
	0xee6b,
	0xee73,
	0xee78,
	0xee7d,
	0xee7f,
	0xee8a,
	0xeea4,
	0xeeaa,
	0xf0c0,
	0xf0d0,
	0xf12f,
	0xf93f,
}

// isGraphic lists the graphic runes not matched by IsPrint.
var isGraphic = []uint16{
	0x00a0,
	0x1680,
	0x2000,
	0x2001,
	0x2002,
	0x2003,
	0x2004,
	0x2005,
	0x2006,
	0x2007,
	0x2008,
	0x2009,
	0x200a,
	0x202f,
	0x205f,
	0x3000,
}
