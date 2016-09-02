#include "Compiler.hpp"

Compiler::Compiler()
{
}
Compiler::Compiler(const std::string _input)
{
	open(_input);
}
Compiler::~Compiler()
{
}
void Compiler::open(const std::string _input)
{
	input_file.open(_input);
	if (!input_file.is_open())
	{
		std::cout << "Error: Failed to invoke compiler. " << _input << " is not a file.\n";
		std::exit(-1);
	}
	output_file.open(_input + ".8", std::ios::binary);
	if (!output_file.is_open())
	{
		std::cout << "Error: Failed to invoke compiler. " << _input << ".8 cannot be created.\n";
		std::exit(-1);
	}
}
void Compiler::compile()
{
	while (!input_file.eof())
	{
		input_file >> buffer;
		if (is_opcode(buffer))
		{
				store_opcode(buffer, bytevec);
		}
		else if (is_hex(buffer))
		{
				bytevec.push_back(stoi(buffer, 0, 16));
		}
		else if (buffer.size() == 1 && isalpha(buffer.at(0)))
		{
			bytevec.push_back(buffer.at(0));
		}
		else if (is_string(buffer)/* || state == EXPECTING_STRING*/)
		{
				for (auto c : buffer)
				{
					// Ate doesn't support character escapes, so any quotes or backslashes get ignored for the time being.
					if (c == '\\' || c == '\"')
						continue;
					else
					{
						bytevec.push_back((byte)c);
					}
				}
		}
	}
	for (auto _byte : bytevec)
		output_file << _byte;
}

