#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//defining cells of each face
char F[3][3],U[3][3],R[3][3],L[3][3],D[3][3],B[3][3];
char fTemp[3][3],rTemp[3][3],lTemp[3][3],uTemp[3][3],dTemp[3][3],bTemp[3][3];

void upXChk(char *k);
void uXClrChk(char *k);
void uXSolve();
void xAlg();
void uXclrMatch();
void xClrAlg(char OA);

void uXClrChk(char *k)
{
    if ((F[0][1]==F[1][1]) && (R[0][1]==R[1][1]) && (B[0][1]==B[1][1]) && (L[0][1]==L[1][1]))
    {
        *k='Y';
    }else
    {
        *k='N';
    }
}

void xClrAlg(char OA)
{
    printf("Rotate right clockwise i.e. Right[^]\n");
    rotateFace("rc");
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
    printf("Rotate up clockwise two times i.e. UP[<-] x2\n");
    rotateFace("uc");
    rotateFace("uc");
    getche();
    system("cls");
    show3d();
    printf("Rotate right anticlockwise i.e. RIGHT[v]\n");
    rotateFace("ra");
    getche();
    system("cls");
    show3d();
    if (OA=='A')
    {
        printf("Rotate up clockwise i.e. UP[<-]\n");
        rotateFace("uc");
    }
}

void xAlg()
{
    printf("Rotate front clockwise i.e. FRONT[->]\n");
    rotateFace("fc");
    getche();
    system("cls");
    show3d();
    printf("Rotate right clockwise i.e. RIGHT[^]\n");
    rotateFace("rc");
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
    printf("Rotate front anticlockwise i.e. FRONT[<-]\n");
    rotateFace("fa");
}

void upXChk(char *k)
{
    int n=0,i,j;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            if ((i+j)%2==1)
            {
                if (U[i][j]==U[1][1])
                    {
                        n++;
                    }
            }
        }
    }
    if (n==4)
    {
        *k='Y';
    }else
    {
        *k='N';
    }
}
void uXSolve()
{
    if ((U[1][0]==U[1][1]) && (U[1][2]==U[1][1]))
    {
        xAlg();
        return;
    }
    if ((U[0][1]==U[1][1]) && (U[2][1]==U[1][1]))
    {
        showFace('R');
        printf("Bring right face to front.");
        return;
    }
    if ((U[0][1]==U[1][1]) && (U[1][0]==U[1][1]))
    {
        xAlg();
        return;
    }
    if ((U[0][1]==U[1][1] && U[1][2]==U[1][1]))
    {
        showFace('L');
        printf("Bring left face to front.");
        return;
    }
    if ((U[1][0]==U[1][1] && U[2][1]==U[1][1]))
    {
        showFace('R');
        printf("Bring right face to front.");
        return;
    }
    if ((U[1][2]==U[1][1] && U[2][1]==U[1][1]))
    {
        showFace('B');
        printf("Bring back face to front.");
        return;
    }
    xAlg();
    return;
}

void uXclrMatch()
{
    if ((R[0][1]==R[1][1]) && (B[0][1]==B[1][1]))
    {
        xClrAlg('A');
        return;
    }
    if ((F[0][1]==F[1][1]) && (R[0][1]==R[1][1]))
    {
        showFace('L');
        printf("Bring left face to front.");
        return;
    }
    if ((F[0][1]==F[1][1]) && (L[0][1]==L[1][1]))
    {
        showFace('B');
        printf("Bring back face to front.");
        return;
    }
    if ((B[0][1]==B[1][1]) && (L[0][1]==L[1][1]))
    {
        showFace('R');
        printf("Bring right face to front.");
        return;
    }
    /// Complete of checking if alternative color matches

    if ((F[0][1]==F[1][1])&& (B[0][1]==B[1][1]))
    {
        xClrAlg('O');
        return;
    }
    if ((R[0][1]==R[1][1])&& (L[0][1]==L[1][1]))
    {
        xClrAlg('O');
        return;
    }
    /// end of checking whether alternative color do not occur
    if ((F[0][1]==R[1][1]) && (L[0][1]==F[1][1]))
    {
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->]");
        return;
    }else if ((F[0][1]==L[1][1]) && (L[0][1]==B[1][1]))
    {
        rotateFace("uc");
        printf("Rotate up clockwise i.e UP[<-]");
        return;
    }else if ((F[0][1]==B[1][1]) && (L[0][1]==R[1][1]))
    {
        rotateFace("ua");
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->] x2");
        return;
    }
    if ((F[0][1]==R[1][1]) && (R[0][1]==B[1][1]))
    {
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->]");
        return;
    }else if ((F[0][1]==L[1][1]) && (R[0][1]==F[1][1]))
    {
        rotateFace("uc");
        printf("Rotate up clockwise i.e UP[<-]");
        return;
    }else if ((F[0][1]==B[1][1]) && (R[0][1]==L[1][1]))
    {
        rotateFace("ua");
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->] x2");
        return;
    }
    if ((R[0][1]==B[1][1]) && (B[0][1]==L[1][1]))
    {
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->]");
        return;
    }else if ((R[0][1]==F[1][1]) && (B[0][1]==R[1][1]))
    {
        rotateFace("uc");
        printf("Rotate up clockwise i.e UP[<-]");
        return;
    }else if ((R[0][1]==L[1][1]) && (B[0][1]==F[1][1]))
    {
        rotateFace("ua");
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->] x2");
        return;
    }
    if ((B[0][1]==L[1][1]) && (L[0][1]==F[1][1]))
    {
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->]");
        return;
    }else if ((B[0][1]==R[1][1]) && (L[0][1]==B[1][1]))
    {
        rotateFace("uc");
        printf("Rotate up clockwise i.e UP[<-]");
        return;
    }else if ((B[0][1]==F[1][1]) && (L[0][1]==R[1][1]))
    {
        rotateFace("ua");
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->] x2");
        return;
    }
    /// complete of rotation and match of colors
}

