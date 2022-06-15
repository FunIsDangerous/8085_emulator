#pragma once

#include <chrono>
#include <thread>
#include <vector>

#include "memory.h"
#include "stack.h"
#include "register.h"
#include "IOchip.h"

//Flag bits

#define SIGN_FLAG 7
#define ZERO_FLAG 6
#define AUX_CARRY_FLAG 4
#define PARITY_FLAG 2
#define CARRY_FLAG 0

//Clock speed it 3.2mhz
//We divide that in CLOCK_ACCURACY steps.
//More explanation in .cpp file.

// Probably should make them into variables and have options about them..

#define CLOCK_SPEED 3200000 // Clock speed of 8085 is 3.2mhz
#define CLOCK_ACCURACY 200 // The higher, the better the accuracy of the timing.

class CPU
{
private:
	//Each instruction takes multiple cycles in the real 8085.
	//Here, we execute them all in one or in a few lines of code.
	//So, for us it's only "one cycle". So we will do absolutely nothing for the next few cycles.
	//how many, depending on the instruction.
	int _HangingCycles;
	bool _Running;
	bool _Halted;

public:
	static CPU* cpu;

	std::vector<int> &_Breakpoints;
	std::vector<std::pair<uint16_t, int>> _Symbols;

	Memory* _Memory;
	IOchip* _IOchip;
	Stack* _Stack;

	Register8* A;
	Register8* B;
	Register8* C;
	Register8* D;
	Register8* E;
	Register8* H;
	Register8* L;

	Register8* Flags;

	Register* PC;
	Register* SP;

public:

	bool _InterruptsEnabled = false;

	bool _M55 = true;
	bool _M65 = true;
	bool _M75 = true;

	bool _IP55 = false;
	bool _IP65 = false;
	bool _IP75 = false;

	bool _IPINTR = false;
	uint16_t INTR_ADDR = 0;

public:

	CPU(Memory* memory, IOchip* io, std::vector<int>& breakpoints, std::vector<std::pair<uint16_t, int>>& symbols);
	CPU(uint8_t* memory, size_t size, IOchip* io, std::vector<int>& breakpoints, std::vector<std::pair<uint16_t, int>> symbols);
	~CPU();

	std::thread Run();

	bool Interrupts();

	void Loop();

	void Clock();

	void Step(std::vector<std::pair<uint16_t, int>> Symbols);

	void SetFlags(uint8_t sign, uint8_t zero, uint8_t aux_c, uint8_t parity, uint8_t carry);

	int GetInstructionBytes();

	inline void SetRunning(bool running)
	{
		_Running = running;
	}

	inline bool GetRunning()
	{
		return _Running;
	}

	inline void SetHalted(bool halted)
	{
		_Halted = halted;
	}

	inline bool GetHalted()
	{
		return _Halted;
	}

	inline Memory* GetMemory()
	{
		return _Memory;
	}

	inline IOchip* GetIO()
	{
		return _IOchip;
	}

	//Read memory at location pointed by H,L. Return unsigned.
	inline uint8_t GetUnsignedM()
	{
		uint8_t H = cpu->H->GetUnsigned();
		uint8_t L = cpu->L->GetUnsigned();

		uint16_t addr = (H << 8) | L;
		uint8_t result = cpu->GetMemory()->GetDataAtAddr(addr);

		return result;
	}

	//Read memory at location pointed by H,L. Return signed
	inline int8_t GetSignedM()
	{
		uint8_t H = cpu->H->GetSigned();
		uint8_t L = cpu->L->GetSigned();

		uint16_t addr = (H << 8) | L;
		uint8_t result = cpu->GetMemory()->GetDataAtAddr(addr);

		return *(int8_t*)&result;
	}

	//Increment PC and then read the data at that address.
	inline uint8_t NextPC()
	{
		PC->Increment();
		uint8_t ret = _Memory->GetDataAtAddr(PC->Get());

		return ret;
	}

	//Read current PC without incrementing.
	inline uint8_t ReadPC()
	{
		return _Memory->GetDataAtAddr(PC->Get());
	}
};