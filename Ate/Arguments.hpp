#pragma once

#include <string>
#include <iostream>
#include <cstring>

extern std::string compile_name;
extern std::string ROMNAME;
extern bool compile;
extern bool run;

void print_usage()
{
	std::cout << "Usage: TODO\n";
}

void handle_args(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (std::strcmp(argv[i], "-help") == 0)
		{
			print_usage();
		}
		else if ((std::strcmp(argv[i], "-c") == 0) && (i < argc))
		{
			compile = true;
			compile_name = argv[++i];
		}
		else
		{
			run = true;
			ROMNAME = argv[i];
		}
	}
}