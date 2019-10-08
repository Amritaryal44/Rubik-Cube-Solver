#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


//function building for rotation
void clkRot(char cell[3][3],char cellTemp[3][3]);
void anticlkRot(char cell[3][3],char cellTemp[3][3]);
void rotateFace(char face[10]);
void showFace(char faceSide);
void showCube(char faceSide);

//defining cells of each face
char F[3][3],U[3][3],R[3][3],L[3][3],D[3][3],B[3][3];
char fTemp[3][3],rTemp[3][3],lTemp[3][3],uTemp[3][3],dTemp[3][3],bTemp[3][3];

void clkRot(char cell[3][3],char cellTemp[3][3])
{
    int X,Y,y1;
    for (Y=0;Y<=2;Y++)
    {
        y1=0;
        for (X=2;X>=0;X--)
        {
            cell[Y][y1]=cellTemp[X][Y];
            y1++;
        }
    }
    return;
}

void anticlkRot(char cell[3][3],char cellTemp[3][3])
{
    int X,Y,y1;
    for (Y=2;Y>=0;Y--)
    {
        y1=0;
        for (X=0;X<=2;X++)
        {
            cell[2-Y][y1]=cellTemp[X][Y];
            y1++;
        }
    }
    return;
}

void rotateFace(char face[10])
{
    int i,j;
    //setting temporary data of cube
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            uTemp[i][j]=U[i][j];
            rTemp[i][j]=R[i][j];
            lTemp[i][j]=L[i][j];
            dTemp[i][j]=D[i][j];
            bTemp[i][j]=B[i][j];
            fTemp[i][j]=F[i][j];
        }
    }

    //checking what rotation command is used
    if (strcmp(face,"ua")==0)
    {
        for (i=0;i<=2;i++)
        {
            F[0][i]=lTemp[0][i];
            L[0][i]=bTemp[0][i];
            B[0][i]=rTemp[0][i];
            R[0][i]=fTemp[0][i];
        }
        anticlkRot(U,uTemp);
    }
    else if (strcmp(face,"uc")==0)
    {
        for (i=0;i<=2;i++)
        {
            F[0][i]=rTemp[0][i];
            R[0][i]=bTemp[0][i];
            B[0][i]=lTemp[0][i];
            L[0][i]=fTemp[0][i];
        }
        clkRot(U,uTemp);
    }
    else if (strcmp(face,"dc")==0)
    {
        for (i=0;i<=2;i++)
        {
            F[2][i]=lTemp[2][i];
            L[2][i]=bTemp[2][i];
            B[2][i]=rTemp[2][i];
            R[2][i]=fTemp[2][i];
        }
        clkRot(D,dTemp);
    }
    else if (strcmp(face,"da")==0)
    {
        for (i=0;i<=2;i++)
        {
            F[2][i]=rTemp[2][i];
            R[2][i]=bTemp[2][i];
            B[2][i]=lTemp[2][i];
            L[2][i]=fTemp[2][i];
        }
        anticlkRot(D,dTemp);
    }
    else if (strcmp(face,"ra")==0)
    {
        j=2;
        for (i=0;i<=2;i++)
        {
            F[i][2]=uTemp[i][2];
            U[i][2]=bTemp[j][0];
            B[i][0]=dTemp[j][2];
            D[i][2]=fTemp[i][2];
            j--;
        }
        anticlkRot(R,rTemp);
    }
    else if (strcmp(face,"rc")==0)
    {
        j=2;
        for (i=0;i<=2;i++)
        {
            F[i][2]=dTemp[i][2];
            D[i][2]=bTemp[j][0];
            B[i][0]=uTemp[j][2];
            U[i][2]=fTemp[i][2];
            j--;
        }
        clkRot(R,rTemp);
    }
    else if (strcmp(face,"la")==0)
    {
        j=2;
        for (i=0;i<=2;i++)
        {
            F[i][0]=dTemp[i][0];
            D[i][0]=bTemp[j][2];
            B[i][2]=uTemp[j][0];
            U[i][0]=fTemp[i][0];
            j--;
        }
        anticlkRot(L,lTemp);
    }
    else if (strcmp(face,"lc")==0)
    {
        j=2;
        for (i=0;i<=2;i++)
        {
            F[i][0]=uTemp[i][0];
            U[i][0]=bTemp[j][2];
            B[i][2]=dTemp[j][0];
            D[i][0]=fTemp[i][0];
            j--;
        }
        clkRot(L,lTemp);
    }
    else if (strcmp(face,"fc")==0)
    {
        j=2;
        for (i=0;i<=2;i++)
        {
            U[2][i]=lTemp[j][2];
            L[i][2]=dTemp[0][i];
            D[0][i]=rTemp[j][0];
            R[i][0]=uTemp[2][i];
            j--;
        }
        clkRot(F,fTemp);
    }
    else if (strcmp(face,"fa")==0)
    {
        j=2;
        for (i=0;i<=2;i++)
        {
            U[2][i]=rTemp[i][0];
            R[i][0]=dTemp[0][j];
            D[0][i]=lTemp[i][2];
            L[i][2]=uTemp[2][j];
            j--;
        }
        anticlkRot(F,fTemp);
    }
    else if (strcmp(face,"mha")==0)
    {
        for (i=0;i<=2;i++)
        {
            F[1][i]=lTemp[1][i];
            R[1][i]=fTemp[1][i];
            B[1][i]=rTemp[1][i];
            L[1][i]=bTemp[1][i];
        }
    }
    else if (strcmp(face,"mhc")==0)
    {
        for (i=0;i<=2;i++)
        {
            F[1][i]=rTemp[1][i];
            R[1][i]=bTemp[1][i];
            B[1][i]=lTemp[1][i];
            L[1][i]=fTemp[1][i];
        }
    }
    else if (strcmp(face,"mva")==0)
    {
        j=2;
        for (i=0;i<=2;i++)
        {
            F[i][1]=uTemp[i][1];
            D[i][1]=fTemp[i][1];
            B[i][1]=dTemp[j][1];
            U[i][1]=bTemp[j][1];
            j--;
        }
    }
    else if (strcmp(face,"mvc")==0)
    {
        j=2;
        for (i=0;i<=2;i++)
        {
            F[i][1]=dTemp[i][i];
            D[i][1]=bTemp[j][i];
            B[i][1]=uTemp[j][i];
            U[i][1]=fTemp[i][1];
            j--;
        }
    }
    return;
}

