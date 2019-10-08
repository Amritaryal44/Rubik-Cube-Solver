#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//defining cells of each face
char F[3][3],U[3][3],R[3][3],L[3][3],D[3][3],B[3][3];
char fTemp[3][3],rTemp[3][3],lTemp[3][3],uTemp[3][3],dTemp[3][3],bTemp[3][3];

//functions here
void mEdgeErr(char LR);
void mEdge();
void midChk(char *k);
void midSolve();

void mEdgeErr(char LR)
{
    if (LR=='L')
    {
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
        printf("Rotate left clockwise i.e. LEFT[v]\n");
        rotateFace("lc");
        getche();
        system("cls");
        show3d();
        printf("Bring left face to front.");
        showFace('L');
        getche();
        system("cls");
        show3d();
        dEdge('R');
    }
    else if (LR=='R')
    {
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
        printf("Rotate RIGHT anticlockwise i.e. RIGHT[v]\n");
        rotateFace("ra");
        getche();
        system("cls");
        show3d();
        printf("Bring Right face to front.");
        showFace('R');
        getche();
        system("cls");
        show3d();
        dEdge('L');
    }
}

void mEdge()
{
    if (U[2][1]==R[1][1])
    {
        rotateFace("uc");
        printf("Rotate up clockwise i.e UP[<-]");
        getche();
        system("cls");
        show3d();
        rotateFace("rc");
        printf("Rotate right clockwise i.e RIGHT[^]");
        getche();
        system("cls");
        show3d();
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->]");
        getche();
        system("cls");
        show3d();
        rotateFace("ra");
        printf("Rotate right anticlockwise i.e RIGHT[v]");
        getche();
        system("cls");
        show3d();
        showFace('R');
        printf("Bring right face to front");
        getche();
        system("cls");
        show3d();
        dEdge('L');
    }else if (U[2][1]==L[1][1])
    {
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e UP[->]");
        getche();
        system("cls");
        show3d();
        rotateFace("la");
        printf("Rotate left anticlockwise i.e LEFT[^]");
        getche();
        system("cls");
        show3d();
        rotateFace("uc");
        printf("Rotate up clockwise i.e UP[<-]");
        getche();
        system("cls");
        show3d();
        rotateFace("lc");
        printf("Rotate left clockwise i.e LEFT[v]");
        getche();
        system("cls");
        show3d();
        showFace('L');
        printf("Bring left face to front");
        getche();
        system("cls");
        show3d();
        dEdge('R');
    }
}

void midChk(char *k)
{
    if (F[1][0]==F[1][1] && L[1][2]==L[1][1] && L[1][0]==L[1][1] && B[1][2]==B[1][1] && B[1][0]==B[1][1] && R[1][2]==R[1][1] && R[1][0]==R[1][1])
    {
        *k='Y';
    }else
    {
        *k='N';
    }
}

void midSolve()
{
    if ((F[0][1]==F[1][1]) && (U[2][1]!=U[1][1]))
    {
        mEdge();
        return;
    }
    if ((R[0][1]==R[1][1]) && (U[1][2]!=U[1][1]))
    {
        showFace('R');
        printf("Bring right face to front.");
        return;
    }
    if ((B[0][1]==B[1][1]) && (U[0][1]!=U[1][1]))
    {
        showFace('B');
        printf("Bring back face to front.");
        return;
    }
    if ((L[0][1]==L[1][1]) && (U[1][0]!=U[1][1]))
    {
        showFace('L');
        printf("Bring left face to front.");
        return;
    }
    if ((U[2][1]!=U[1][1]) && (F[0][1]!=U[1][1]))
    {
        if (F[0][1]==R[1][1])
        {
            rotateFace("ua");
            printf("Rotate up anticlockwise i.e UP[->]");
        }else if (F[0][1]==B[1][1])
        {
            rotateFace("ua");
            rotateFace("ua");
            printf("Rotate up anticlockwise two times i.e UP[->] x2");
        }else if (F[0][1]==L[1][1])
        {
            rotateFace("uc");
            printf("Rotate up clockwise i.e UP[<-]");
        }
        return;
    }
    if ((U[1][2]!=U[1][1]) && (R[0][1]!=U[1][1]))
    {
        if (R[0][1]==B[1][1])
        {
            rotateFace("ua");
            printf("Rotate up anticlockwise i.e UP[->]");
        }else if (R[0][1]==L[1][1])
        {
            rotateFace("ua");
            rotateFace("ua");
            printf("Rotate up anticlockwise two times i.e UP[->] x2");
        }else if (R[0][1]==F[1][1])
        {
            rotateFace("uc");
            printf("Rotate up clockwise i.e UP[<-]");
        }
        return;
    }
    if ((U[0][1]!=U[1][1]) && (B[0][1]!=U[1][1]))
    {
        if (B[0][1]==L[1][1])
        {
            rotateFace("ua");
            printf("Rotate up anticlockwise i.e UP[->]");
        }else if (B[0][1]==F[1][1])
        {
            rotateFace("ua");
            rotateFace("ua");
            printf("Rotate up anticlockwise two times i.e UP[->] x2");
        }else if (B[0][1]==R[1][1])
        {
            rotateFace("uc");
            printf("Rotate up clockwise i.e UP[<-]");
        }
        return;
    }
    if ((U[1][0]!=U[1][1]) && (L[0][1]!=U[1][1]))
    {
        if (L[0][1]==F[1][1])
        {
            rotateFace("ua");
            printf("Rotate up anticlockwise i.e UP[->]");
        }else if (L[0][1]==R[1][1])
        {
            rotateFace("ua");
            rotateFace("ua");
            printf("Rotate up anticlockwise two times i.e UP[->] x2");
        }else if (L[0][1]==B[1][1])
        {
            rotateFace("uc");
            printf("Rotate up clockwise i.e UP[<-]");
        }
        return;
    }
    if ((F[1][0]!=U[1][1]) && (L[1][2]!=U[1][1]) && (F[1][0]!=F[1][1]) && (L[1][2]!=L[1][1]))
    {
        mEdgeErr('L');
        return;
    }
    if ((F[1][2]!=U[1][1]) && (R[1][0]!=U[1][1]) && (F[1][2]!=F[1][1]) && (R[1][0]!=R[1][1]))
    {
        mEdgeErr('R');
        return;
    }
    if ((B[1][0]!=U[1][1]) && (R[1][2]!=U[1][1]) && (B[1][0]!=B[1][1]) && (R[1][2]!=R[1][1]))
    {
        showFace('B');
        printf("Bring back face to front.");
        getche();
        system("cls");
        show3d();
        dDEdge('L');
        getche();
        system("cls");
        show3d();
        showFace('L');
        printf("Bring left face to front.");
        getche();
        system("cls");
        show3d();
        dEdge('R');
        return;
    }
    if ((B[1][2]!=U[1][1]) && (L[1][0]!=U[1][1]) && (B[1][2]!=B[1][1]) && (L[1][0]!=L[1][1]))
    {
        showFace('B');
        printf("Bring back face to front.");
        getche();
        system("cls");
        show3d();
        dDEdge('R');
        getche();
        system("cls");
        show3d();
        showFace('R');
        printf("Bring right face to front.");
        getche();
        system("cls");
        show3d();
        dEdge('L');
        return;
    }
}
