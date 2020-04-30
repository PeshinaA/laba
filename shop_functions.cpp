#include "shop_struct.h"

void menu(cosmetic mass[], int size, int argc, char* argv[]){

	cout<<"  What do you want to do?"<<endl;
	cout<<"[1] Add product."<<endl;
	cout<<"[2] Print all products."<<endl;
	cout<<"[3] Remove product."<<endl;
	cout<<"[4] Find product."<<endl;
	cout<<"[5] Clear file."<<endl;
	cout<<"[6] Exit."<<endl;
	cout<<" >Enter the number: "<<endl;
	
	int number;
	cin>>number;
	switch(number){
		case 1:
			add(mass, size, argv[1]);
			size++;
			break;
		case 2:
			pprint(argv[1]);
			break;
		case 3:
			rremove(mass, size, argv[1]);
			break;
		case 4:
			find(argv[1]);
			break;
		case 5:
			clear(argv[1]);
			break;
		case 6:
			cout<<"  Goodbye."<<endl;
			exit(0);

		default:
			cout<<"  Please, enter the number for 1 to 5."<<endl;
			break;
	}
}

void clear(int argc, char* argv[]){
	ofstream f(argv[1], ios_base::trunc);
	f.close();
}

void add(cosmetic mass[], int size, int argc, char* argv[]){
	cout<<"   Please enter information."<<endl;
	cosmetic c;
        cout<<"Type: "<<endl;
	getline(cin, c.type);
	cout<<"Color: "<<endl;
	getline(cin, c.color);
	cout<<"Price: "<<endl;
	cin>>c.price;
	cout<<"Place: "<<endl;
	cin>>c.place;

	mass[size-1] = c;
	ofstream f(argv[1]);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	f.write((cosmetic *)&mass[size-1], sizeof(cosmetic));
	f.close();
	cout<<"  Product added."<<endl;
}

void pprint(int argc, char* argv[]){
	cosmetic c2;
	ifstream f(argv[1]);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	while(f.read((cosmetic *)&c2, sizeof(cosmetic))){
		cout<<"Type: "<<c2.type<<"Color: "<<c2.color<<"Price: "<<c2.price<<"Place: "<<c2.place<<endl;
	}
	f.close();
}
