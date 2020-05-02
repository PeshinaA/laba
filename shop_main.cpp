#include "shop_struct.h"

int main(int argc, char* argv[]){
	cout<<" Welcome to the cosmetic shop!"<<endl;

	char *name = argv[1];
	int size = 0;
	int max = 100;

	cosmetic * mass = new cosmetic[max];

	menu(name, mass, size);
	

	return 0;
}
