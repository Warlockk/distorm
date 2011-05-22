/*
mnemonics.h

diStorm3 - Powerful disassembler for X86/AMD64
http://ragestorm.net/distorm/
distorm at gmail dot com
Copyright (C) 2010  Gil Dabah

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/


#ifndef MNEMONICS_H
#define MNEMONICS_H

#ifdef __cplusplus
 extern "C" {
#endif

typedef struct WMnemonic {
	unsigned char length;
	unsigned char p[1]; /* p is a null terminated string, which contains 'length' characters. */
} _WMnemonic;

typedef struct WRegister {
	unsigned int length;
	unsigned char p[6]; /* p is a null terminated string. */
} _WRegister;

extern const unsigned char _MNEMONICS[];
extern const _WRegister _REGISTERS[];

#ifdef __cplusplus
} /* End Of Extern */
#endif

#define GET_REGISTER_NAME(r) (unsigned char*)_REGISTERS[(r)].p
#define GET_MNEMONIC_NAME(m) ((_WMnemonic*)&_MNEMONICS[(m)])->p

typedef enum {
	I_UNDEFINED = 0, I_AAA = 66, I_AAD = 389, I_AAM = 384, I_AAS = 76, I_ADC = 31, I_ADD = 11, I_ADDPD = 4923,
	I_ADDPS = 4916, I_ADDSD = 4937, I_ADDSS = 4930, I_ADDSUBPD = 7090, I_ADDSUBPS = 7100,
	I_AESDEC = 3989, I_AESDECLAST = 4006, I_AESENC = 3947, I_AESENCLAST = 3964,
	I_AESIMC = 3930, I_AESKEYGENASSIST = 4583, I_AND = 41, I_ANDNPD = 4834, I_ANDNPS = 4826,
	I_ANDPD = 4803, I_ANDPS = 4796, I_ARPL = 111, I_BLENDPD = 4152, I_BLENDPS = 4133,
	I_BLENDVPD = 2408, I_BLENDVPS = 2398, I_BOUND = 104, I_BSF = 939, I_BSR = 6306,
	I_BSWAP = 965, I_BT = 872, I_BTC = 934, I_BTR = 912, I_BTS = 887, I_CALL = 456,
	I_CALL_FAR = 260, I_CBW = 228, I_CDQ = 250, I_CDQE = 239, I_CLC = 492, I_CLD = 512,
	I_CLFLUSH = 6251, I_CLGI = 1156, I_CLI = 502, I_CLTS = 541, I_CMC = 487, I_CMOVA = 694,
	I_CMOVAE = 663, I_CMOVB = 656, I_CMOVBE = 686, I_CMOVG = 754, I_CMOVGE = 738,
	I_CMOVL = 731, I_CMOVLE = 746, I_CMOVNO = 648, I_CMOVNP = 723, I_CMOVNS = 708,
	I_CMOVNZ = 678, I_CMOVO = 641, I_CMOVP = 716, I_CMOVS = 701, I_CMOVZ = 671,
	I_CMP = 71, I_CMPEQPD = 6397, I_CMPEQPS = 6318, I_CMPEQSD = 6555, I_CMPEQSS = 6476,
	I_CMPLEPD = 6415, I_CMPLEPS = 6336, I_CMPLESD = 6573, I_CMPLESS = 6494, I_CMPLTPD = 6406,
	I_CMPLTPS = 6327, I_CMPLTSD = 6564, I_CMPLTSS = 6485, I_CMPNEQPD = 6436, I_CMPNEQPS = 6357,
	I_CMPNEQSD = 6594, I_CMPNEQSS = 6515, I_CMPNLEPD = 6456, I_CMPNLEPS = 6377,
	I_CMPNLESD = 6614, I_CMPNLESS = 6535, I_CMPNLTPD = 6446, I_CMPNLTPS = 6367,
	I_CMPNLTSD = 6604, I_CMPNLTSS = 6525, I_CMPORDPD = 6466, I_CMPORDPS = 6387,
	I_CMPORDSD = 6624, I_CMPORDSS = 6545, I_CMPS = 301, I_CMPUNORDPD = 6424, I_CMPUNORDPS = 6345,
	I_CMPUNORDSD = 6582, I_CMPUNORDSS = 6503, I_CMPXCHG = 898, I_CMPXCHG16B = 7044,
	I_CMPXCHG8B = 7033, I_COMISD = 2102, I_COMISS = 2094, I_CPUID = 865, I_CQO = 255,
	I_CRC32 = 4038, I_CVTDQ2PD = 7408, I_CVTDQ2PS = 5120, I_CVTPD2DQ = 7418, I_CVTPD2PI = 2004,
	I_CVTPD2PS = 5046, I_CVTPI2PD = 1818, I_CVTPI2PS = 1808, I_CVTPS2DQ = 5130,
	I_CVTPS2PD = 5036, I_CVTPS2PI = 1994, I_CVTSD2SI = 2024, I_CVTSD2SS = 5066,
	I_CVTSI2SD = 1838, I_CVTSI2SS = 1828, I_CVTSS2SD = 5056, I_CVTSS2SI = 2014,
	I_CVTTPD2DQ = 7397, I_CVTTPD2PI = 1937, I_CVTTPS2DQ = 5140, I_CVTTPS2PI = 1926,
	I_CVTTSD2SI = 1959, I_CVTTSS2SI = 1948, I_CWD = 245, I_CWDE = 233, I_DAA = 46,
	I_DAS = 56, I_DEC = 86, I_DIV = 8580, I_DIVPD = 5312, I_DIVPS = 5305, I_DIVSD = 5326,
	I_DIVSS = 5319, I_DPPD = 4404, I_DPPS = 4391, I_EMMS = 6067, I_ENTER = 340,
	I_EXTRACTPS = 4269, I_EXTRQ = 6103, I_F2XM1 = 8034, I_FABS = 7965, I_FADD = 7865,
	I_FADDP = 8483, I_FBLD = 8535, I_FBSTP = 8541, I_FCHS = 7959, I_FCLEX = 8401,
	I_FCMOVB = 8250, I_FCMOVBE = 8266, I_FCMOVE = 8258, I_FCMOVNB = 8319, I_FCMOVNBE = 8337,
	I_FCMOVNE = 8328, I_FCMOVNU = 8347, I_FCMOVU = 8275, I_FCOM = 7877, I_FCOMI = 8386,
	I_FCOMIP = 8557, I_FCOMP = 7883, I_FCOMPP = 8497, I_FCOS = 8153, I_FDECSTP = 8080,
	I_FDIV = 7903, I_FDIVP = 8528, I_FDIVR = 7909, I_FDIVRP = 8520, I_FEDISI = 8362,
	I_FEMMS = 574, I_FENI = 8356, I_FFREE = 8431, I_FIADD = 8191, I_FICOM = 8205,
	I_FICOMP = 8212, I_FIDIV = 8235, I_FIDIVR = 8242, I_FILD = 8292, I_FIMUL = 8198,
	I_FINCSTP = 8089, I_FINIT = 8416, I_FIST = 8306, I_FISTP = 8312, I_FISTTP = 8298,
	I_FISUB = 8220, I_FISUBR = 8227, I_FLD = 7916, I_FLD1 = 7983, I_FLDCW = 7940,
	I_FLDENV = 7932, I_FLDL2E = 7997, I_FLDL2T = 7989, I_FLDLG2 = 8012, I_FLDLN2 = 8020,
	I_FLDPI = 8005, I_FLDZ = 8028, I_FMUL = 7871, I_FMULP = 8490, I_FNCLEX = 8393,
	I_FNINIT = 8408, I_FNOP = 7953, I_FNSAVE = 8453, I_FNSTCW = 8176, I_FNSTENV = 8159,
	I_FNSTSW = 8468, I_FPATAN = 8055, I_FPREM = 8098, I_FPREM1 = 8072, I_FPTAN = 8048,
	I_FRNDINT = 8130, I_FRSTOR = 8423, I_FSAVE = 8461, I_FSCALE = 8139, I_FSETPM = 8370,
	I_FSIN = 8147, I_FSINCOS = 8121, I_FSQRT = 8114, I_FST = 7921, I_FSTCW = 8184,
	I_FSTENV = 8168, I_FSTP = 7926, I_FSTSW = 8476, I_FSUB = 7890, I_FSUBP = 8513,
	I_FSUBR = 7896, I_FSUBRP = 8505, I_FTST = 7971, I_FUCOM = 8438, I_FUCOMI = 8378,
	I_FUCOMIP = 8548, I_FUCOMP = 8445, I_FUCOMPP = 8283, I_FXAM = 7977, I_FXCH = 7947,
	I_FXRSTOR = 6204, I_FXSAVE = 6196, I_FXTRACT = 8063, I_FYL2X = 8041, I_FYL2XP1 = 8105,
	I_GETSEC = 633, I_HADDPD = 6128, I_HADDPS = 6136, I_HLT = 482, I_HSUBPD = 6162,
	I_HSUBPS = 6170, I_IDIV = 8585, I_IMUL = 117, I_IN = 447, I_INC = 81, I_INS = 123,
	I_INSERTPS = 4336, I_INSERTQ = 6110, I_INT = 367, I_INT_3 = 360, I_INT1 = 476,
	I_INTO = 372, I_INVD = 555, I_INVEPT = 3073, I_INVLPG = 1042, I_INVLPGA = 1170,
	I_INVVPID = 3081, I_IRET = 378, I_JA = 166, I_JAE = 147, I_JB = 143, I_JBE = 161,
	I_JCXZ = 427, I_JECXZ = 433, I_JG = 202, I_JGE = 192, I_JL = 188, I_JLE = 197,
	I_JMP = 462, I_JMP_FAR = 467, I_JNO = 138, I_JNP = 183, I_JNS = 174, I_JNZ = 156,
	I_JO = 134, I_JP = 179, I_JRCXZ = 440, I_JS = 170, I_JZ = 152, I_LAHF = 289,
	I_LAR = 522, I_LDDQU = 7615, I_LDMXCSR = 6260, I_LDS = 335, I_LEA = 223, I_LEAVE = 347,
	I_LES = 330, I_LFENCE = 6219, I_LFS = 917, I_LGDT = 1018, I_LGS = 922, I_LIDT = 1024,
	I_LLDT = 983, I_LMSW = 1036, I_LODS = 313, I_LOOP = 421, I_LOOPNZ = 406, I_LOOPZ = 414,
	I_LSL = 527, I_LSS = 907, I_LTR = 989, I_LZCNT = 6311, I_MASKMOVDQU = 7695,
	I_MASKMOVQ = 7685, I_MAXPD = 5372, I_MAXPS = 5365, I_MAXSD = 5386, I_MAXSS = 5379,
	I_MFENCE = 6235, I_MINPD = 5252, I_MINPS = 5245, I_MINSD = 5266, I_MINSS = 5259,
	I_MONITOR = 1086, I_MOV = 218, I_MOVAPD = 1782, I_MOVAPS = 1774, I_MOVBE = 4031,
	I_MOVD = 5733, I_MOVDDUP = 1509, I_MOVDQ2Q = 7173, I_MOVDQA = 5759, I_MOVDQU = 5767,
	I_MOVHLPS = 1474, I_MOVHPD = 1668, I_MOVHPS = 1660, I_MOVLHPS = 1651, I_MOVLPD = 1491,
	I_MOVLPS = 1483, I_MOVMSKPD = 4628, I_MOVMSKPS = 4618, I_MOVNTDQ = 7470, I_MOVNTDQA = 2684,
	I_MOVNTI = 957, I_MOVNTPD = 1879, I_MOVNTPS = 1870, I_MOVNTQ = 7462, I_MOVNTSD = 1897,
	I_MOVNTSS = 1888, I_MOVQ = 5739, I_MOVQ2DQ = 7164, I_MOVS = 295, I_MOVSD = 1433,
	I_MOVSHDUP = 1676, I_MOVSLDUP = 1499, I_MOVSS = 1426, I_MOVSX = 944, I_MOVSXD = 8597,
	I_MOVUPD = 1418, I_MOVUPS = 1410, I_MOVZX = 927, I_MPSADBW = 4417, I_MUL = 8575,
	I_MULPD = 4983, I_MULPS = 4976, I_MULSD = 4997, I_MULSS = 4990, I_MWAIT = 1095,
	I_NEG = 8570, I_NOP = 581, I_NOT = 8565, I_OR = 27, I_ORPD = 4866, I_ORPS = 4860,
	I_OUT = 451, I_OUTS = 128, I_PABSB = 2477, I_PABSD = 2507, I_PABSW = 2492,
	I_PACKSSDW = 5662, I_PACKSSWB = 5494, I_PACKUSDW = 2705, I_PACKUSWB = 5572,
	I_PADDB = 7780, I_PADDD = 7810, I_PADDQ = 7132, I_PADDSB = 7551, I_PADDSW = 7568,
	I_PADDUSB = 7271, I_PADDUSW = 7290, I_PADDW = 7795, I_PALIGNR = 4191, I_PAND = 7258,
	I_PANDN = 7316, I_PAUSE = 8605, I_PAVGB = 7331, I_PAVGUSB = 1401, I_PAVGW = 7346,
	I_PBLENDVB = 2388, I_PBLENDW = 4171, I_PCLMULQDQ = 4436, I_PCMPEQB = 6010,
	I_PCMPEQD = 6048, I_PCMPEQQ = 2665, I_PCMPEQW = 6029, I_PCMPESTRI = 4515,
	I_PCMPESTRM = 4492, I_PCMPGTB = 5515, I_PCMPGTD = 5553, I_PCMPGTQ = 2876,
	I_PCMPGTW = 5534, I_PCMPISTRI = 4560, I_PCMPISTRM = 4537, I_PEXTRB = 4210,
	I_PEXTRD = 4244, I_PEXTRQ = 4252, I_PEXTRW = 4227, I_PF2ID = 1237, I_PF2IW = 1230,
	I_PFACC = 1351, I_PFADD = 1300, I_PFCMPEQ = 1358, I_PFCMPGE = 1261, I_PFCMPGT = 1307,
	I_PFMAX = 1316, I_PFMIN = 1270, I_PFMUL = 1367, I_PFNACC = 1244, I_PFPNACC = 1252,
	I_PFRCP = 1277, I_PFRCPIT1 = 1323, I_PFRCPIT2 = 1374, I_PFRSQIT1 = 1333, I_PFRSQRT = 1284,
	I_PFSUB = 1293, I_PFSUBR = 1343, I_PHADDD = 2162, I_PHADDSW = 2179, I_PHADDW = 2145,
	I_PHMINPOSUW = 3048, I_PHSUBD = 2238, I_PHSUBSW = 2255, I_PHSUBW = 2221, I_PI2FD = 1223,
	I_PI2FW = 1216, I_PINSRB = 4319, I_PINSRD = 4357, I_PINSRQ = 4365, I_PINSRW = 6982,
	I_PMADDUBSW = 2198, I_PMADDWD = 7649, I_PMAXSB = 2963, I_PMAXSD = 2980, I_PMAXSW = 7585,
	I_PMAXUB = 7299, I_PMAXUD = 3014, I_PMAXUW = 2997, I_PMINSB = 2895, I_PMINSD = 2912,
	I_PMINSW = 7523, I_PMINUB = 7241, I_PMINUD = 2946, I_PMINUW = 2929, I_PMOVMSKB = 7182,
	I_PMOVSXBD = 2543, I_PMOVSXBQ = 2564, I_PMOVSXBW = 2522, I_PMOVSXDQ = 2627,
	I_PMOVSXWD = 2585, I_PMOVSXWQ = 2606, I_PMOVZXBD = 2771, I_PMOVZXBQ = 2792,
	I_PMOVZXBW = 2750, I_PMOVZXDQ = 2855, I_PMOVZXWD = 2813, I_PMOVZXWQ = 2834,
	I_PMULDQ = 2648, I_PMULHRSW = 2325, I_PMULHRW = 1384, I_PMULHUW = 7361, I_PMULHW = 7380,
	I_PMULLD = 3031, I_PMULLW = 7147, I_PMULUDQ = 7630, I_POP = 22, I_POPA = 98,
	I_POPCNT = 6298, I_POPF = 277, I_POR = 7540, I_PREFETCH = 1195, I_PREFETCHNTA = 1725,
	I_PREFETCHT0 = 1738, I_PREFETCHT1 = 1750, I_PREFETCHT2 = 1762, I_PREFETCHW = 1205,
	I_PSADBW = 7668, I_PSHUFB = 2128, I_PSHUFD = 5801, I_PSHUFHW = 5809, I_PSHUFLW = 5818,
	I_PSHUFW = 5793, I_PSIGNB = 2274, I_PSIGND = 2308, I_PSIGNW = 2291, I_PSLLD = 5931,
	I_PSLLDQ = 5993, I_PSLLQ = 5978, I_PSLLW = 5886, I_PSRAD = 5916, I_PSRAW = 5871,
	I_PSRLD = 5901, I_PSRLDQ = 5961, I_PSRLQ = 5946, I_PSRLW = 5856, I_PSUBB = 7720,
	I_PSUBD = 7750, I_PSUBQ = 7765, I_PSUBSB = 7489, I_PSUBSW = 7506, I_PSUBUSB = 7203,
	I_PSUBUSW = 7222, I_PSUBW = 7735, I_PSWAPD = 1393, I_PTEST = 2418, I_PUNPCKHBW = 5593,
	I_PUNPCKHDQ = 5639, I_PUNPCKHQDQ = 5708, I_PUNPCKHWD = 5616, I_PUNPCKLBW = 5425,
	I_PUNPCKLDQ = 5471, I_PUNPCKLQDQ = 5683, I_PUNPCKLWD = 5448, I_PUSH = 16,
	I_PUSHA = 91, I_PUSHF = 270, I_PXOR = 7602, I_RCL = 7835, I_RCPPS = 4766, I_RCPSS = 4773,
	I_RCR = 7840, I_RDMSR = 600, I_RDPMC = 607, I_RDTSC = 593, I_RDTSCP = 1187,
	I_RET = 325, I_RETF = 354, I_ROL = 7825, I_ROR = 7830, I_ROUNDPD = 4076, I_ROUNDPS = 4057,
	I_ROUNDSD = 4114, I_ROUNDSS = 4095, I_RSM = 882, I_RSQRTPS = 4728, I_RSQRTSS = 4737,
	I_SAHF = 283, I_SAL = 7855, I_SALC = 394, I_SAR = 7860, I_SBB = 36, I_SCAS = 319,
	I_SETA = 807, I_SETAE = 780, I_SETB = 774, I_SETBE = 800, I_SETG = 859, I_SETGE = 845,
	I_SETL = 839, I_SETLE = 852, I_SETNO = 767, I_SETNP = 832, I_SETNS = 819, I_SETNZ = 793,
	I_SETO = 761, I_SETP = 826, I_SETS = 813, I_SETZ = 787, I_SFENCE = 6243, I_SGDT = 1006,
	I_SHL = 7845, I_SHLD = 876, I_SHR = 7850, I_SHRD = 892, I_SHUFPD = 7007, I_SHUFPS = 6999,
	I_SIDT = 1012, I_SKINIT = 1162, I_SLDT = 972, I_SMSW = 1030, I_SQRTPD = 4668,
	I_SQRTPS = 4660, I_SQRTSD = 4684, I_SQRTSS = 4676, I_STC = 497, I_STD = 517,
	I_STGI = 1150, I_STI = 507, I_STMXCSR = 6279, I_STOS = 307, I_STR = 978, I_SUB = 51,
	I_SUBPD = 5192, I_SUBPS = 5185, I_SUBSD = 5206, I_SUBSS = 5199, I_SWAPGS = 1179,
	I_SYSCALL = 532, I_SYSENTER = 614, I_SYSEXIT = 624, I_SYSRET = 547, I_TEST = 206,
	I_UCOMISD = 2065, I_UCOMISS = 2056, I_UD2 = 569, I_UNPCKHPD = 1619, I_UNPCKHPS = 1609,
	I_UNPCKLPD = 1577, I_UNPCKLPS = 1567, I_VADDPD = 4952, I_VADDPS = 4944, I_VADDSD = 4968,
	I_VADDSS = 4960, I_VADDSUBPD = 7110, I_VADDSUBPS = 7121, I_VAESDEC = 3997,
	I_VAESDECLAST = 4018, I_VAESENC = 3955, I_VAESENCLAST = 3976, I_VAESIMC = 3938,
	I_VAESKEYGENASSIST = 4600, I_VANDNPD = 4851, I_VANDNPS = 4842, I_VANDPD = 4818,
	I_VANDPS = 4810, I_VBLENDPD = 4161, I_VBLENDPS = 4142, I_VBLENDVPD = 4470,
	I_VBLENDVPS = 4459, I_VBROADCASTF128 = 2461, I_VBROADCASTSD = 2447, I_VBROADCASTSS = 2433,
	I_VCMPEQPD = 6721, I_VCMPEQPS = 6634, I_VCMPEQSD = 6895, I_VCMPEQSS = 6808,
	I_VCMPESTRI = 4526, I_VCMPLEPD = 6741, I_VCMPLEPS = 6654, I_VCMPLESD = 6915,
	I_VCMPLESS = 6828, I_VCMPLTPD = 6731, I_VCMPLTPS = 6644, I_VCMPLTSD = 6905,
	I_VCMPLTSS = 6818, I_VCMPNEQPD = 6764, I_VCMPNEQPS = 6677, I_VCMPNEQSD = 6938,
	I_VCMPNEQSS = 6851, I_VCMPNLEPD = 6786, I_VCMPNLEPS = 6699, I_VCMPNLESD = 6960,
	I_VCMPNLESS = 6873, I_VCMPNLTPD = 6775, I_VCMPNLTPS = 6688, I_VCMPNLTSD = 6949,
	I_VCMPNLTSS = 6862, I_VCMPORDPD = 6797, I_VCMPORDPS = 6710, I_VCMPORDSD = 6971,
	I_VCMPORDSS = 6884, I_VCMPUNORDPD = 6751, I_VCMPUNORDPS = 6664, I_VCMPUNORDSD = 6925,
	I_VCMPUNORDSS = 6838, I_VCOMISD = 2119, I_VCOMISS = 2110, I_VCVTDQ2PD = 7440,
	I_VCVTDQ2PS = 5151, I_VCVTPD2DQ = 7451, I_VCVTPD2PS = 5109, I_VCVTPS2DQ = 5162,
	I_VCVTPS2PD = 5098, I_VCVTSD2SI = 2045, I_VCVTSD2SS = 5087, I_VCVTSI2SD = 1859,
	I_VCVTSI2SS = 1848, I_VCVTSS2SD = 5076, I_VCVTSS2SI = 2034, I_VCVTTPD2DQ = 7428,
	I_VCVTTPS2DQ = 5173, I_VCVTTSD2SI = 1982, I_VCVTTSS2SI = 1970, I_VDIVPD = 5341,
	I_VDIVPS = 5333, I_VDIVSD = 5357, I_VDIVSS = 5349, I_VDPPD = 4410, I_VDPPS = 4397,
	I_VERR = 994, I_VERW = 1000, I_VEXTRACTF128 = 4305, I_VEXTRACTPS = 4280, I_VFMADD132PD = 3167,
	I_VFMADD132PS = 3154, I_VFMADD132SD = 3193, I_VFMADD132SS = 3180, I_VFMADD213PD = 3447,
	I_VFMADD213PS = 3434, I_VFMADD213SD = 3473, I_VFMADD213SS = 3460, I_VFMADD231PD = 3727,
	I_VFMADD231PS = 3714, I_VFMADD231SD = 3753, I_VFMADD231SS = 3740, I_VFMADDSUB132PD = 3106,
	I_VFMADDSUB132PS = 3090, I_VFMADDSUB213PD = 3386, I_VFMADDSUB213PS = 3370,
	I_VFMADDSUB231PD = 3666, I_VFMADDSUB231PS = 3650, I_VFMSUB132PD = 3219, I_VFMSUB132PS = 3206,
	I_VFMSUB132SD = 3245, I_VFMSUB132SS = 3232, I_VFMSUB213PD = 3499, I_VFMSUB213PS = 3486,
	I_VFMSUB213SD = 3525, I_VFMSUB213SS = 3512, I_VFMSUB231PD = 3779, I_VFMSUB231PS = 3766,
	I_VFMSUB231SD = 3805, I_VFMSUB231SS = 3792, I_VFMSUBADD132PD = 3138, I_VFMSUBADD132PS = 3122,
	I_VFMSUBADD213PD = 3418, I_VFMSUBADD213PS = 3402, I_VFMSUBADD231PD = 3698,
	I_VFMSUBADD231PS = 3682, I_VFNMADD132PD = 3272, I_VFNMADD132PS = 3258, I_VFNMADD132SD = 3300,
	I_VFNMADD132SS = 3286, I_VFNMADD213PD = 3552, I_VFNMADD213PS = 3538, I_VFNMADD213SD = 3580,
	I_VFNMADD213SS = 3566, I_VFNMADD231PD = 3832, I_VFNMADD231PS = 3818, I_VFNMADD231SD = 3860,
	I_VFNMADD231SS = 3846, I_VFNMSUB132PD = 3328, I_VFNMSUB132PS = 3314, I_VFNMSUB132SD = 3356,
	I_VFNMSUB132SS = 3342, I_VFNMSUB213PD = 3608, I_VFNMSUB213PS = 3594, I_VFNMSUB213SD = 3636,
	I_VFNMSUB213SS = 3622, I_VFNMSUB231PD = 3888, I_VFNMSUB231PS = 3874, I_VFNMSUB231SD = 3916,
	I_VFNMSUB231SS = 3902, I_VHADDPD = 6144, I_VHADDPS = 6153, I_VHSUBPD = 6178,
	I_VHSUBPS = 6187, I_VINSERTF128 = 4292, I_VINSERTPS = 4346, I_VLDDQU = 7622,
	I_VLDMXCSR = 6269, I_VMASKMOVDQU = 7707, I_VMASKMOVPD = 2738, I_VMASKMOVPS = 2726,
	I_VMAXPD = 5401, I_VMAXPS = 5393, I_VMAXSD = 5417, I_VMAXSS = 5409, I_VMCALL = 1050,
	I_VMCLEAR = 7074, I_VMINPD = 5281, I_VMINPS = 5273, I_VMINSD = 5297, I_VMINSS = 5289,
	I_VMLAUNCH = 1058, I_VMLOAD = 1134, I_VMMCALL = 1125, I_VMOVAPD = 1799, I_VMOVAPS = 1790,
	I_VMOVD = 5745, I_VMOVDDUP = 1557, I_VMOVDQA = 5775, I_VMOVDQU = 5784, I_VMOVHLPS = 1518,
	I_VMOVHPD = 1705, I_VMOVHPS = 1696, I_VMOVLHPS = 1686, I_VMOVLPD = 1537, I_VMOVLPS = 1528,
	I_VMOVMSKPD = 4649, I_VMOVMSKPS = 4638, I_VMOVNTDQ = 7479, I_VMOVNTDQA = 2694,
	I_VMOVNTPD = 1916, I_VMOVNTPS = 1906, I_VMOVQ = 5752, I_VMOVSD = 1448, I_VMOVSHDUP = 1714,
	I_VMOVSLDUP = 1546, I_VMOVSS = 1440, I_VMOVUPD = 1465, I_VMOVUPS = 1456, I_VMPSADBW = 4426,
	I_VMPTRLD = 7065, I_VMPTRST = 7056, I_VMREAD = 6095, I_VMRESUME = 1068, I_VMRUN = 1118,
	I_VMSAVE = 1142, I_VMULPD = 5012, I_VMULPS = 5004, I_VMULSD = 5028, I_VMULSS = 5020,
	I_VMWRITE = 6119, I_VMXOFF = 1078, I_VMXON = 7083, I_VORPD = 4879, I_VORPS = 4872,
	I_VPABSB = 2484, I_VPABSD = 2514, I_VPABSW = 2499, I_VPACKSSDW = 5672, I_VPACKSSWB = 5504,
	I_VPACKUSDW = 2715, I_VPACKUSWB = 5582, I_VPADDB = 7787, I_VPADDD = 7817,
	I_VPADDQ = 7139, I_VPADDSB = 7559, I_VPADDSW = 7576, I_VPADDUSW = 7280, I_VPADDW = 7802,
	I_VPALIGNR = 4200, I_VPAND = 7264, I_VPANDN = 7323, I_VPAVGB = 7338, I_VPAVGW = 7353,
	I_VPBLENDVB = 4481, I_VPBLENDVW = 4180, I_VPCLMULQDQ = 4447, I_VPCMPEQB = 6019,
	I_VPCMPEQD = 6057, I_VPCMPEQQ = 2674, I_VPCMPEQW = 6038, I_VPCMPESTRM = 4503,
	I_VPCMPGTB = 5524, I_VPCMPGTD = 5562, I_VPCMPGTQ = 2885, I_VPCMPGTW = 5543,
	I_VPCMPISTRI = 4571, I_VPCMPISTRM = 4548, I_VPERM2F128 = 4045, I_VPERMILPD = 2357,
	I_VPERMILPS = 2346, I_VPEXTRB = 4218, I_VPEXTRD = 4260, I_VPEXTRW = 4235,
	I_VPHADDD = 2170, I_VPHADDSW = 2188, I_VPHADDW = 2153, I_VPHMINPOSUW = 3060,
	I_VPHSUBD = 2246, I_VPHSUBSW = 2264, I_VPHSUBW = 2229, I_VPINSRB = 4327, I_VPINSRD = 4373,
	I_VPINSRQ = 4382, I_VPINSRW = 6990, I_VPMADDUBSW = 2209, I_VPMADDWD = 7658,
	I_VPMAXSB = 2971, I_VPMAXSD = 2988, I_VPMAXSW = 7593, I_VPMAXUB = 7307, I_VPMAXUD = 3022,
	I_VPMAXUW = 3005, I_VPMINSB = 2903, I_VPMINSD = 2920, I_VPMINSW = 7531, I_VPMINUB = 7249,
	I_VPMINUD = 2954, I_VPMINUW = 2937, I_VPMOVMSKB = 7192, I_VPMOVSXBD = 2553,
	I_VPMOVSXBQ = 2574, I_VPMOVSXBW = 2532, I_VPMOVSXDQ = 2637, I_VPMOVSXWD = 2595,
	I_VPMOVSXWQ = 2616, I_VPMOVZXBD = 2781, I_VPMOVZXBQ = 2802, I_VPMOVZXBW = 2760,
	I_VPMOVZXDQ = 2865, I_VPMOVZXWD = 2823, I_VPMOVZXWQ = 2844, I_VPMULDQ = 2656,
	I_VPMULHRSW = 2335, I_VPMULHUW = 7370, I_VPMULHW = 7388, I_VPMULLD = 3039,
	I_VPMULLW = 7155, I_VPMULUDQ = 7639, I_VPOR = 7545, I_VPSADBW = 7676, I_VPSHUFB = 2136,
	I_VPSHUFD = 5827, I_VPSHUFHW = 5836, I_VPSHUFLW = 5846, I_VPSIGNB = 2282,
	I_VPSIGND = 2316, I_VPSIGNW = 2299, I_VPSLLD = 5938, I_VPSLLDQ = 6001, I_VPSLLQ = 5985,
	I_VPSLLW = 5893, I_VPSRAD = 5923, I_VPSRAW = 5878, I_VPSRLD = 5908, I_VPSRLDQ = 5969,
	I_VPSRLQ = 5953, I_VPSRLW = 5863, I_VPSUBB = 7727, I_VPSUBD = 7757, I_VPSUBQ = 7772,
	I_VPSUBSB = 7497, I_VPSUBSW = 7514, I_VPSUBUSB = 7212, I_VPSUBUSW = 7231,
	I_VPSUBW = 7742, I_VPTEST = 2425, I_VPTESTPD = 2378, I_VPTESTPS = 2368, I_VPUNPCKHBW = 5604,
	I_VPUNPCKHDQ = 5650, I_VPUNPCKHQDQ = 5720, I_VPUNPCKHWD = 5627, I_VPUNPCKLBW = 5436,
	I_VPUNPCKLDQ = 5482, I_VPUNPCKLQDQ = 5695, I_VPUNPCKLWD = 5459, I_VPXOR = 7608,
	I_VRCPPS = 4788, I_VRCPSS = 4780, I_VROUNDPD = 4085, I_VROUNDPS = 4066, I_VROUNDSD = 4123,
	I_VROUNDSS = 4104, I_VRSQRTPS = 4756, I_VRSQRTSS = 4746, I_VSHUFPD = 7024,
	I_VSHUFPS = 7015, I_VSQRTPD = 4719, I_VSQRTPS = 4710, I_VSQRTSD = 4701, I_VSQRTSS = 4692,
	I_VSTMXCSR = 6288, I_VSUBPD = 5221, I_VSUBPS = 5213, I_VSUBSD = 5237, I_VSUBSS = 5229,
	I_VUCOMISD = 2084, I_VUCOMISS = 2074, I_VUNPCKHPD = 1640, I_VUNPCKHPS = 1629,
	I_VUNPCKLPD = 1598, I_VUNPCKLPS = 1587, I_VXORPD = 4908, I_VXORPS = 4900,
	I_VZEROALL = 6085, I_VZEROUPPER = 6073, I_WAIT = 8591, I_WBINVD = 561, I_WRMSR = 586,
	I_XADD = 951, I_XAVE = 6213, I_XCHG = 212, I_XGETBV = 1102, I_XLAT = 400, I_XOR = 61,
	I_XORPD = 4893, I_XORPS = 4886, I_XRSTOR = 6227, I_XSETBV = 1110, 
} _InstructionType;

