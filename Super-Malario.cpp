// Super-Malario.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "GameLogic.h"


using namespace std;

int main(int argc, char** args)
{

	//Create new Engine


	//eng->initEngine();


	GameLogic* gl = new GameLogic();

	printf("Engine Terminated\n");
	system("pause");
	
	// End the program
	return 0;
}
