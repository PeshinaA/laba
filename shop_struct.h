#include <iostream>
#include <fstream>
#include <string>
#include <new>
using namespace std;
typedef struct product{
	int place;
	int price;
	char type[80];
	char color[80];
} cosmetic;

void menu();
void add();
void pprint();
void clear();
void rremove();
void find();
