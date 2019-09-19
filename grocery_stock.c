#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grocery{
	char item_name[100];
	int item_qty;
	double item_cost;
};
void additem(struct grocery department[100], int count);
void editquantity(struct grocery department[100], int count);
void editcost(struct grocery department[100], int count);
void grocery_list(struct grocery department1[100], int count1, struct grocery department2[100], int count2, struct grocery department3[100], int count3, struct grocery department4[100], int count4);

int main(void){
	struct grocery produce[100];
	struct grocery deli[100];
	struct grocery bakery[100];
	struct grocery frozen[100];

	int choice, dept;
	static int item_p=0;
	static int item_d=0;
	static int item_b=0;
	static int item_f=0;

	printf("Welcome to the grocery store inventory manager menu!\n");

	while(1){
		printf("\nPlease select an option from the menu:\n");
		printf("1. Add an item to inventory\n2. Change the quantity of an item in inventory\n3. Change the cost of an item in inventory\n4. Output entire inventory to file\n5. Exit program\n\n");
		scanf("%d", &choice);
		if(choice == 1){
			printf("\nPlease select which department you would like to perform this action for:\n");
			printf("1. Produce\n2. Deli\n3. Bakery\n4. Frozen Foods\n5. Exit Sub-menu\n");
			scanf("%d", &dept);
			if(dept == 1){
				additem(produce, item_p);
				printf("\n%s has been added to the store inventory list.\n", produce[item_p].item_name);
				item_p++;
			}
			else if(dept == 2){
				additem(deli, item_d);
				printf("\n%s has been added to the store inventory list.\n", deli[item_d].item_name);
				item_d++;
			}
			else if(dept == 3){
				additem(bakery, item_b);
				printf("\n%s has been added to the store inventory list.\n", bakery[item_b].item_name);
				item_b++;
			}
			else if(dept == 4){
				additem(frozen, item_f);
				printf("\n%s has been added to the store inventory list.\n", frozen[item_f].item_name);
				item_f++;
			}
			else if(dept == 5){
				printf(" You will now be returned to the main menu.\n");
			}
			else{
				printf("That choice is invalid, returning to the menu.\n");
			}
		}
		else if(choice == 2){
			printf("Please select which department you would like to perform this action for:\n");
			printf("1. Produce\n2. Deli\n3. Bakery\n4. Frozen Foods\n5. Exit Sub-menu\n");
			scanf("%d", &dept);
			if(dept == 1){
				editquantity(produce, item_p);
			}
			else if(dept == 2){
				editquantity(deli, item_d);
			}
			else if(dept == 3){
				editquantity(bakery, item_b);
			}
			else if(dept == 4){
				editquantity(frozen, item_f);
			}
			else if(dept == 5){
				printf(" You will now be returned to the main menu\n");
			}
			else{
				printf("That choice is invalid, returning to the menu\n");
			}
		}
		else if(choice == 3){
			printf("Please select which department you would like to perform this action for:\n");
			printf("1. Produce\n2. Deli\n3. Bakery\n4. Frozen Foods\n5. Exit Sub-menu\n");
			scanf("%d", &dept);
			if(dept == 1){
				editcost(produce, item_p);
			}
			else if(dept == 2){
				editcost(deli, item_d);
			}
			else if(dept == 3){
				editcost(bakery, item_b);
			}
			else if(dept == 4){
				editcost(frozen, item_f);
			}
			else if(dept == 5){
				printf("You will now be returned to the main menu\n");
			}
			else{
				printf("That choice is invalid, returning to the main menu\n");
			}
		}
		else if(choice == 4){
			grocery_list(produce, item_p, deli, item_d, bakery, item_b, frozen, item_f);
			printf("The inventory has been succesfully uploaded to file \"grocery_list.txt\"\n");
		}
		else if(choice == 5){
			break;
		}
		else{
			printf("That choice is invalid, returning to the main menu\n");
		}
	}
	printf("\nThe grocery store inventory manager will now exit\n");
	return 0;
}

void additem(struct grocery department[100], int count){
	char name[100];
	int quantity;
	double cost;
	printf("Please enter the name of the item to add: ");
	scanf("%s", name);
	for(int i=0;name[i]!='\0';i++){
		department[count].item_name[i] = name[i];
	}
	printf("\nPlease enter the quantity of the item: ");
	scanf("%d", &quantity);
	department[count].item_qty = quantity;
	printf("\nPlease enter the cost of the item: ");
	scanf("%lf", &cost);
	department[count].item_cost = cost;
}

void editquantity(struct grocery department[100], int count){
	if(count==0){
		printf("There are no items in this department.\nYou will now be returned to the main menu.\n");
	}
	else{
		int modify, quantity;
		printf("Please select the item for which you wish to edit the quantity:\n");
		for (int i=0;i<count;i++){
			printf("%d. %s\n", i+1, department[i].item_name);
		}
		printf("0. Exit Sub-menu\n");
		scanf("%d", &modify);
		if(modify == 0){
			printf("You will now be returned to the main menu.\n");
		}
		else{
			if(modify>0 && modify<=count){
				printf("Please enter the new item quantity: ");
				scanf("%d", &quantity);
				department[modify-1].item_qty = quantity;
			}
			else{
				printf("That choice is invalid, returning to the main menu\n");
			}
		}
	}
}

void editcost(struct grocery department[100], int count){
	if(count==0){
		printf("There are no items in this department.\nYou will now be returned to the main menu.\n");
	}
	else{
		int modify; 
		double cost;
		printf("Please select the item for which you wish to edit the cost:\n");
		for (int i=0;i<count;i++){
			printf("%d. %s\n", i+1, department[i].item_name);
		}
		printf("0. Exit Sub-menu\n");
		scanf("%d", &modify);
		if(modify == 0){
			printf("You will now be returned to the main menu.\n");
		}
		else{
			if(modify>0 && modify<=count){
				printf("Please enter the new item cost: ");
				scanf("%lf", &cost);
				department[modify-1].item_cost = cost;
			}
			else{
				printf("That choice is invalid, returning to the main menu\n");
			}
		}
	}
}

void grocery_list(struct grocery department1[100], int count1, struct grocery department2[100], int count2, struct grocery department3[100], int count3, struct grocery department4[100], int count4){
	FILE *glist;
	glist= fopen("grocery_list.txt", "w+");
	fprintf(glist, "Produce Department Inventory\n");
	for(int p=0;p<count1;p++){
		fprintf(glist,"%s, Quantity: %d,Cost: $%.2lf\n", department1[p].item_name, department1[p].item_qty, department1[p].item_cost);
	}
	fprintf(glist, "\nDeli Department Inventory\n");
	for(int d=0;d<count2;d++){
		fprintf(glist,"%s, Quantity: %d,Cost: $%.2lf\n", department2[d].item_name, department2[d].item_qty, department2[d].item_cost);
	}
	fprintf(glist, "\nBakery Department Inventory\n");
	for(int b=0;b<count3;b++){
		fprintf(glist,"%s, Quantity: %d,Cost: $%.2lf\n", department3[b].item_name, department3[b].item_qty, department3[b].item_cost);
	}
	fprintf(glist, "\nFrozen Food Department Inventory\n");
	for(int f=0;f<count4;f++){
		fprintf(glist,"%s, Quantity: %d,Cost: $%.2lf\n", department4[f].item_name, department4[f].item_qty, department4[f].item_cost);
	}
	fclose(glist);
}