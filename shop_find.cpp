#include "shop_struct.h"

void find(char name[80]){
	int n;
	char s[80];
	int p;
	int k = 0;
	printf("[1]Find by type.\n[2]Find by color\n[3]Find by price.\n[4]Find by place.\n");
	printf(">Enter the number: ");
	cosmetic c1;
	scanf("%d", &n);
	FILE *f;
	if ((f = fopen( name, "rb"))== NULL){
		printf("  Cannot open file.\n");
		exit(1);
	}
	if (n == 1){
		printf("\n>Enter type: ");
		scanf("%s", s);
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
			printf("  No products found.\n");
	}else if (n == 2){
		printf("\n>Enter color: ");
		scanf("%s", s);
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
			printf("  No products found.\n");
	}else if (n == 3){
		printf("\n>Enter price: ");
		scanf("%d", &p);
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
			printf("  No products found.\n");
	}else if (n == 4){
		printf("\n>Enter place: ");
		scanf("%d", &p);
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
			printf("  No products found.\n");
	}else {
		printf("  Please, enter a number from 1 to 4\n");
		scanf("%d", &n);
	}
	fclose(f);
}
