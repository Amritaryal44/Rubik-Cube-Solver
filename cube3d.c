#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//defining cells of each face
char F[3][3],U[3][3],R[3][3],L[3][3],D[3][3],B[3][3];
char fTemp[3][3],rTemp[3][3],lTemp[3][3],uTemp[3][3],dTemp[3][3],bTemp[3][3];

void show3d()
{
    printf("\n\n");
    printf("\t\t\t\t          ___________________________\n");
    printf("\t\t\t\t         /       /        /         /|\n");
    printf("\t\t\t\t        /   %c   /    %c   /     %c   / |\n",U[0][0],U[0][1],U[0][2]);
    printf("\t\t\t\t       /_______/________/_________/ %c|\n",R[0][2]);
    printf("\t\t\t\t      /       /        /         /|  |\n");
    printf("\t\t\t\t     /   %c   /   %c    /    %c    / | /|\n",U[1][0],U[1][1],U[1][2]);
    printf("\t\t\t\t    /_______/________/_________/ %c|/ |\n",R[0][1]);
    printf("\t\t\t\t   /       /        /         /|  + %c|\n",R[1][2]);
    printf("\t\t\t\t  /   %c   /    %c   /    %c    / | /|  |\n",U[2][0],U[2][1],U[2][2]);
    printf("\t\t\t\t /_______/________/_________/  |/ | /|\n");
	printf("\t\t\t\t|        |        |        | %c + %c|/ |\n",R[0][0],R[1][1]);
	printf("\t\t\t\t|        |        |        |  /|  + %c|\n",R[2][2]);
	printf("\t\t\t\t|   %c    |   %c    |   %c    | / | /|  |\n",F[0][0],F[0][1],F[0][2]);
	printf("\t\t\t\t|________+________+________|/  |/ | /\n");
	printf("\t\t\t\t|        |        |        | %c + %c|/\n",R[1][0],R[2][1]);
	printf("\t\t\t\t|        |        |        |  /|  +\n");
	printf("\t\t\t\t|   %c    |   %c    |    %c   | / | /\n",F[1][0],F[1][1],F[1][2]);
	printf("\t\t\t\t|________+________+________|/  |/\n");
	printf("\t\t\t\t|        |        |        | %c +\n",R[2][0]);
	printf("\t\t\t\t|        |        |        |  /\n");
	printf("\t\t\t\t|   %c    |   %c    |    %c   | /\n",F[2][0],F[2][1],F[2][2]);
	printf("\t\t\t\t|________+________+________|/\n");
	printf("\n###########################################################################################\n");
}
