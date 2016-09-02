/*

A super simple mnemonic compiler for the Ate VM.

*/
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "byte.hpp"
#include "Opcodes.hpp"

using Onyx::byte;

enum states
{
	EXPECTING_OPCODE,
	EXPECTING_STRING,
	EXPECTING_BYTE,
	EXPECTING_BYTES,
};

static std::array<std::string, 8> enum_str = {"OPCODE", "STRING", "BYTE"};

class Compiler
{
private:
	//std::vector<size_t> string_locations; unused for the time being
	std::vector<byte> bytevec;
	short state = EXPECTING_OPCODE;
	bool is_hex(const std::string _val)
	{
		if (_val.at(0) == '0' && (_val.at(1) == 'x' || _val.at(1) == 'X'))
			return true;
		else return false;
	}
	bool is_string(const std::string _val)
	{
		if (_val.at(0) == '"' || _val.at(_val.size()-1) == '"')
			return true;
		else return false;
	}
	void store_opcode(const std::string _code, std::vector<byte> &vec)
	{
		vec.push_back(get_opcode(_code));
	}
	void error_msg(const std::string &err, short expected, short got)
	{
		std::cerr << "Compiler error!\tRead:\t" << enum_str[got] << "\nExpected:\t" << enum_str[expected] << "\n";
		if (err != "")
			std::cout << "Details: " << err << "\n";
		std::exit(-1);
	}
	std::string buffer = "";
	std::ifstream input_file;
	std::ofstream output_file;
public:
	Compiler();
	void open(const std::string _input);
	Compiler(const std::string _input);
	void compile();
	~Compiler();
};

