#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char AirportCode[4];
typedef struct NodeTag{
	AirportCode	Airport;
	struct NodeTag *Link;
}NodeType;
NodeType *L, *M, *N;

void InsertNewFirstNode(char* A, NodeType **L);
void DeleteFirst(NodeType **L);
void InsertNode(NodeType *N, NodeType *M, NodeType *L);
NodeType Copy(NodeType *L);
void Reverse(NodeType **L);
void PrintList(NodeType *L);

int main(void){
	M = (NodeType *)malloc(sizeof(NodeType));
	strcpy(M->Airport, "YYZ");
	M->Link=NULL;

	AirportCode A = "AUS";
	InsertNewFirstNode(A, &L);
	AirportCode B = "BRA";
	InsertNewFirstNode(B, &L);
	AirportCode C = "CAS";
	InsertNewFirstNode(C, &L);
	DeleteFirst(&L);
	N=L;
	InsertNode(N, M, L);
	PrintList(L);
	Reverse(&L);
	PrintList(L);
	return 0;
}

void InsertNewFirstNode(char* A, NodeType **L){
	NodeType *X;
	X = (NodeType *)malloc(sizeof(NodeType));

	strcpy(X->Airport, A);
	if(*L==NULL){
		X->Link = NULL;
		*L = X;
	}
	else{
		X->Link = *L;
		*L = X;
	}
}

void DeleteFirst(NodeType **L){
	if(*L!=NULL){
		if((*L)->Link==NULL){
			free(*L);
			*L=NULL;
		}
		else{
			NodeType *X;
			X=*L;
			*L= (*L)->Link;
			free(X);
		}
	}
}

void InsertNode(NodeType *N, NodeType *M, NodeType *L){
	NodeType *X, *Y;
	AirportCode temp;
	X=L;
	Y=L;
	while(X->Link!= N->Link){
		X = X->Link;
		Y = Y->Link;
	}
	X = X->Link;
	Y->Link = M;
	strcpy(temp, Y->Airport);
	strcpy(Y->Airport, M->Airport);
	Y=Y->Link;
	strcpy(Y->Airport, temp);
	Y->Link = X;
}

NodeType Copy(NodeType *L){
	NodeType *copylist;
	copylist = L;
	return *copylist;
}

void Reverse(NodeType **L){
	NodeType *X, *Y, *Z;
	X = *L;
	Y = NULL;
	Z = NULL;
	while(X!= NULL){
		Y = X->Link;
		X->Link = Z;
		Z = X;
		X = Y;
	}
	*L = Z;
}

void PrintList(NodeType *L){
	NodeType *X;
	printf("(");
	X=L;
	while(X!=NULL){
		printf("%s", X->Airport);
		X = X->Link;
		if(X!=NULL){
			printf(", ");
		}
	}
	printf(")");
}





