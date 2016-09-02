#include "Ate.hpp"
#include "Opcodes.hpp"

Ate::Ate() : X(0), Y(0)
{
}

void Ate::open(const std::string ROM) 
{
	// Initializing opcodes
	size_t init = 0;
	opcodes[(int)get_opcode("NOP")] = &NOP;		//00
	opcodes[(int)get_opcode("LOAD")] = &load;	//01
	opcodes[(int)get_opcode("LOADC")] = &loadc;	//02
	opcodes[(int)get_opcode("MOVE")] = &move;	//03
	opcodes[(int)get_opcode("COPY")] = &copy;	//04
	opcodes[(int)get_opcode("SWAP")] = &swap;	//05
	opcodes[(int)get_opcode("ADD")] = &add;		//06
	opcodes[(int)get_opcode("SUB")] = &sub;		//07
	opcodes[(int)get_opcode("MUL")] = &mul;		//08
	opcodes[(int)get_opcode("DIV")] = &div;		//09
	opcodes[(int)get_opcode("PRINT")] = &print;	//0A
	opcodes[(int)get_opcode("SET")] = &set;		//0B
	opcodes[(int)get_opcode("JUMP")] = &jump;	//0C
	opcodes[(int)get_opcode("EXEC")] = &exec;	//0D

	init = OPCODESTR.size();
	for (size_t i = init; i < 255; i++)
		opcodes[i] = &exit_vm;
	std::ifstream ROM_file(ROM);
	if (!ROM_file.is_open())
	{
		std::cout << "Invalid 8 ROM.\n";
		std::exit(-1);
	}
	else
	{
		unsigned short i = 0;
		while (!ROM_file.eof())
			this->ROM[i++] = ROM_file.get();

		ROM_SIZE = i - 1;

		//padding
		while (i < (std::pow(2, 16) - 1))
			this->ROM[i++] = 0x00;
	}
}

Ate::Ate(const std::string ROM) : X(0), Y(0)
{
	open(ROM);
}

Ate::~Ate()
{
}

void Ate::run()
{
	for (; pc < ROM_SIZE;)
		(*opcodes[ROM[pc++]])(*this);
}
