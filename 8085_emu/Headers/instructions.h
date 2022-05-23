#pragma once

#include <cstdint>


struct Instruction
{
    uint8_t OPCODE;
    char OPERAND[16];
    uint8_t bytes;
    int(*ACTION)(int bytes);
};

int ACIData(int bytes);
int ADCA(int bytes);
int ADCB(int bytes);
int ADCC(int bytes);
int ADCD(int bytes);
int ADCE(int bytes);
int ADCH(int bytes);
int ADCL(int bytes);
int ADCM(int bytes);
int ADDA(int bytes);
int ADDB(int bytes);
int ADDC(int bytes);
int ADDD(int bytes);
int ADDE(int bytes);
int ADDH(int bytes);
int ADDL(int bytes);
int ADDM(int bytes);
int ADIData(int bytes);
int ANAA(int bytes);
int ANAB(int bytes);
int ANAC(int bytes);
int ANAD(int bytes);
int ANAE(int bytes);
int ANAH(int bytes);
int ANAL(int bytes);
int ANAM(int bytes);
int ANIData(int bytes);
int CALLLabel(int bytes);
int CCLabel(int bytes);
int CMLabel(int bytes);
int CMA(int bytes);
int CMC(int bytes);
int CMPA(int bytes);
int CMPB(int bytes);
int CMPC(int bytes);
int CMPD(int bytes);
int CMPE(int bytes);
int CMPH(int bytes);
int CMPL(int bytes);
int CMPM(int bytes);
int CNCLabel(int bytes);
int CNZLabel(int bytes);
int CPLabel(int bytes);
int CPELabel(int bytes);
int CPIData(int bytes);
int CPOLabel(int bytes);
int CZLabel(int bytes);
int DAA(int bytes);
int DADB(int bytes);
int DADD(int bytes);
int DADH(int bytes);
int DADSP(int bytes);
int DCRA(int bytes);
int DCRB(int bytes);
int DCRC(int bytes);
int DCRD(int bytes);
int DCRE(int bytes);
int DCRH(int bytes);
int DCRL(int bytes);
int DCRM(int bytes);
int DCXB(int bytes);
int DCXD(int bytes);
int DCXH(int bytes);
int DCXSP(int bytes);
int DI(int bytes);
int EI(int bytes);
int HLT(int bytes);
int INPortAddress(int bytes);
int INRA(int bytes);
int INRB(int bytes);
int INRC(int bytes);
int INRD(int bytes);
int INRE(int bytes);
int INRH(int bytes);
int INRL(int bytes);
int INRM(int bytes);
int INXB(int bytes);
int INXD(int bytes);
int INXH(int bytes);
int INXSP(int bytes);
int JCLabel(int bytes);
int JMLabel(int bytes);
int JMPLabel(int bytes);
int JNCLabel(int bytes);
int JNZLabel(int bytes);
int JPLabel(int bytes);
int JPELabel(int bytes);
int JPOLabel(int bytes);
int JZLabel(int bytes);
int LDAAddress(int bytes);
int LDAXB(int bytes);
int LDAXD(int bytes);
int LHLDAddress(int bytes);
int LXIB(int bytes);
int LXID(int bytes);
int LXIH(int bytes);
int LXISP(int bytes);
int MOVAA(int bytes);
int MOVAB(int bytes);
int MOVAC(int bytes);
int MOVAD(int bytes);
int MOVAE(int bytes);
int MOVAH(int bytes);
int MOVAL(int bytes);
int MOVAM(int bytes);
int MOVBA(int bytes);
int MOVBB(int bytes);
int MOVBC(int bytes);
int MOVBD(int bytes);
int MOVBE(int bytes);
int MOVBH(int bytes);
int MOVBL(int bytes);
int MOVBM(int bytes);
int MOVCA(int bytes);
int MOVCB(int bytes);
int MOVCC(int bytes);
int MOVCD(int bytes);
int MOVCE(int bytes);
int MOVCH(int bytes);
int MOVCL(int bytes);
int MOVCM(int bytes);
int MOVDA(int bytes);
int MOVDB(int bytes);
int MOVDC(int bytes);
int MOVDD(int bytes);
int MOVDE(int bytes);
int MOVDH(int bytes);
int MOVDL(int bytes);
int MOVDM(int bytes);
int MOVEA(int bytes);
int MOVEB(int bytes);
int MOVEC(int bytes);
int MOVED(int bytes);
int MOVEE(int bytes);
int MOVEH(int bytes);
int MOVEL(int bytes);
int MOVEM(int bytes);
int MOVHA(int bytes);
int MOVHB(int bytes);
int MOVHC(int bytes);
int MOVHD(int bytes);
int MOVHE(int bytes);
int MOVHH(int bytes);
int MOVHL(int bytes);
int MOVHM(int bytes);
int MOVLA(int bytes);
int MOVLB(int bytes);
int MOVLC(int bytes);
int MOVLD(int bytes);
int MOVLE(int bytes);
int MOVLH(int bytes);
int MOVLL(int bytes);
int MOVLM(int bytes);
int MOVMA(int bytes);
int MOVMB(int bytes);
int MOVMC(int bytes);
int MOVMD(int bytes);
int MOVME(int bytes);
int MOVMH(int bytes);
int MOVML(int bytes);
int MVIAData(int bytes);
int MVIBData(int bytes);
int MVICData(int bytes);
int MVIDData(int bytes);
int MVIEData(int bytes);
int MVIHData(int bytes);
int MVILData(int bytes);
int MVIMData(int bytes);
int NOP(int bytes);
int ORAA(int bytes);
int ORAB(int bytes);
int ORAC(int bytes);
int ORAD(int bytes);
int ORAE(int bytes);
int ORAH(int bytes);
int ORAL(int bytes);
int ORAM(int bytes);
int ORIData(int bytes);
int OUTPortAddress(int bytes);
int PCHL(int bytes);
int POPB(int bytes);
int POPD(int bytes);
int POPH(int bytes);
int POPPSW(int bytes);
int PUSHB(int bytes);
int PUSHD(int bytes);
int PUSHH(int bytes);
int PUSHPSW(int bytes);
int RAL(int bytes);
int RAR(int bytes);
int RC(int bytes);
int RET(int bytes);
int RIM(int bytes);
int RLC(int bytes);
int RM(int bytes);
int RNC(int bytes);
int RNZ(int bytes);
int RP(int bytes);
int RPE(int bytes);
int RPO(int bytes);
int RRC(int bytes);
int RST0(int bytes);
int RST1(int bytes);
int RST2(int bytes);
int RST3(int bytes);
int RST4(int bytes);
int RST5(int bytes);
int RST6(int bytes);
int RST7(int bytes);
int RZ(int bytes);
int SBBA(int bytes);
int SBBB(int bytes);
int SBBC(int bytes);
int SBBD(int bytes);
int SBBE(int bytes);
int SBBH(int bytes);
int SBBL(int bytes);
int SBBM(int bytes);
int SBIData(int bytes);
int SHLDAddress(int bytes);
int SIM(int bytes);
int SPHL(int bytes);
int STAAddress(int bytes);
int STAXB(int bytes);
int STAXD(int bytes);
int STC(int bytes);
int SUBA(int bytes);
int SUBB(int bytes);
int SUBC(int bytes);
int SUBD(int bytes);
int SUBE(int bytes);
int SUBH(int bytes);
int SUBL(int bytes);
int SUBM(int bytes);
int SUIData(int bytes);
int XCHG(int bytes);
int XRAA(int bytes);
int XRAB(int bytes);
int XRAC(int bytes);
int XRAD(int bytes);
int XRAE(int bytes);
int XRAH(int bytes);
int XRAL(int bytes);
int XRAM(int bytes);
int XRIData(int bytes);
int XTHL(int bytes);

extern Instruction Instructions[256];