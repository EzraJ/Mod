// Mod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ModDLL.h"

int intInput;
std::string input;
std::string dir;
bool running = true;

changesData data(dir, running, intInput);
changes change(input,  data);
properties windowProp;

int main() {	
	std::cout << "WARNING: Be careful on any externel DLLs for Mod DLL You decide to download, it could contain malicous content." << std::endl << "Press enter to continue";
	std::cin.get();
	windowProp.consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string strBuffer = "ModDLL v" + VERSION;
	std::wstring buffer = std::wstring(strBuffer.begin(), strBuffer.end());
	windowProp.windowName = buffer.c_str();
	windowProp.points = COORD{ 1280, 720 };
	windowProp.windowSize = SMALL_RECT{ 0, 0, 100, 100 };
	init(change, windowProp);
	while (running) {
		std::string buffer;
		std::cout << dir << "> ";
		std::getline(std::cin, buffer);
		if ((int)buffer[0] == 0 || buffer == "\n" || buffer[0] == ' ') {
			buffer = "clear";
		}
		change.input = buffer;
		
		run(change);
	}
}
