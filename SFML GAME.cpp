#define _CRTDBG_MAP_ALLOC
#include "uwu.h"
#include <iostream>
#include <time.h>// random 

int main()
{
	srand(time(NULL));
	//no memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	uwu uwuQuiz;
	uwuQuiz.run();
	//memory leaks tester
	//int* leaksMaker = new int();
	return 0;
}