//showing face side
void showFace(char faceSide)
{
    switch(faceSide)
    {
    case 'R':
        rotateFace("uc");
        rotateFace("mhc");
        rotateFace("da");
        break;
    case 'L':
        rotateFace("ua");
        rotateFace("mha");
        rotateFace("dc");
        break;
    case 'B':
        rotateFace("ua");
        rotateFace("mha");
        rotateFace("dc");
        rotateFace("ua");
        rotateFace("mha");
        rotateFace("dc");
        break;
    case 'U':
        rotateFace("ra");
        rotateFace("mva");
        rotateFace("lc");
        break;
    case 'D':
        rotateFace("rc");
        rotateFace("mvc");
        rotateFace("la");
        break;

    }
    return;
}
void showCube(char faceSide)
{
    if (faceSide == 'F')
    {
        //showing face up
        printf("\t\t\t\t\tFRONT FACE : \t\t      UP\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",F[0][0],F[0][1],F[0][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\tLEFT\t| %c | %c | %c |\tRIGHT\n",F[1][0],F[1][1],F[1][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",F[2][0],F[2][1],F[2][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\n\t\t\t\t\t\t\t\t     DOWN    \n");
    }else if (faceSide == 'L')
    {
        //showing face up
        printf("\t\t\t\t\tLEFT FACE : \t\t      UP\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",L[0][0],L[0][1],L[0][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\tBACK\t| %c | %c | %c |\tFRONT\n",L[1][0],L[1][1],L[1][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",L[2][0],L[2][1],L[2][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\n\t\t\t\t\t\t\t\t     DOWN    \n");
    }
    else if (faceSide == 'R')
    {
        //showing face up
        printf("\t\t\t\t\tRIGHT FACE : \t\t      UP\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",R[0][0],R[0][1],R[0][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\tFRONT\t| %c | %c | %c |\tBACK\n",R[1][0],R[1][1],R[1][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",R[2][0],R[2][1],R[2][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\n\t\t\t\t\t\t\t\t     DOWN    \n");
    }
    else if (faceSide == 'B')
    {
        //showing face up
        printf("\t\t\t\t\tBACK FACE : \t\t      UP\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",B[0][0],B[0][1],B[0][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\tRIGHT\t| %c | %c | %c |\tLEFT\n",B[1][0],B[1][1],B[1][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",B[2][0],B[2][1],B[2][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\n\t\t\t\t\t\t\t\t     DOWN    \n");
    }
    else if (faceSide == 'D')
    {
        //showing face up
        printf("\t\t\t\t\tDOWN FACE : \t\t      FRONT\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",D[0][0],D[0][1],D[0][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\tLEFT\t| %c | %c | %c |\tRIGHT\n",D[1][0],D[1][1],D[1][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",D[2][0],D[2][1],D[2][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\n\t\t\t\t\t\t\t\t     BACK    \n");
    }
    else if (faceSide == 'U')
    {
        //showing face up
        printf("\t\t\t\t\t  UP FACE : \t\t      BACK\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",U[0][0],U[0][1],U[0][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\tLEFT\t| %c | %c | %c |\tRIGHT\n",U[1][0],U[1][1],U[1][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\t\t\t\t\t\t\t\t| %c | %c | %c |\n",U[2][0],U[2][1],U[2][2]);
        printf("\t\t\t\t\t\t\t\t-------------\n");
        printf("\n\t\t\t\t\t\t\t\t     FRONT   \n");
    }
}

