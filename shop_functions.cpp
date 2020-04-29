#include "shop_struct.h"

void cosmetic::menu(cosmetic * mass, int size, int argc, char* argv[]){

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

void cosmetic::clear(int argc, char* argv[]){
	ofstream f(argv[1], ios_base::trunc);
	f.close();
}

void cosmetic::add(cosmetic * mass, int size, int argc, char* argv[]){
	cout<<"   Please enter information."<<endl;
	cosmetic c;
        cout<<"Type: "<<endl;
	scanf("%s", c.type);
	cout<<"Color: "<<endl;
	scanf("%s", c.color);
	cout<<"Price: "<<endl;
	scanf("%d", &c.price);
	cout<<"Place: "<<endl;
	scanf("%d", &c.place);

	mass[size-1] = c;
	ofstream f(argv[1]);
	if (f.is_open())
		cout<<"OK"<<endl;
	else{
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	fwrite(&mass[size-1], sizeof(cosmetic), 1, bf_in);
	f.close();
	cout<<"  Product added."<<endl;
}

void cosmetic::pprint(int argc, char* argv[]){
	cosmetic c2;
	ifstream f(argv[1]);
	if (f.is_open())
		cout<<"OK"<<endl;
	else{
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	while(!feof(bf_out)){
		fread(&c2, sizeof(c2), 1, bf_out);
		printf("\nType: %s\n", c2.type);
		printf("Color: %s\n", c2.color);
		printf("Price: %d\n", c2.price);
		printf("Place: %d\n", c2.place);
	}
	f.close();
}
