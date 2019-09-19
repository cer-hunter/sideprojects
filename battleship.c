#include <stdio.h>
#include <stdlib.h>

void printBoard(int board[10][10]);
void printGameBoard(char board[10][10]);
void place1x5(int x, int y, int board[10][10]);
void place1x4(int x, int y, int board[10][10]);
void place1x3(int x, int y, int board[10][10]);

int p1Board[10][10]={{0}}, p2Board[10][10]={{0}};
char gameBoard1[10][10]={{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'}}, gameBoard2[10][10]={{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'}};


int main(void)
{
	int wcoord, dcoord;
	printf("Welcome to Battleship!\n");
	printf("Displayed below is your playing board, ships are represented by the number 1: \n");
	printBoard(p1Board);
	printf("Player 1 please enter the width location of your 1x5 ship: ");
	scanf("%d", &wcoord);
	printf("Player 1 please enter the depth location of your 1x5 ship: ");
	scanf("%d", &dcoord);
	if((wcoord<=9 && wcoord>=0) && (dcoord<=9 && dcoord>=0)){
		place1x5(dcoord, wcoord, p1Board);
	}
	else{
		printf("This set of co-ordinates is invalid.\n");
		return 0;
	}
	printf("Player 1 please enter the width location of your 1x3 ship: ");
	scanf("%d", &wcoord);
	printf("Player 1 please enter the depth location of your 1x3 ship: ");
	scanf("%d", &dcoord);
	if((wcoord<=9 && wcoord>=0) && (dcoord<=9 && dcoord>=0) && p1Board[dcoord][wcoord]!=1){
		place1x3(dcoord, wcoord, p1Board);
		}
	else{
		printf("This set of co-ordinates is invalid.\n");
		return 0;
	}
	printf("Player 1 please enter the width location of your 1x4 ship: ");
	scanf("%d", &wcoord);
	printf("Player 1 please enter the depth location of your 1x4 ship: ");
	scanf("%d", &dcoord);
	if((wcoord<=9 && wcoord>=0) && (dcoord<=9 && dcoord>=0) && p1Board[dcoord][wcoord]!=1){
		place1x4(dcoord, wcoord, p1Board);
		}
	else{
		printf("This set of co-ordinates is invalid.\n");
		return 0;
	}

	printf("Please press the enter key to pass the input to Player 2\n");
	getchar();
	if(getchar() == '\n'){
		system("clear");
	}

	printf("Welcome to Battleship!\n");
	printf("Displayed below is your playing board, ships are represented by the number 1: \n");
	printBoard(p2Board);
	printf("Player 2 please enter the width location of your 1x5 ship: ");
	scanf("%d", &wcoord);
	printf("Player 2 please enter the depth location of your 1x5 ship: ");
	scanf("%d", &dcoord);
	if((wcoord<=9 && wcoord>=0) && (dcoord<=9 && dcoord>=0)){
		place1x5(dcoord, wcoord, p2Board);
	}
	else{
		printf("This set of co-ordinates is invalid.\n");
		return 0;
	}
	printf("Player 2 please enter the width location of your 1x3 ship: ");
	scanf("%d", &wcoord);
	printf("Player 2 please enter the depth location of your 1x3 ship: ");
	scanf("%d", &dcoord);
	if((wcoord<=9 && wcoord>=0) && (dcoord<=9 && dcoord>=0) && p2Board[dcoord][wcoord]!=1){
		place1x3(dcoord, wcoord, p2Board);
		}
	else{
		printf("This set of co-ordinates is invalid.\n");
		return 0;
	}
	printf("Player 2 please enter the width location of your 1x4 ship: ");
	scanf("%d", &wcoord);
	printf("Player 2 please enter the depth location of your 1x4 ship: ");
	scanf("%d", &dcoord);
	if((wcoord<=9 && wcoord>=0) && (dcoord<=9 && dcoord>=0) && p2Board[dcoord][wcoord]!=1){
		place1x4(dcoord, wcoord, p2Board);
		}
	else{
		printf("This set of co-ordinates is invalid.\n");
		return 0;
	}

	printf("Please press the enter key to begin the game!\n");
	getchar();
	if(getchar() == '\n'){
		system("clear");
	}

	int p1Hits=0,p2Hits=0;
	printf("Each player will take turns guessing a co-ordinate where the other player's ship may be.\nA successful guess will be counted as a hit represented by \"H\" on the game board.\nAn unsuccessful guess will be marked as \"X\" on the game board.\nThe first player to sink all three ships of the other player wins!\n\n");
	printf("Displayed below is the game board.\n");
	printGameBoard(gameBoard1);

	while(p1Hits!=12 && p2Hits!=12){
		printf("Player 1 it is your turn to guess!\nPlayer 1 please enter the width location for your guess: ");
		scanf("%d", &wcoord);
		printf("Player 1 please enter the depth location for your guess: ");
		scanf("%d", &dcoord);
		if((wcoord<=9 && wcoord>=0) && (dcoord<=9 && dcoord>=0)){
			if(p2Board[dcoord][wcoord]==1){
				gameBoard1[dcoord][wcoord] = 'H';
				p1Hits++;
				printGameBoard(gameBoard1);
				printf("\nYou scored a hit!\n");
			}
			else{
				gameBoard1[dcoord][wcoord] = 'X';
				printGameBoard(gameBoard1);
				printf("\nYou missed!\n");
			}
		}
		else{
		printf("This set of co-ordinates is invalid and your turn will be skipped.\n");
		}

		printf("Player 2 it is your turn to guess!\nPlayer 2 please enter the width location for your guess: ");
		scanf("%d", &wcoord);
		printf("Player 2 please enter the depth location for your guess: ");
		scanf("%d", &dcoord);
		if((wcoord<=9 && wcoord>=0) && (dcoord<=9 && dcoord>=0)){
			if(p1Board[dcoord][wcoord]==1){
				gameBoard2[dcoord][wcoord] = 'H';
				p2Hits++;
				printGameBoard(gameBoard2);
				printf("\nYou scored a hit!\n");
			}
			else{
				gameBoard2[dcoord][wcoord] = 'X';
				printGameBoard(gameBoard2);
				printf("\nYou missed!\n");
			}
		}
		else{
		printf("This set of co-ordinates is invalid and your turn will be skipped.\n");
		}
	}
	if(p1Hits==12){
		printf("Congratulations Player 1, you won the game!\n");
	}
	else{
		printf("Congratulations Player 2, you won the game!\n");
	}
	return 0;
}


