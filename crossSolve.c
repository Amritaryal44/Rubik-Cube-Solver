#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char crossChk(char *k);
char crossTop(char *k);
void crossSolve();
//defining cells of each face
char F[3][3],U[3][3],R[3][3],L[3][3],D[3][3],B[3][3];
char fTemp[3][3],rTemp[3][3],lTemp[3][3],uTemp[3][3],dTemp[3][3],bTemp[3][3];
char chkCrs='F';

void crossSolve()
{
    if (chkCrs!='T')
    {
        crossTop(&chkCrs);
    }
    if (chkCrs!='T')
    {
        //Down cross on top face
        ///front case
        if (F[1][0]==D[1][1])
        {
            if (U[1][0]!=D[1][1])
            {
                rotateFace("la");
                printf("Rotate left anticlockwise i.e. LEFT[^]\n");
            }
            else if (U[1][0]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (F[1][2]==D[1][1])
        {
            if (U[1][2]!=D[1][1])
            {
                rotateFace("rc");
                printf("Rotate right clockwise i.e. RIGHT[^]\n");
            }
            else if (U[1][2]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (F[0][1]==D[1][1])
        {
            if (U[2][1]!=D[1][1])
            {
                rotateFace("fc");
                printf("Rotate front clockwise i.e. FRONT[->]\n");
            }
            else if (U[2][1]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (F[2][1]==D[1][1])
        {
            if (U[2][1]!=D[1][1])
            {
                rotateFace("fc");
                printf("Rotate front clockwise i.e. FRONT[->]\n");
            }
            else if (U[2][1]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        ///Back Case
        if (B[1][0]==D[1][1])
        {
            if (U[1][2]!=D[1][1])
            {
                rotateFace("ra");
                printf("Rotate right anticlockwise i.e. RIGHT[v]\n");
            }
            else if (U[1][2]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (B[1][2]==D[1][1])
        {
            if (U[1][0]!=D[1][1])
            {
                rotateFace("lc");
                printf("Rotate left clockwise i.e. LEFT[v]\n");
            }
            else if (U[1][2]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (B[0][1]==D[1][1])
        {
            rotateFace("uc");
            rotateFace("uc");
            printf("Rotate up clockwise two times i.e. UP[<-] x2\n");
            return;
        }
        if (B[2][1]==D[1][1])
        {
            rotateFace("da");
            rotateFace("da");
            printf("Rotate down anticlockwise two times i.e. DOWN[<-] x2\n");
            return;
        }
        ///RIGHT Case
        if (R[1][0]==D[1][1])
        {
            if (U[2][1]!=D[1][1])
            {
                rotateFace("fa");
                printf("Rotate front anticlockwise i.e. FRONT[<-]\n");
            }
            else if (U[2][1]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (R[0][1]==D[1][1])
        {
            if (U[1][2]!=D[1][1])
            {
                rotateFace("ra");
                printf("Rotate right anticlockwise i.e. RIGHT[v]\n");
            }
            else if (U[1][2]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (R[2][1]==D[1][1])
        {
            if (U[1][2]!=D[1][1])
            {
                rotateFace("rc");
                printf("Rotate right clockwise i.e. RIGHT[^]\n");
            }
            else if (U[1][2]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (R[1][2]==D[1][1])
        {
            if (U[1][2]!=D[1][1])
            {
                rotateFace("rc");
                printf("Rotate right clockwise i.e. RIGHT[^]\n");
            }
            else if (U[1][2]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        ///LEFT Case
        if (L[1][2]==D[1][1])
        {
            if (U[2][1]!=D[1][1])
            {
            rotateFace("fc");
            printf("Rotate front clockwise i.e. FRONT[->]\n");
            }
            else if (U[2][1]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (L[0][1]==D[1][1])
        {
            if (U[1][0]!=D[1][1])
            {
                rotateFace("lc");
                printf("Rotate left clockwise i.e. LEFT[v]\n");
            }
            else if (U[1][0]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (L[2][1]==D[1][1])
        {
            if (U[1][0]!=D[1][1])
            {
            rotateFace("la");
            printf("Rotate left anticlockwise i.e. LEFT[^]\n");
            }
            else if (U[1][0]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (L[1][0]==D[1][1])
        {
            if (U[1][0]!=D[1][1])
            {
            rotateFace("lc");
            printf("Rotate left clockwise i.e. LEFT[v]\n");
            }
            else if (U[1][0]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        ///Down Case
        if (D[0][1]==D[1][1])
        {
            if (U[2][1]!=D[1][1])
            {
            rotateFace("fc");
            rotateFace("fc");
            printf("Rotate front clockwise two times i.e. FRONT[->] x2\n");
            }
            else if (U[2][1]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (D[1][0]==D[1][1])
        {
            if (U[1][0]!=D[1][1])
            {
            rotateFace("lc");
            rotateFace("lc");
            printf("Rotate left clockwise two times i.e. left[^] x2\n");
            }
            else if (U[1][0]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up clockwise i.e. UP[->]\n");
            }
            return;
        }
        if (D[1][2]==D[1][1])
        {
            if (U[1][2]!=D[1][1])
            {
            rotateFace("rc");
            rotateFace("rc");
            printf("Rotate right clockwise two times i.e. RIGHT[^] x2\n");
            }
            else if (U[1][2]==D[1][1])
            {
                rotateFace("ua");
                printf("Rotate up anticlockwise i.e. UP[->]\n");
            }
            return;
        }
        if (D[2][1]==D[1][1])
        {
            rotateFace("dc");
            printf("Rotate down clockwise i.e. DOWN[->]\n");
            return;
        }
    }
    else
    {
        ///check whether any cross cell matches to its adjacent side color
        if (F[0][1]==F[1][1] && U[2][1]==D[1][1])
        {
            rotateFace("fc");
            rotateFace("fc");
            printf("Rotate front clockwise two times i.e. FRONT[->] x2\n");
            return;
        }
        if (R[0][1]==R[1][1] && U[1][2]==D[1][1])
        {
            rotateFace("rc");
            rotateFace("rc");
            printf("Rotate right clockwise two times i.e. RIGHT[^] x2\n");
            return;
        }
        if (L[0][1]==L[1][1] && U[1][0]==D[1][1])
        {
            rotateFace("lc");
            rotateFace("lc");
            printf("Rotate left clockwise two times i.e. LEFT[v] x2\n");
            return;
        }
        if (B[0][1]==B[1][1] && U[0][1]==D[1][1])
        {
            showFace('B');
            printf("Bring back side of cube to front\n");
            return;
        }
        ///End of checking whether any cross cell matches to its adjacent side color
        ///bringing in right places
        //for Front
        if (R[0][1]==F[1][1] && U[1][2]==D[1][1])
        {
            rotateFace("uc");
            printf("Rotate up clockwise i.e. UP[<-]\n");
            return;
        }
        if (L[0][1]==F[1][1] && U[1][0]==D[1][1])
        {
            rotateFace("ua");
            printf("Rotate up anticlockwise i.e. UP[->]\n");
            return;
        }
        if (B[0][1]==F[1][1] && U[0][1]==D[1][1])
        {
            rotateFace("uc");
            rotateFace("uc");
            printf("Rotate up clockwise two times i.e. UP[<-] x2\n");
            return;
        }
        //for left
        if (F[0][1]==L[1][1] && U[2][1]==D[1][1])
        {
            rotateFace("uc");
            printf("Rotate up clockwise i.e. UP[<-]\n");
            return;
        }
        if (B[0][1]==L[1][1] && U[0][1]==D[1][1])
        {
            rotateFace("ua");
            printf("Rotate up anticlockwise i.e. UP[->]\n");
            return;
        }
        if (R[0][1]==L[1][1] && U[1][2]==D[1][1])
        {
            rotateFace("uc");
            rotateFace("uc");
            printf("Rotate up clockwise two times i.e. UP[<-] x2\n");
            return;
        }
        //for right
        if (B[0][1]==R[1][1] && U[0][1]==D[1][1])
        {
            rotateFace("uc");
            printf("Rotate up clockwise i.e. UP[<-]\n");
            return;
        }
        if (F[0][1]==R[1][1] && U[2][1]==D[1][1])
        {
            rotateFace("ua");
            printf("Rotate up anticlockwise i.e. UP[->]\n");
            return;
        }
        if (L[0][1]==R[1][1] && U[1][0]==D[1][1])
        {
            rotateFace("uc");
            rotateFace("uc");
            printf("Rotate up clockwise two times i.e. UP[<-] x2\n");
            return;
        }
        //for back
        if (L[0][1]==B[1][1] && U[1][0]==D[1][1])
        {
            rotateFace("uc");
            printf("Rotate up clockwise i.e. UP[<-]\n");
            return;
        }
        if (R[0][1]==B[1][1] && U[1][2]==D[1][1])
        {
            rotateFace("ua");
            printf("Rotate up anticlockwise i.e. UP[->]\n");
            return;
        }
        if (F[0][1]==B[1][1] && U[2][1]==D[1][1])
        {
            rotateFace("uc");
            rotateFace("uc");
            printf("Rotate up clockwise two times i.e. UP[<-] x2\n");
            return;
        }
    }
}

char crossChk(char *k)
{
    /* ----- Check whether cross is built already ----- */
    /* ----- Checking Front cross ----- */
    int i,j,n=0;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            if (F[i][j]==F[1][1] && (i+j)%2!=0)
            {
                n++;
            }
        }
    }
    if (n==4)
    {
        if (U[2][1]==U[1][1] && R[1][0]==R[1][1] && D[0][1]==D[1][1] && L[1][2]==L[1][1])
        {
            *k='F';
        }
    }

    /* ----- Checking Up cross ----- */
    n=0;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            if (U[i][j]==U[1][1] && (i+j)%2!=0)
            {
                n++;
            }
        }
    }
    if (n==4)
    {
        if (F[0][1]==F[1][1] && R[0][1]==R[1][1] && B[0][1]==B[1][1] && L[0][1]==L[1][1])
        {
            *k='U';
        }
    }

    /* ----- Checking Left cross ----- */
    n=0;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            if (L[i][j]==L[1][1] && (i+j)%2!=0)
            {
                n++;
            }
        }
    }
    if (n==4)
    {
        if (D[1][0]==D[1][1] && F[1][0]==F[1][1] && U[1][0]==U[1][1] && B[1][2]==B[1][1])
        {
            *k='L';
        }
    }

    /* ----- Checking Right cross ----- */
    n=0;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            if (R[i][j]==R[1][1] && (i+j)%2!=0)
            {
                n++;
            }
        }
    }
    if (n==4)
    {
        if (F[1][2]==F[1][1] && D[1][2]==D[1][1] && B[1][0]==B[1][1] && U[1][2]==U[1][1])
        {
            *k='R';
        }
    }

    /* ----- Checking Back cross ----- */
    n=0;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            if (B[i][j]==B[1][1] && (i+j)%2!=0)
            {
                n++;
            }
        }
    }
    if (n==4)
    {
        if (R[1][2]==R[1][1] && D[2][1]==D[1][1] && L[1][0]==L[1][1] && U[0][1]==U[1][1])
        {
            *k='B';
        }
    }

    /* ----- Checking Down cross ----- */
    n=0;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            if (D[i][j]==D[1][1] && (i+j)%2!=0)
            {
                n++;
            }
        }
    }
    if (n==4)
    {
        if (F[2][1]==F[1][1] && L[2][1]==L[1][1] && B[2][1]==B[1][1] && R[2][1]==R[1][1])
        {
            *k='D';
        }
    }
    /* ----- Checking cross complete ----- */
}

char crossTop(char *k)
{
    int i,j,n=0;
     for (i=0;i<=2;i++)
            {
                for (j=0;j<=2;j++)
                {
                    if (U[i][j]==D[1][1] && (i+j)%2!=0)
                    {
                        n++;
                    }
                }
            }
    if (n==4)
    {
        *k='T';
    }else
    {
        *k='F';
    }
}
