#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char F[3][3],U[3][3],R[3][3],L[3][3],D[3][3],B[3][3];
char fTemp[3][3],rTemp[3][3],lTemp[3][3],uTemp[3][3],dTemp[3][3],bTemp[3][3];

void chkuEdge(char *k);
void uEPosMatch();
void uCrnrPos();
void uEclrMatch();
void chkuEClr(char *k);
void uClrArg();

// Functions here
void chkuEdge(char *k)
{
    char E;
    int n=0;
    if ((U[2][0]==F[1][1]) || (F[0][0]==F[1][1]) || (L[0][2]==F[1][1]))
    {
        if ((U[2][0]==L[1][1]) || (F[0][0]==L[1][1]) || (L[0][2]==L[1][1]))
        {
            n++;
            E = 'L';
        }
    }
    if (((U[2][2]==F[1][1]) || (F[0][2]==F[1][1]) || (R[0][0]==F[1][1])))
    {
        if ((U[2][2]==R[1][1]) || (F[0][2]==R[1][1]) || (R[0][0]==R[1][1]))
        {
            n++;
            E = 'R';
        }
    }
    if ((U[0][2]==B[1][1]) || (B[0][0]==B[1][1]) || (R[0][2]==B[1][1]))
    {
        if ((U[0][2]==R[1][1]) || (B[0][0]==R[1][1]) || (R[0][2]==R[1][1]))
        {
            n++;
            E = 'l';
        }
    }
    if ((U[0][0]==B[1][1]) || (B[0][2]==B[1][1]) || (L[0][0]==B[1][1]))
    {
        if ((U[0][0]==L[1][1]) || (B[0][2]==L[1][1]) || (L[0][0]==L[1][1]))
        {
            n++;
            E = 'r';
        }
    }
    if (n==4)
    {
        *k='A';
    }else
    {
        *k=E;
    }
}

void uCrnrPos()
{
    printf("Rotate up clockwise i.e. UP[<-]\n");
    rotateFace("uc");
    getche();
    system("cls");
    show3d();
    printf("Rotate right clockwise i.e. RIGHT[^]\n");
    rotateFace("rc");
    getche();
    system("cls");
    show3d();
    printf("Rotate up anticlockwise i.e. UP[->]\n");
    rotateFace("ua");
    getche();
    system("cls");
    show3d();
    printf("Rotate left anticlockwise i.e. LEFT[^]\n");
    rotateFace("la");
    getche();
    system("cls");
    show3d();
    printf("Rotate up clockwise i.e. UP[<-]\n");
    rotateFace("uc");
    getche();
    system("cls");
    show3d();
    printf("Rotate right anticlockwise i.e. RIGHT[v]\n");
    rotateFace("ra");
    getche();
    system("cls");
    show3d();
    printf("Rotate up anticlockwise i.e. UP[->]\n");
    rotateFace("ua");
    getche();
    system("cls");
    show3d();
    printf("Rotate left clockwise i.e. LEFT[v]\n");
    rotateFace("lc");
}

void uEPosMatch()
{
    char uPosChk;
    chkuEdge(&uPosChk);
    if (uPosChk=='R')
    {
        uCrnrPos();
        return;
    }
    if (uPosChk=='L')
    {
        showFace('L');
        printf("Bring left face to front.");
        return;
    }
    if (uPosChk=='l')
    {
        showFace('R');
        printf("Bring right face to front.");
        return;
    }
    if (uPosChk=='r')
    {
        showFace('B');
        printf("Bring back face to front.");
        return;
    }
    uCrnrPos();
}

void chkuEClr(char *k)
{
    int i,j,n=0;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            if (U[i][j]==U[1][1])
            {
                n++;
            }
        }
    }
    if (n==9)
    {
        *k='Y';
    }else
    {
        *k='N';
    }
}

void uClrArg()
{
    printf("Rotate right anticlockwise i.e. RIGHT[v]\n");
    rotateFace("ra");
    getche();
    system("cls");
    show3d();
    printf("Rotate down anticlockwise i.e. DOWN[<-]\n");
    rotateFace("da");
    getche();
    system("cls");
    show3d();
    printf("Rotate right clockwise i.e. RIGHT[^]\n");
    rotateFace("rc");
    getche();
    system("cls");
    show3d();
    printf("Rotate down clockwise i.e. DOWN[->]\n");
    rotateFace("dc");
}

void uEclrMatch()
{
    if (U[2][2]!=U[1][1])
    {
        uClrArg();
    }
    else
    {
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->]");
    }
    return;
}
