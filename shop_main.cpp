#include "shop_struct.h"

int main(int argc, char* argv[]){
	cout<<" Welcome to the cosmetic shop!"<<endl;
	cout<<" >Enter file name: "<<endl;

	int size = 0;
	ifstream f(name);
	if (f.is_open())
		cout<<"OK"<<endl;
	else{
		cout<<"Cannot open file."<<endl;
		return 1;

	cosmetic temp;
	while(!feof(f)){
		fread(&temp, sizeof(cosmetic), 1, f);
		size++;
	}
	size--;
	f.close();

	cosmetic * mass = (cosmetic*)malloc(sizeof(cosmetic) * size);

	int number;
	do{
		menu(mass, size, name);
	} while (number !=6);
	
	free(mass);

	return 0;
}
