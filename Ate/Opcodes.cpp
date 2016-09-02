#include "Opcodes.hpp"

void NOP(Ate &instance)
{
	//instance.pc++;
}
void load(Ate &instance)
{
	instance.get_input();
	instance.memory[instance.Y] = instance.X;
}
void loadc(Ate &instance)
{
	instance.get_input();
	for (byte it = instance.X; it <= instance.Y; it++)
		instance.memory[instance.ptr + (it - instance.X)] = instance.ROM[it];
}
void move(Ate &instance)
{
	instance.get_input();
	instance.memory[instance.Y] = instance.memory[instance.X];
	instance.memory[instance.X] = 0;
}
void copy(Ate &instance)
{
	instance.get_input();
	instance.memory[instance.Y] = instance.memory[instance.X];
}
void swap(Ate &instance)
{
	instance.get_input();
	byte temp;
	temp = instance.memory[instance.Y];
	instance.memory[instance.Y] = instance.memory[instance.X];
	instance.memory[instance.X] = temp;
}
void add(Ate &instance)
{
	instance.memory[instance.X] = (instance.memory[instance.X] + instance.memory[instance.Y]);
}
void sub(Ate &instance)
{
	instance.memory[instance.X] = (instance.memory[instance.X] - instance.memory[instance.Y]);
}
void mul(Ate &instance)
{
	instance.memory[instance.X] = (instance.memory[instance.X] * instance.memory[instance.Y]);
}
void div(Ate &instance)
{
	instance.memory[instance.X] = (instance.memory[instance.X] / instance.memory[instance.Y]);
}
void print(Ate &instance)
{
	instance.get_input();
	byte _x = instance.X, _y = instance.Y;
	if (_x < _y)
	{
		while (_x <= _y)
		{
			std::cout << static_cast<byte>(instance.memory[_x++]);
			if (_x == _y)
				break;
		}
	}
	else if (_x > _y)
	{
		while (_x >= _y)
		{
			std::cout << static_cast<byte>(instance.memory[_x--]);
			if (_x == _y)
				break;
		}
	}
	else if (_x == _y)
		std::cout << static_cast<byte>(instance.memory[_x]);
}

void set(Ate &instance)
{
	// Set only uses one more byte, so instance.Y is discarded at the end of the opcode.
	instance.get_input();
	instance.ptr = instance.X;
}
void jump(Ate &instance)
{
	instance.get_input();
	instance.pc = Onyx::to_ushort({ instance.X, instance.Y });
}
void exec(Ate &instance)
{
	instance.get_input();
	// execute all the bytes in memory between instance.X and instance.Y as opcodes using this instance of the VM (self executing code)
	for (byte it = instance.X; it <= instance.Y; it++)
	{
		(*instance.opcodes[instance.memory[it]])(instance);
	}
}
void exit_vm(Ate &instance)
{
	std::exit(1);
}