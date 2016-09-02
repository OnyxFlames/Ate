#pragma once

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include "byte.hpp"

using std::stoi;
using Onyx::byte;

struct Ate
{
public:
	void (*opcodes[256])(Ate&);
	Ate();
	Ate(const std::string ROM);
	void open(const std::string ROM);
	void run();
	// Hardware features
	unsigned short pc = 0;
	byte ptr = 0;		// memory pointer register. used for loading chunks of memory at a time.
	byte X, Y;			// Opcode buffer registers.
	byte memory[256];	// The VM's RAM (0 - 255)
	// ...

	unsigned ROM_SIZE;
	byte ROM[65535];	// ROM size max is (2^16) - 1
	void get_input()
	{
		X = ROM[pc++];
		Y = ROM[pc++];
	}
	~Ate();
};