// Super-Malario.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Engine.cpp"


using namespace std;

int main(int argc, char** args)
{

	//Create new Engine
	Engine *eng = new Engine();

	eng->initEngine();



	// End the program
	return 0;
}
