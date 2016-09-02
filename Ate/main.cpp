#include "Opcodes.hpp"
#include "Arguments.hpp"
#include "Compiler.hpp"

bool compile = false;
bool run = false;
std::string compile_name = "";
std::string ROMNAME = "";
int main(int argc, char* argv[])
{
	if (argc < 2)
	{ 
		std::cout << "ROM: ";
		std::cin >> ROMNAME;
		std::cout << "---" << std::endl;
	}
	else
	{
		handle_args(argc, argv);
	}
	
	Ate inst;
	Compiler comp;
	if (run == true)
	{
		inst.open(ROMNAME);
		inst.run();
	}
	else if (compile == true)
	{
		comp.open(compile_name);
		comp.compile();
	}
	else
	{
		std::cout << "Error: No valid flags passed. Cannot do anything. Exiting.\n";
		return -1;
	}
	
	return 0;
}