#include "shop_struct.h"

void rremove(cosmetic * mass, int size, int argc, char* argv[]){

	cout<<" >Enter product: "<<endl;
	string type, color;
	int price, place;
	cout<<"Type: "<<endl;
	scanf("%s", type);
	cout<<"Color: "<<endl;
	scanf("%s", color);
	cout<<"Price: "<<endl;
	scanf("%d", &price);
	cout<<"Place: "<<endl;
	scanf("%d", &place);
	int i;
	
	ifstream f(argv[1]);
	if (f.is_open())
		cout<<"OK"<<endl;
	else{
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	while(!feof(f))
		for(i = size-1; i >= 0; i--)
			fread(&mass[i], sizeof(cosmetic), 1, f);
	f.close();

	int rm_i, k = 0;
	for(i = size-1; i >= 0; i--){
		if ((strcmp(type, mass[i].type)== 0) && (strcmp(color, mass[i].color)== 0) && (price == mass[i].price) && (place == mass[i].place)){
			rm_i = i;
			k++;
		}
	}
	if(k != 0){
		ofstream f(argv[1]);
		if (f.is_open())
			cout<<"OK"<<endl;
		else{
			cout<<"Cannot open file."<<endl;
			return 1;
		}
		
		for(i = size-1; i >=0; i--){
			if (i != rm_i)
				fwrite(&mass[i], sizeof(cosmetic), 1, newf);
			}
		f.close();
		size--;
		cout<<" Product removed."<<endl;
	}else
		cout<<" Product not found."<<endl;
}
