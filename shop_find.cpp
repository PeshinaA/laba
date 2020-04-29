#include "shop_struct.h"

void cosmetic::find(int argc, char* argv[]){
	int n;
	string s;
	int p;
	int k = 0;
	cout<<"[1]Find by type."<<endl;
	cout<<"[2]Find by color"<<endl;
	cout<<"[3]Find by price."<<endl;
	cout<<"[4]Find by place."<<endl;
	cout<<" >Enter the number: "<<end;
	cosmetic c1;
	cin>>n;
	
	ifstream f(argv[1]);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	if (n == 1){
		cout<<"\n>Enter type: "<<endl;
		getline(cin, s);
		while(!feof(f)){
			fread(&c1, sizeof(c1), 1, f);
			if (strcmp( s, c1.type)== 0) {
				k++;
				printf("\nType: %s\n", c1.type);
				printf("Color: %s \n", c1.color);
				printf("Price: %d\n", c1.price);
				printf("Place: %d\n", c1.place);
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 2){
		cout<<" >Enter color: "<<endl;
		getline(cin, s);
		while(!feof(f)){
			fread(&c1, sizeof(c1), 1, f);
			if (strcmp( s, c1.color)== 0) {
				k++;
				printf("\nType: %s\n", c1.type);
				printf("Color: %s \n", c1.color);
				printf("Price: %d\n", c1.price);
				printf("Place: %d\n", c1.place);
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 3){
		cout<<" >Enter price: "<<endl;
		cin>>p;
		while(!feof(f)){
			fread(&c1, sizeof(c1), 1, f);
			if (c1.price == p) {
				k++;
				printf("\nType: %s\n", c1.type);
				printf("Color: %s \n", c1.color);
				printf("Price: %d\n", c1.price);
				printf("Place: %d\n", c1.place);
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 4){
		cout<<" >Enter place: "<<endl;
		cin>>p;
		while(!feof(f)){
			fread(&c1, sizeof(c1), 1, f);
			if (c1.place == p) {
				k++;
				printf("\nType: %s\n", c1.type);
				printf("Color: %s \n", c1.color);
				printf("Price: %d\n", c1.price);
				printf("Place: %d\n", c1.place);
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else {
		cout<<"  Please, enter a number from 1 to 4."<<endl;
		cin>>n;
	}
	f.close();
}
