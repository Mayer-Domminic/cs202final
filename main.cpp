#include <iostream>
#include "iWavModel.h"
#include "Echo.h"
#include "Controller.h"

int main(){
	Console console;
	Controller controller;
	controller.setConsole(&console);
	controller.run();
	
	return 0;
}