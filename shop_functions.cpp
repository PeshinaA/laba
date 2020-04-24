#include "shop_struct.h"

void menu(cosmetic * mass, int size, char name[80]){
	int number;
	printf("\n  What do you want to do?\n");
	printf("[1] Add product.\n");
	printf("[2] Print all products.\n");
	printf("[3] Remove product.\n");
	printf("[4] Find product.\n");
	printf("[5] Clear file.\n");
	printf("[6] Exit.\n");
	printf(">Enter the number: ");

	scanf("%d", &number);
	switch(number){
		case 1:
			add(mass, size, name);
			size++;
			break;
		case 2:
			pprint(name);
			break;
		case 3:
			rremove(mass, size, name);
			break;
		case 4:
			find(name);
			break;
		case 5:
			clear(name);
			break;
		case 6:
			printf("  Goodbye.\n");
			exit(0);

		default:
			printf("\n  Please, enter the number for 1 to 5.\n");
			break;
	}
}

void clear(char name[80]){
	FILE *f = fopen(name, "wb");
	fclose(f);
}

void add(cosmetic * mass, int size, char name[80]){
	printf("\n   Please enter information.\n");
	cosmetic c;
        printf("Type: ");
	scanf("%s", c.type);
	printf("Color: ");
	scanf("%s", c.color);
	printf("Price: ");
	scanf("%d", &c.price);
	printf("Place: ");
	scanf("%d", &c.place);

	mass[size-1] = c;
	FILE *bf_in;
	if (( bf_in = fopen( name, "a+b"))== NULL){
		printf("  Cannot open file.\n");
		exit(1);
	}

	fwrite(&mass[size-1], sizeof(cosmetic), 1, bf_in);
	fclose(bf_in);
	printf("\n  Product added.\n");
}

void pprint(char name[80]){
	cosmetic c2;
	FILE *bf_out;
	if (( bf_out = fopen( name, "r+b"))== NULL){
		printf("  Cannot open file.\n");
		exit(1);
	}

	while(!feof(bf_out)){
		fread(&c2, sizeof(c2), 1, bf_out);
		printf("\nType: %s\n", c2.type);
		printf("Color: %s\n", c2.color);
		printf("Price: %d\n", c2.price);
		printf("Place: %d\n", c2.place);
	}
	fclose(bf_out);
}