typedef enum {
	R_RAX, R_RCX, R_RDX, R_RBX, R_RSP, R_RBP, R_RSI, R_RDI, R_R8, R_R9, R_R10, R_R11, R_R12, R_R13, R_R14, R_R15,
	R_EAX, R_ECX, R_EDX, R_EBX, R_ESP, R_EBP, R_ESI, R_EDI, R_R8D, R_R9D, R_R10D, R_R11D, R_R12D, R_R13D, R_R14D, R_R15D,
	R_AX, R_CX, R_DX, R_BX, R_SP, R_BP, R_SI, R_DI, R_R8W, R_R9W, R_R10W, R_R11W, R_R12W, R_R13W, R_R14W, R_R15W,
	R_AL, R_CL, R_DL, R_BL, R_AH, R_CH, R_DH, R_BH, R_R8B, R_R9B, R_R10B, R_R11B, R_R12B, R_R13B, R_R14B, R_R15B,
	R_SPL, R_BPL, R_SIL, R_DIL,
	R_ES, R_CS, R_SS, R_DS, R_FS, R_GS,
	R_RIP,
	R_ST0, R_ST1, R_ST2, R_ST3, R_ST4, R_ST5, R_ST6, R_ST7,
	R_MM0, R_MM1, R_MM2, R_MM3, R_MM4, R_MM5, R_MM6, R_MM7,
	R_XMM0, R_XMM1, R_XMM2, R_XMM3, R_XMM4, R_XMM5, R_XMM6, R_XMM7, R_XMM8, R_XMM9, R_XMM10, R_XMM11, R_XMM12, R_XMM13, R_XMM14, R_XMM15,
	R_YMM0, R_YMM1, R_YMM2, R_YMM3, R_YMM4, R_YMM5, R_YMM6, R_YMM7, R_YMM8, R_YMM9, R_YMM10, R_YMM11, R_YMM12, R_YMM13, R_YMM14, R_YMM15,
	R_CR0, R_UNUSED0, R_CR2, R_CR3, R_CR4, R_UNUSED1, R_UNUSED2, R_UNUSED3, R_CR8,
	R_DR0, R_DR1, R_DR2, R_DR3, R_UNUSED4, R_UNUSED5, R_DR6, R_DR7
} _RegisterType;

#endif /* MNEMONICS_H */
