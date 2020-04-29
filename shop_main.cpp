#include "shop_struct.h"

int main(int argc, char* argv[]){
	cout<<" Welcome to the cosmetic shop!"<<endl;
	cout<<" >Enter file name: "<<endl;

	int size = 0;
	ifstream f(argv[1]);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	cosmetic temp;
	while(!feof(f)){
		fread(&temp, sizeof(cosmetic), 1, f);
		size++;
	}
	size--;
	f.close();

	cosmetic * mass = new cosmetic[size];

	int number;
	do{
		cosmetic.menu(mass, size, argv[1]);
	} while (number !=6);
	
	delete [] mass;

	return 0;
}