void place1x5(int x, int y, int board[10][10])
{
	int j, orient, n=0, e=0, s=0, w=0; //n,e,s,t are used to check if the loops were run
	printf("Please select the orientation of the ship from the following list:\n");
	if((x-5)>=-1){
		for(j=0;j<5;j++){
			if(j==0){
				printf("1. NORTH ");
				n++;
			}
			printf("%d,%d ", y, x-j);
		}
		printf("\n");
	}
	if((y-5)>=-1){
		for(j=0;j<5;j++){
			if(j==0){
				printf("2. WEST ");
				w++;
			}
			printf("%d,%d ", y-j, x);
		}
		printf("\n");
	}
	if((x+5)<=10){
		for(j=0;j<5;j++){
			if(j==0){
				printf("3. SOUTH ");
				s++;
			}
			printf("%d,%d ", y, x+j);
		}
		printf("\n");
	}
	if((y+5)<=10){
		for(j=0;j<5;j++){
			if(j==0){
				printf("4. EAST ");
				e++;
			}
			printf("%d,%d ", y+j, x);
		}
		printf("\n");
	}
	int i;
	printf("NOTE: NORTH corresponds to 1, WEST corresponds to 2, SOUTH corresponds to 3, and EAST corresponds to 4.\nPlease enter the number of your choice: ");
	scanf("%d", &orient);
	if(orient==1 && n==1){
	    for(i=0;i<5;i++){
	    	board[x-i][y]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==2 && w==1){
		for(i=0;i<5;i++){
	    	board[x][y-i]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==3 && s==1){
		for(i=0;i<5;i++){
	    	board[x+i][y]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==4 && e==1){
		for(i=0;i<5;i++){
	    	board[x][y+i]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else{
		printf("\nThat orientation is invalid please choose again\n\n");
		place1x5(x, y, board);
	}
}

void place1x4(int x, int y, int board[10][10])
{
	int j, orient, coord, n=0, e=0, s=0, w=0, noSpace; //n,e,s,t are used to check if the loops were run, noSpace checks if a ship is already placed
	printf("Please select the orientation of the ship from the following list:\n");
	for (j=0;j<4;j++){
		if(board[x-j][y]==1){
			noSpace = 1;
			break;
		}
	}
	if((x-4)>=-1 && noSpace!=1){
		for(j=0;j<4;j++){
			if(j==0){
				printf("1. NORTH ");
				n++;
			}
			printf("%d,%d ", y, x-j);
		}
		printf("\n");
	}
	noSpace = 0;
	for (j=0;j<4;j++){
		if(board[x][y-j]==1){
			noSpace = 1;
			break;
		}
	}
	if((y-4)>=-1 && noSpace!=1){
		for(j=0;j<4;j++){
			if(j==0){
				printf("2. WEST ");
				w++;
			}
			printf("%d,%d ", y-j, x);
		}
		printf("\n");
	}
	noSpace = 0;
	for (j=0;j<4;j++){
		if((board[x+j][y])==1){
			noSpace = 1;
			break;
		}
	}
	if((x+4)<=10 && noSpace!=1){
		for(j=0;j<4;j++){
			if(j==0){
				printf("3. SOUTH ");
				s++;
			}
			printf("%d,%d ", y, x+j);
		}
		printf("\n");
	}
	noSpace = 0;
	for (j=0;j<4;j++){
		if((board[x][y+j])==1){
			noSpace = 1;
			break;
		}
	}
	if((y+4)<=10 && noSpace!=1){
		for(j=0;j<4;j++){
			if(j==0){
				printf("4. EAST ");
				e++;
			}
			printf("%d,%d ", y+j, x);	
		}
		printf("\n");
	}
	int i;
	printf("NOTE: NORTH corresponds to 1, WEST corresponds to 2, SOUTH corresponds to 3, and EAST corresponds to 4.\nPlease enter the number of your choice: ");
	scanf("%d", &orient);
	if(orient==1 && n==1){
	    for(i=0;i<4;i++){
	    	board[x-i][y]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==2 && w==1){
		for(i=0;i<4;i++){
	    	board[x][y-i]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==3 && s==1){
		for(i=0;i<4;i++){
	    	board[x+i][y]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==4 && e==1){
		for(i=0;i<4;i++){
	    	board[x][y+i]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else{
		printf("\nThat orientation is invalid please choose again\n\n");
		place1x3(x, y, board);
	}
}

void place1x3(int x, int y, int board[10][10])
{
	int j, orient, n=0, e=0, s=0, w=0, noSpace; //n,e,s,t are used to check if the loops were run, noSpace checks if a ship is already placed
	printf("Please select the orientation of the ship from the following list:\n");
	for (j=0;j<3;j++){
		if(board[x-j][y]==1){
			noSpace = 1;
			break;
		}
	}
	if((x-3)>=-1 && noSpace!=1){
		for(j=0;j<3;j++){
			if(j==0){
				printf("1. NORTH ");
				n++;
			}
			printf("%d,%d ", y, x-j);
		}
		printf("\n");
	}
	noSpace = 0;
	for (j=0;j<3;j++){
		if(board[x][y-j]==1){
			noSpace = 1;
			break;
		}
	}
	if((y-3)>=-1 && noSpace!=1){
		for(j=0;j<3;j++){
			if(j==0){
				printf("2. WEST ");
				w++;
			}
			printf("%d,%d ", y-j, x);
		}
		printf("\n");
	}
	noSpace = 0;
	for (j=0;j<3;j++){
		if((board[x+j][y])==1){
			noSpace = 1;
			break;
		}
	}
	if((x+3)<=10 && noSpace!=1){
		for(j=0;j<3;j++){
			if(j==0){
				printf("3. SOUTH ");
				s++;
			}
			printf("%d,%d ", y, x+j);
		}
		printf("\n");
	}
	noSpace = 0;
	for (j=0;j<3;j++){
		if((board[x][y+j])==1){
			noSpace = 1;
			break;
		}
	}
	if((y+3)<=10 && noSpace!=1){
		for(j=0;j<3;j++){
			if(j==0){
				printf("4. EAST ");
				e++;
			}
			printf("%d,%d ", y+j, x);	
		}
		printf("\n");
	}
	int i;
	printf("NOTE: NORTH corresponds to 1, WEST corresponds to 2, SOUTH corresponds to 3, and EAST corresponds to 4.\nPlease enter the number of your choice: ");
	scanf("%d", &orient);
	if(orient==1 && n==1){
	    for(i=0;i<3;i++){
	    	board[x-i][y]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==2 && w==1){
		for(i=0;i<3;i++){
	    	board[x][y-i]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==3 && s==1){
		for(i=0;i<3;i++){
	    	board[x+i][y]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else if(orient==4 && e==1){
		for(i=0;i<3;i++){
	    	board[x][y+i]=1;
		}
		printf("\n");
		printBoard(board);
	}
	else{
		printf("\nThat orientation is invalid please choose again\n\n");
		place1x3(x, y, board);
	}
}
	
void printBoard(int board[10][10])
{                                          
	int i, j, k;
	int coords[10]={0,1,2,3,4,5,6,7,8,9};
	printf("\n");
	for(i=0; i<10; i++){
		if (i==0){
			for(k=0; k<10; k++){
				if (k==0){
					printf(" ");
				}
				printf(" ");
				printf("%d", coords[k]);
			}
			printf("\n");
		}
		for(j=0; j<10; j++){
			if (j==0){
				printf("%d", coords[i]);
				printf(" ");
			}
			printf("%d", board[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

void printGameBoard(char board[10][10])
{                                          
	int i, j, k;
	int coords[10]={0,1,2,3,4,5,6,7,8,9};
	printf("\n");
	for(i=0; i<10; i++){
		if (i==0){
			for(k=0; k<10; k++){
				if (k==0){
					printf(" ");
				}
				printf(" ");
				printf("%d", coords[k]);
			}
			printf("\n");
		}
		for(j=0; j<10; j++){
			if (j==0){
				printf("%d", coords[i]);
				printf(" ");
			}
			printf("%c", board[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}