#include "shop_struct.h"

void rremove(cosmetic * mass, int size, char name[80]){

	printf("\n>Enter product: ");
	char type[80], color[80];
	int price, place;
	printf("\nType: ");
	scanf("%s", type);
	printf("Color: ");
	scanf("%s", color);
	printf("Price: ");
	scanf("%d", &price);
	printf("Place: ");
	scanf("%d", &place);
	int i;
	FILE * f;
	if (( f = fopen( name, "rb"))== NULL){
		printf("  Cannot open file.\n");
		exit(1);
	}
	while(!feof(f))
		for(i = size-1; i >= 0; i--)
			fread(&mass[i], sizeof(cosmetic), 1, f);
	fclose(f);

	int rm_i, k = 0;
	for(i = size-1; i >= 0; i--){
		if ((strcmp(type, mass[i].type)== 0) && (strcmp(color, mass[i].color)== 0) && (price == mass[i].price) && (place == mass[i].place)){
			rm_i = i;
			k++;
		}
	}
	if(k != 0){
		FILE * newf;
		if (( newf = fopen( name, "w+b"))== NULL){
			printf("  Canot open file.\n");
			exit(1);
		}
		for(i = size-1; i >=0; i--){
			if (i != rm_i)
				fwrite(&mass[i], sizeof(cosmetic), 1, newf);
		}
		fclose(newf);
		size--;
	printf("\n  Product removed.\n");
	}else
		printf("\n  Product not found.\n");
}
