#pragma once
#include <string>
#include <array>
#include "byte.hpp"
#include "Ate.hpp"
using Onyx::byte;

static std::array<std::string, 16> OPCODESTR = { "NOP", "LOAD", "LOADC", "MOVE",
												"COPY", "SWAP", "ADD", "SUB", "MUL",
												"DIV", "PRINT", "SET", "JUMP", "EXEC", };
static bool is_opcode(const std::string _name)
{
	for (byte it = 0; it < OPCODESTR.size(); it++)
		if (OPCODESTR[it] == _name)
			return true;
	return false;
}
static byte get_opcode(const std::string _name)
{
	for (byte it = 0; it < OPCODESTR.size(); it++)
		if (OPCODESTR[it] == _name)
			return it;
	std::cout << "Unable to find OPCODE: " << _name << "\n";
	return 0x00;
}

// Opcodes
void NOP(Ate &instance);
void load(Ate &instance);
void loadc(Ate &instance);
void move(Ate &instance);
void copy(Ate &instance);
void swap(Ate &instance);
void add(Ate &instance);
void sub(Ate &instance);
void div(Ate &instance);
void mul(Ate &instance);
void print(Ate &instance);
void set(Ate &instance);
void jump(Ate &instance);
void exec(Ate &instance);
void exit_vm(Ate &instance);