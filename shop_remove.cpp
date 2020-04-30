#include "shop_struct.h"

void rremove(cosmetic mass[], int size, int argc, char* argv[]){

	cout<<" >Enter product: "<<endl;
	string type, color;
	int price, place;
	cout<<"Type: "<<endl;
	getline(cin, type);
	cout<<"Color: "<<endl;
	getline(cin, color);
	cout<<"Price: "<<endl;
	cin>>price;
	cout<<"Place: "<<endl;
	cin>>place;
	int i;
	
	ifstream f(argv[1]);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	cosmetic c3;
	while(f.read((cosmetic *)&c3, sizeof(cosmetic))
		for(i = size-1; i >= 0; i--)
			f.read((cosmetic *)&mass[i], sizeof(cosmetic));
	f.close();

	int rm_i, k = 0;
	for(i = size-1; i >= 0; i--){
		if ((strcmp(type, mass[i].type)== 0) && (strcmp(color, mass[i].color)== 0) && (price == mass[i].price) && (place == mass[i].place)){
			rm_i = i;
			k++;
		}
	}
	if(k != 0){
		ofstream newf(argv[1], ios::trunc);
		if (!f.is_open()){
			cout<<"Cannot open file."<<endl;
			return 1;
		}
		
		for(i = size-1; i >=0; i--){
			if (i != rm_i)
				newf.write((cosmetic *)&mass[i], sizeof(cosmetic));
			}
		f.close();
		size--;
		cout<<" Product removed."<<endl;
	}else
		cout<<" Product not found."<<endl;
}
