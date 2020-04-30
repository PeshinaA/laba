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
	
	cosmetic c;
	while(f.read((cosmetic *)&c, sizeof(cosmetic))){
		size++;
	}
	f.close();

	cosmetic * mass = new cosmetic[size];

	int number;
	do{
		menu(mass, size, argv[1]);
	} while (number !=6);
	
	delete [] mass;

	return 0;
}
