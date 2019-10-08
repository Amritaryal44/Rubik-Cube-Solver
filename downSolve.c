#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
//defining cells of each face
char F[3][3],U[3][3],R[3][3],L[3][3],D[3][3],B[3][3];
char fTemp[3][3],rTemp[3][3],lTemp[3][3],uTemp[3][3],dTemp[3][3],bTemp[3][3];

void downCheck(char *k);
void downSolve();
void dEdge(char LR);
void dDEdge(char LR);
int n; //used in downsolve function to check whether up corners contains down cells

void dEdge(char LR)
{
    if (LR=='R')
    {
        rotateFace("uc");
        printf("Rotate up clockwise i.e. UP[<-]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("rc");
        printf("Rotate right clockwise i.e. RIGHT[^]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e. up[->]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("ra");
        printf("Rotate right anticlockwise i.e. RIGHT[v]\n");
    }
    else if (LR=='L')
    {
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e. UP[->]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("la");
        printf("Rotate left anticlockwise i.e. LEFT[^]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("uc");
        printf("Rotate up clockwise i.e. UP[<-]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("lc");
        printf("Rotate left clockwise i.e. LEFT[v]\n");
    }
}
void dDEdge(char LR)
{
    if (LR=='L')
    {
        rotateFace("la");
        printf("Rotate left anticlockwise i.e. LEFT[^]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("uc");
        printf("Rotate up clockwise i.e. UP[<-]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("lc");
        printf("Rotate left clockwise i.e. LEFT[v]\n");
    }
    else if (LR=='R')
    {
        rotateFace("rc");
        printf("Rotate right clockwise i.e. RIGHT[^]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("ua");
        printf("Rotate up anticlockwise i.e. UP[->]\n");
        getche();
        system("cls");
        show3d();
        rotateFace("ra");
        printf("Rotate RIGHT anticlockwise i.e. RIGHT[v]\n");
    }
}
///down portion is solved or not checking...
void downCheck(char *k)
{
    char XChk;
    crossChk(&XChk);
    if (XChk=='D')
    {
        if ((R[2][2]==R[1][1]) && (B[2][0]==B[1][1]) && (D[2][2]=D[1][1]) && (R[2][0]==R[1][1]) && (F[2][2]==F[1][1]) && (D[0][2]=D[1][1]) && (B[2][2]==B[1][1]) && (L[2][0]==L[1][1]) && (D[2][0]=D[1][1]) && (L[2][2]==L[1][1]) && (F[2][0]==F[1][1]) && (D[0][0]=D[1][1]))
        {
            *k='Y';
        }
        else
        {
            *k='N';
        }
    }
}
void downSolve()
{
    n=0;
    char dSlvChk;
    downCheck(&dSlvChk);
    if (F[0][2]==D[1][1] && U[2][2]==F[1][1] && R[0][0]==R[1][1])
    {
        dEdge('R');
        return;
    }else
    {
        n++;
    }
    if (F[0][0]==D[1][1] && U[2][0]==F[1][1] && L[0][2]==L[1][1])
    {
        dEdge('L');
        return;
    }else
    {
        n++;
    }
    if (R[0][0]==D[1][1] && F[0][2]==F[1][1] && U[2][2]==R[1][1])
    {
        showFace('R');
        printf("Bring right face to front\n");
        return;
    }else
    {
        n++;
    }
    if (R[0][2]==D[1][1] && U[0][2]==R[1][1] && B[0][0]==B[1][1])
    {
        showFace('R');
        printf("Bring right face to front\n");
        return;
    }else
    {
        n++;
    }
    if (B[0][0]==D[1][1] && U[0][2]==B[1][1] && R[0][2]==R[1][1])
    {
        showFace('B');
        printf("Bring back face to front\n");
        return;
    }else
    {
        n++;
    }
    if (B[0][2]==D[1][1] && U[0][0]==B[1][1] && L[0][0]==L[1][1])
    {
        showFace('B');
        printf("Bring back face to front\n");
        return;
    }else
    {
        n++;
    }
    if (L[0][0]==D[1][1] && U[0][0]==L[1][1] && B[0][2]==B[1][1])
    {
        showFace('L');
        printf("Bring left face to front\n");
        return;
    }else
    {
        n++;
    }
    if (L[0][2]==D[1][1] && U[2][0]==L[1][1] && F[0][0]==F[1][1])
    {
        showFace('L');
        printf("Bring left face to front\n");
        return;
    }else
    {
        n++;
    }
    if (n==8)   //means there is no any upRight or upLeft corners containing white color (except upper case)...
    {
        if (F[0][0]==D[1][1])
        {
            if (R[1][1]==U[2][0])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
            }
            else if (B[1][1]==U[2][0])
            {
                rotateFace("ua");
                rotateFace("ua");
                printf("Rotate up anticlockwise two times i.e. UP[->] x2");
            }
            else if (L[1][1]==U[2][0])
            {
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
            }
            return;
        }
        if (F[0][2]==D[1][1])
        {
            if (R[1][1]==U[2][2])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
            }
            else if (B[1][1]==U[2][2])
            {
                rotateFace("ua");
                rotateFace("ua");
                printf("Rotate up anticlockwise two times i.e. UP[->] x2");
            }
            else if (L[1][1]==U[2][2])
            {
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
            }
            return;
        }
        if (R[0][0]==D[1][1])
        {
            if (B[1][1]==U[2][2])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
            }
            else if (L[1][1]==U[2][2])
            {
                rotateFace("ua");
                rotateFace("ua");
                printf("Rotate up anticlockwise two times i.e. UP[->] x2");
            }
            else if (F[1][1]==U[2][2])
            {
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
            }
            return;
        }
        if (R[0][2]==D[1][1])
        {
            if (B[1][1]==U[0][2])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
            }
            else if (L[1][1]==U[0][2])
            {
                rotateFace("ua");
                rotateFace("ua");
                printf("Rotate up anticlockwise two times i.e. UP[->] x2");
            }
            else if (F[1][1]==U[0][2])
            {
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
            }
            return;
        }
        if (L[0][0]==D[1][1])
        {
            if (F[1][1]==U[0][0])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
            }
            else if (R[1][1]==U[0][0])
            {
                rotateFace("ua");
                rotateFace("ua");
                printf("Rotate up anticlockwise two times i.e. UP[->] x2");
            }
            else if (B[1][1]==U[0][0])
            {
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
            }
            return;
        }
        if (L[0][2]==D[1][1])
        {
            if (F[1][1]==U[2][0])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
            }
            else if (R[1][1]==U[2][0])
            {
                rotateFace("ua");
                rotateFace("ua");
                printf("Rotate up anticlockwise two times i.e. UP[->] x2");
            }
            else if (B[1][1]==U[2][0])
            {
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
            }
            return;
        }
        if (B[0][0]==D[1][1])
        {
            if (L[1][1]==U[0][2])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
            }
            else if (F[1][1]==U[0][2])
            {
                rotateFace("ua");
                rotateFace("ua");
                printf("Rotate up anticlockwise two times i.e. UP[->] x2");
            }
            else if (R[1][1]==U[0][2])
            {
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
            }
            return;
        }
        if (B[0][2]==D[1][1])
        {
            if (L[1][1]==U[0][0])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
            }
            else if (F[1][1]==U[0][0])
            {
                rotateFace("ua");
                rotateFace("ua");
                printf("Rotate up anticlockwise two times i.e. UP[->] x2");
            }
            else if (R[1][1]==U[0][0])
            {
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
            }
            return;
        }
        /// End of solving up corner edges for downSolve
        /// Start of solving down corner edges for downSolve
        if ((F[2][0]==D[1][1]) || ((D[0][0]==D[1][1]) && (F[2][0]!=F[1][1]) && (L[2][2]!=L[1][1])))
        {
            dDEdge('L');
            return;
        }
        if ((F[2][2]==D[1][1]) || ((D[0][2]==D[1][1]) && (F[2][2]!=F[1][1]) && (R[2][0]!=R[1][1])))
        {
            dDEdge('R');
            return;
        }
        if (R[2][0]==D[1][1])
        {
            showFace('R');
            printf("Bring right face to front.");
            return;
        }
        if (R[2][2]==D[1][1])
        {
            showFace('R');
            printf("Bring right face to front.");
            return;
        }
        if (L[2][0]==D[1][1])
        {
            showFace('L');
            printf("Bring left face to front.");
            return;
        }
        if (L[2][2]==D[1][1])
        {
            showFace('L');
            printf("Bring left face to front.");
            return;
        }
        if ((B[2][0]==D[1][1]) || ((D[2][2]==D[1][1]) && (B[2][0]!=B[1][1]) && (R[2][2]!=R[1][1])))
        {
            showFace('B');
            printf("Bring back face to front.");
            return;
        }
        if ((B[2][2]==D[1][1]) || ((D[2][0]==D[1][1]) && (B[2][2]!=B[1][1]) && (L[2][0]!=L[1][1])))
        {
            showFace('B');
            printf("Bring back face to front.");
            return;
        }
        /// End of solving down corner edges for downSolve
        /// Start of solving up corner edges containing down cell in Upper part
        if (U[2][0]==D[1][1])
        {
            if (D[0][0]!=D[1][1])
            {
                rotateFace("la");
                printf("Rotate left anticlockwise i.e. LEFT[^]");
                getche();
                system("cls");
                show3d();
                rotateFace("uc");
                printf("Rotate up clockwise i.e. UP[<-]");
                getche();
                system("cls");
                show3d();
                rotateFace("lc");
                printf("Rotate left clockwise i.e. LEFT[v]");
            }
            else if (D[0][0]==D[1][1])
            {
                if (D[0][2]!=D[1][1])
                {
                    rotateFace("ua");
                    printf("Rotate up anticlockwise i.e. UP[->]");
                }else if (D[2][2]!=D[1][1])
                {
                    rotateFace("ua");
                    rotateFace("ua");
                    printf("Rotate up anticlockwise two times i.e. UP[->] x2");
                }else if (D[2][0]!=D[1][1])
                {
                    rotateFace("uc");
                    printf("Rotate up clockwise i.e. UP[<-]");
                }
            }
            return;
        }
        if (U[2][2]==D[1][1])
        {
            if (D[0][2]!=D[1][1])
            {
                rotateFace("rc");
                printf("Rotate right clockwise i.e. RIGHT[^]");
                getche();
                system("cls");
                show3d();
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]");
                getche();
                system("cls");
                show3d();
                rotateFace("ra");
                printf("Rotate right anticlockwise i.e. RIGHT[v]");
            }
            else if (D[0][2]==D[1][1])
            {
                if (D[0][0]!=D[1][1])
                {
                    rotateFace("uc");
                    printf("Rotate up clockwise i.e. UP[<-]");
                }else if (D[2][0]!=D[1][1])
                {
                    rotateFace("uc");
                    rotateFace("uc");
                    printf("Rotate up clockwise two times i.e. UP[<-] x2");
                }else if (D[2][2]!=D[1][1])
                {
                    rotateFace("ua");
                    printf("Rotate up anticlockwise i.e. UP[->]");
                }
            }
            return;
        }
        if (U[0][2]==D[1][1] || U[0][0]==D[1][1])
        {
            showFace('B');
            printf("Bring back face to front.");
        }
    }
}
