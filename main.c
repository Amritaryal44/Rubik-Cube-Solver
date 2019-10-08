#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

//functions to be called
void askColor();
void solveCube();
void splash();
void fullscreen();
void chkAskBug(int *k);

//defining cells of each face
char F[3][3],U[3][3],R[3][3],L[3][3],D[3][3],B[3][3];
char fTemp[3][3],rTemp[3][3],lTemp[3][3],uTemp[3][3],dTemp[3][3],bTemp[3][3];

void fullscreen()
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void splash()
{
    ///Animation at beginning
    printf("\n\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*     RRRRR  U   U  BBBBB  IIIII C   C  ||  SSSSS     *\n");
    printf("\t\t\t\t*     R   R  U   U  B   B    I   C  C   ||  S         *\n");
    printf("\t\t\t\t*     RRRRR  U   U  BBBBB    I   CCC        SSSSS     *\n");
    printf("\t\t\t\t*     R RR   U   U  B   B    I   C  C           S     *\n");
    printf("\t\t\t\t*     R  RR  UUUUU  BBBBB  IIIII C   C      SSSSS     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*     CCCCC  U   U  BBBBB  EEEEE                      *\n");
    printf("\t\t\t\t*     C      U   U  B   B  E                          *\n");
    printf("\t\t\t\t*     C      U   U  BBBBB  EEEEE                      *\n");
    printf("\t\t\t\t*     C      U   U  B   B  E                          *\n");
    printf("\t\t\t\t*     CCCCC  UUUUU  BBBBB  EEEEE                      *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*     SSSSS  OOOOO  L      V     V  EEEEE  RRRRR      *\n");
    printf("\t\t\t\t*     S      O   O  L       V   V   E      R   R      *\n");
    printf("\t\t\t\t*     SSSSS  O   O  L       V   V   EEEEE  RRRRR      *\n");
    printf("\t\t\t\t*         S  O   O  L        V V    E      R RR       *\n");
    printf("\t\t\t\t*     SSSSS  OOOOO  LLLLL     V     EEEEE  R  RR      *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(2000);
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*     CREDIT GOES TO :                                *\n");
    printf("\t\t\t\t*     >AMRIT ARYAL                                    *\n");
    printf("\t\t\t\t*     >BASANTA GYAWALI                                *\n");
    printf("\t\t\t\t*     >Nishant Neupane                                *\n");
    printf("\t\t\t\t*     >Kamal Ayer                                     *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(2000);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*      BBBBB Y   Y      CCCCC                         *\n");
    printf("\t\t\t\t*      B   B  Y Y       C                             *\n");
    printf("\t\t\t\t*      BBBBB   Y        C                             *\n");
    printf("\t\t\t\t*      B   B   Y        C                             *\n");
    printf("\t\t\t\t*      BBBBB   Y        CCCCC                         *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*     BBBBB Y   Y      CCCCC                          *\n");
    printf("\t\t\t\t*     B   B  Y Y       C                              *\n");
    printf("\t\t\t\t*     BBBBB   Y        C                              *\n");
    printf("\t\t\t\t*     B   B   Y        C                              *\n");
    printf("\t\t\t\t*     BBBBB   Y        CCCCC                          *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*    BBBBB Y   Y      CCCCC                           *\n");
    printf("\t\t\t\t*    B   B  Y Y       C                               *\n");
    printf("\t\t\t\t*    BBBBB   Y        C                               *\n");
    printf("\t\t\t\t*    B   B   Y        C                               *\n");
    printf("\t\t\t\t*    BBBBB   Y        CCCCC                           *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*   BBBBB Y   Y      CCCCC                            *\n");
    printf("\t\t\t\t*   B   B  Y Y       C                                *\n");
    printf("\t\t\t\t*   BBBBB   Y        C                                *\n");
    printf("\t\t\t\t*   B   B   Y        C                                *\n");
    printf("\t\t\t\t*   BBBBB   Y        CCCCC                            *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*  BBBBB Y   Y      CCCCC                             *\n");
    printf("\t\t\t\t*  B   B  Y Y       C                                 *\n");
    printf("\t\t\t\t*  BBBBB   Y        C                                 *\n");
    printf("\t\t\t\t*  B   B   Y        C                                 *\n");
    printf("\t\t\t\t*  BBBBB   Y        CCCCC                             *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t* BBBBB Y   Y      CCCCC                              *\n");
    printf("\t\t\t\t* B   B  Y Y       C                                  *\n");
    printf("\t\t\t\t* BBBBB   Y        C                                  *\n");
    printf("\t\t\t\t* B   B   Y        C                                  *\n");
    printf("\t\t\t\t* BBBBB   Y        CCCCC                              *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*BBBBB Y   Y      CCCCC                               *\n");
    printf("\t\t\t\t*B   B  Y Y       C                                   *\n");
    printf("\t\t\t\t*BBBBB   Y        C                                   *\n");
    printf("\t\t\t\t*B   B   Y        C                                   *\n");
    printf("\t\t\t\t*BBBBB   Y        CCCCC                               *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*BBBB Y   Y      CCCCC                                *\n");
    printf("\t\t\t\t*   B  Y Y       C                                    *\n");
    printf("\t\t\t\t*BBBB   Y        C                                    *\n");
    printf("\t\t\t\t*   B   Y        C                                    *\n");
    printf("\t\t\t\t*BBBB   Y        CCCCC                                *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*BBB Y   Y      CCCCC                                 *\n");
    printf("\t\t\t\t*  B  Y Y       C                                     *\n");
    printf("\t\t\t\t*BBB   Y        C                                     *\n");
    printf("\t\t\t\t*  B   Y        C                                     *\n");
    printf("\t\t\t\t*BBB   Y        CCCCC                                 *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*BB Y   Y      CCCCC                                  *\n");
    printf("\t\t\t\t* B  Y Y       C                                      *\n");
    printf("\t\t\t\t*BB   Y        C                                      *\n");
    printf("\t\t\t\t* B   Y        C                                      *\n");
    printf("\t\t\t\t*BB   Y        CCCCC                                  *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*B Y   Y      CCCCC                                   *\n");
    printf("\t\t\t\t*B  Y Y       C                                       *\n");
    printf("\t\t\t\t*B   Y        C                                       *\n");
    printf("\t\t\t\t*B   Y        C                                       *\n");
    printf("\t\t\t\t*B   Y        CCCCC                                   *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*Y   Y      CCCCC                                     *\n");
    printf("\t\t\t\t* Y Y       C                                         *\n");
    printf("\t\t\t\t*  Y        C                                         *\n");
    printf("\t\t\t\t*  Y        C                                         *\n");
    printf("\t\t\t\t*  Y        CCCCC                                     *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*   Y      CCCCC                                      *\n");
    printf("\t\t\t\t*Y Y       C                                          *\n");
    printf("\t\t\t\t* Y        C                                          *\n");
    printf("\t\t\t\t* Y        C                                          *\n");
    printf("\t\t\t\t* Y        CCCCC                                      *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*  Y      CCCCC                                       *\n");
    printf("\t\t\t\t* Y       C                                           *\n");
    printf("\t\t\t\t*Y        C                                           *\n");
    printf("\t\t\t\t*Y        C                                           *\n");
    printf("\t\t\t\t*Y        CCCCC                                       *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t* Y      CCCCC                                        *\n");
    printf("\t\t\t\t*Y       C                                            *\n");
    printf("\t\t\t\t*        C                                            *\n");
    printf("\t\t\t\t*        C                                            *\n");
    printf("\t\t\t\t*        CCCCC                                        *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*Y      CCCCC                                         *\n");
    printf("\t\t\t\t*       C                                             *\n");
    printf("\t\t\t\t*       C                                             *\n");
    printf("\t\t\t\t*       C                                             *\n");
    printf("\t\t\t\t*       CCCCC                                         *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*      CCCCC                                          *\n");
    printf("\t\t\t\t*      C                                              *\n");
    printf("\t\t\t\t*      C                                              *\n");
    printf("\t\t\t\t*      C                                              *\n");
    printf("\t\t\t\t*      CCCCC                                          *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*     CCCCC                                           *\n");
    printf("\t\t\t\t*     C                                               *\n");
    printf("\t\t\t\t*     C                                               *\n");
    printf("\t\t\t\t*     C                                               *\n");
    printf("\t\t\t\t*     CCCCC                                           *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*    CCCCC                                            *\n");
    printf("\t\t\t\t*    C                                                *\n");
    printf("\t\t\t\t*    C                                                *\n");
    printf("\t\t\t\t*    C                                                *\n");
    printf("\t\t\t\t*    CCCCC                                            *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*   CCCCC                                             *\n");
    printf("\t\t\t\t*   C                                                 *\n");
    printf("\t\t\t\t*   C                                                 *\n");
    printf("\t\t\t\t*   C                                                 *\n");
    printf("\t\t\t\t*   CCCCC                                             *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*  CCCCC                                              *\n");
    printf("\t\t\t\t*  C                                                  *\n");
    printf("\t\t\t\t*  C                                                  *\n");
    printf("\t\t\t\t*  C                                                  *\n");
    printf("\t\t\t\t*  CCCCC                                              *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t* CCCCC                                               *\n");
    printf("\t\t\t\t* C                                                   *\n");
    printf("\t\t\t\t* C                                                   *\n");
    printf("\t\t\t\t* C                                                   *\n");
    printf("\t\t\t\t* CCCCC                                               *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*CCCCC                                                *\n");
    printf("\t\t\t\t*C                                                    *\n");
    printf("\t\t\t\t*C                                                    *\n");
    printf("\t\t\t\t*C                                                    *\n");
    printf("\t\t\t\t*CCCCC                                                *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*CCCC                                                 *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*CCCC                                                 *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*CCC                                                  *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*CCC                                                  *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*CC                                                   *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*CC                                                   *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*C                                                    *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*C                                                    *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    Sleep(30);
    system("cls");
    /// End of Animation splash
}

void askColor()
{
    char arrayFace[6]={'F','D','R','L','B','U'};
    int arrCnt=0,i=0,j=0,cellNumber=1;
    char cellColor,nextLine;
    while(arrCnt<=5)
    {
        nextLine='N';
        switch (arrayFace[arrCnt])
        {
        case 'F':
            while (toupper(nextLine)!='Y')
            {
                while (i<=2)
                {
                    while (j<=2)
                    {
                        system("cls");
                        showCube('F');
                        printf("Note : Use 'R' for Red\n");
                        printf("       Use 'Y' for Yellow and so on...\n\n");
                        printf("Enter color for %d : ",cellNumber);
                        cellColor=getche();
                        if (cellColor=='\b')
                        {
                            if (cellNumber>1)
                            {
                                if (cellNumber%3==1)
                                {
                                    i--;
                                    j=3;
                                }
                                cellNumber--;
                                j--;
                            }
                            F[i][j]=cellNumber+'0';
                        }
                        else
                        {
                            F[i][j]=toupper(cellColor);
                            cellNumber++;
                            j++;
                        }
                    }
                    i++;
                    j=0;
                }
                    cellNumber=1;
                    system("cls");
                    showCube('F');
                    printf("Do you want to go to next face? [Y/N]");
                    nextLine=getche();
                    if (toupper(nextLine)=='N')
                    {
                        i=2;
                        j=2;
                        cellNumber=9;
                        F[i][j]='9';
                    }
            }
            cellNumber=1;
            break;
        case 'D':
            i=0;
            j=0;
            while (toupper(nextLine)!='Y')
            {
                while (i<=2)
                {
                    while (j<=2)
                    {
                        system("cls");
                        showCube('D');
                        printf("Note : Use 'R' for Red\n");
                        printf("       Use 'Y' for Yellow and so on...\n\n");
                        printf("Enter color for %d : ",cellNumber);
                        cellColor=getche();
                        if (cellColor=='\b')
                        {
                            if (cellNumber>1)
                            {
                                if (cellNumber%3==1)
                                {
                                    i--;
                                    j=3;
                                }
                                cellNumber--;
                                j--;
                            }
                            D[i][j]=cellNumber+'0';
                        }
                        else
                        {
                            D[i][j]=toupper(cellColor);
                            cellNumber++;
                            j++;
                        }
                    }
                    i++;
                    j=0;
                }
                    cellNumber=1;
                    system("cls");
                    showCube('D');
                    printf("Do you want to go to next face? [Y/N]");
                    nextLine=getche();
                    if (toupper(nextLine)=='N')
                    {
                        i=2;
                        j=2;
                        cellNumber=9;
                        D[i][j]='9';
                    }
            }
            cellNumber=1;
            break;
        case 'R':
            i=0;
            j=0;
            while (toupper(nextLine)!='Y')
            {
                while (i<=2)
                {
                    while (j<=2)
                    {
                        system("cls");
                        showCube('R');
                        printf("Note : Use 'R' for Red\n");
                        printf("       Use 'Y' for Yellow and so on...\n\n");
                        printf("Enter color for %d : ",cellNumber);
                        cellColor=getche();
                        if (cellColor=='\b')
                        {
                            if (cellNumber>1)
                            {
                                if (cellNumber%3==1)
                                {
                                    i--;
                                    j=3;
                                }
                                cellNumber--;
                                j--;
                            }
                            R[i][j]=cellNumber+'0';
                        }
                        else
                        {
                            R[i][j]=toupper(cellColor);
                            cellNumber++;
                            j++;
                        }
                    }
                    i++;
                    j=0;
                }
                    cellNumber=1;
                    system("cls");
                    showCube('R');
                    printf("Do you want to go to next face? [Y/N]");
                    nextLine=getche();
                    if (toupper(nextLine)=='N')
                    {
                        i=2;
                        j=2;
                        cellNumber=9;
                        R[i][j]='9';
                    }
            }
            cellNumber=1;
            break;
         case 'L':
            i=0;
            j=0;
            while (toupper(nextLine)!='Y')
            {
                while (i<=2)
                {
                    while (j<=2)
                    {
                        system("cls");
                        showCube('L');
                        printf("Note : Use 'R' for Red\n");
                        printf("       Use 'Y' for Yellow and so on...\n\n");
                        printf("Enter color for %d : ",cellNumber);
                        cellColor=getche();
                        if (cellColor=='\b')
                        {
                            if (cellNumber>1)
                            {
                                if (cellNumber%3==1)
                                {
                                    i--;
                                    j=3;
                                }
                                cellNumber--;
                                j--;
                            }
                            L[i][j]=cellNumber+'0';
                        }
                        else
                        {
                            L[i][j]=toupper(cellColor);
                            cellNumber++;
                            j++;
                        }
                    }
                    i++;
                    j=0;
                }
                    cellNumber=1;
                    system("cls");
                    showCube('L');
                    printf("Do you want to go to next face? [Y/N]");
                    nextLine=getche();
                    if (toupper(nextLine)=='N')
                    {
                        i=2;
                        j=2;
                        cellNumber=9;
                        L[i][j]='9';
                    }
            }
            cellNumber=1;
            break;
         case 'B':
            i=0;
            j=0;
            while (toupper(nextLine)!='Y')
            {
                while (i<=2)
                {
                    while (j<=2)
                    {
                        system("cls");
                        showCube('B');
                        printf("Note : Use 'R' for Red\n");
                        printf("       Use 'Y' for Yellow and so on...\n\n");
                        printf("Enter color for %d : ",cellNumber);
                        cellColor=getche();
                        if (cellColor=='\b')
                        {
                            if (cellNumber>1)
                            {
                                if (cellNumber%3==1)
                                {
                                    i--;
                                    j=3;
                                }
                                cellNumber--;
                                j--;
                            }
                            B[i][j]=cellNumber+'0';
                        }
                        else
                        {
                            B[i][j]=toupper(cellColor);
                            cellNumber++;
                            j++;
                        }
                    }
                    i++;
                    j=0;
                }
                    cellNumber=1;
                    system("cls");
                    showCube('B');
                    printf("Do you want to go to next face? [Y/N]");
                    nextLine=getche();
                    if (toupper(nextLine)=='N')
                    {
                        i=2;
                        j=2;
                        cellNumber=9;
                        B[i][j]='9';
                    }
            }
            cellNumber=1;
            break;
         case 'U':
            i=0;
            j=0;
            while (toupper(nextLine)!='Y')
            {
                while (i<=2)
                {
                    while (j<=2)
                    {
                        system("cls");
                        showCube('U');
                        printf("Note : Use 'R' for Red\n");
                        printf("       Use 'Y' for Yellow and so on...\n\n");
                        printf("Enter color for %d : ",cellNumber);
                        cellColor=getche();
                        if (cellColor=='\b')
                        {
                            if (cellNumber>1)
                            {
                                if (cellNumber%3==1)
                                {
                                    i--;
                                    j=3;
                                }
                                cellNumber--;
                                j--;
                            }
                            U[i][j]=cellNumber+'0';
                        }
                        else
                        {
                            U[i][j]=toupper(cellColor);
                            cellNumber++;
                            j++;
                        }
                    }
                    i++;
                    j=0;
                }
                    cellNumber=1;
                    system("cls");
                    showCube('U');
                    printf("COMPLETE OF INPUT. WANT TO GO TO NEXT STEP? [Y/N]");
                    nextLine=getche();
                    if (toupper(nextLine)=='N')
                    {
                        i=2;
                        j=2;
                        cellNumber=9;
                        U[i][j]='9';
                    }
            }
            cellNumber=1;
            break;
        }
        arrCnt++;
    }
}

void chkAskBug(int *k)
{
    int i,j,c=0,n=0,m=0;
    char fcArray[6]={'B','W','R','O','G','Y'};
    while (n!=6)
    {
        for (i=0;i<=2;i++)
        {
            for (j=0;j<=2;j++)
            {
                if (F[i][j]==fcArray[n])
                {
                    c++;
                }
                if (D[i][j]==fcArray[n])
                {
                    c++;
                }
                if (R[i][j]==fcArray[n])
                {
                    c++;
                }
                if (L[i][j]==fcArray[n])
                {
                    c++;
                }
                if (B[i][j]==fcArray[n])
                {
                    c++;
                }
                if (U[i][j]==fcArray[n])
                {
                    c++;
                }
            }
        }
        if (c==9)
        {
            m++;
        }
        n++;
        c=0;
    }
    *k=m;
}

void solveCube()
{
    /* ----- Cross solving ----- */
    ///checking for cross in other face and bringing it to down
    char XChk;
    crossChk(&XChk);
    show3d();
    if (XChk=='F')
    {
        showFace('U');
        XChk='D';
        printf("Bring Front face to Down.");
        getche();
    }
    else if (XChk=='L')
    {
        showFace('L');
        showFace('U');
        XChk='D';
        printf("Bring Left face to Down.");
        getche();
    }
    else if (XChk=='R')
    {
        showFace('R');
        showFace('U');
        XChk='D';
        printf("Bring Right face to Down.");
        getche();
    }
    else if (XChk=='B')
    {
        showFace('D');
        XChk='D';
        printf("Bring Back face to Down.");
        getche();
    }
    else if (XChk=='B')
    {
        showFace('D');
        XChk='D';
        printf("Bring Up face to Down.");
        getche();
    }
    system("cls");
    while(XChk!='D')
    {
        show3d();
        crossSolve();
        crossChk(&XChk);
        getche();
        system("cls");
    }

    /* -- down Solving codes -- */
    char dSlvChk;
    downCheck(&dSlvChk);
    while(dSlvChk!='Y')
    {
        show3d();
        downSolve();
        downCheck(&dSlvChk);
        getche();
        system("cls");
    }

    /* -- middle Solving codes -- */
    char mSlvChk;
    midChk(&mSlvChk);
    while(mSlvChk!='Y')
    {
        show3d();
        midSolve();
        midChk(&mSlvChk);
        getche();
        system("cls");
    }

    /* -- up cross only Solving codes -- */
    char uXChk;
    upXChk(&uXChk);
    while(uXChk!='Y')
    {
        show3d();
        uXSolve();
        upXChk(&uXChk);
        getche();
        system("cls");
    }

    /* -- up cross with color match Solving codes -- */
    char uClrChk;
    uXClrChk(&uClrChk);
    while(uClrChk!='Y')
    {
        show3d();
        uXclrMatch();
        uXClrChk(&uClrChk);
        getche();
        system("cls");
    }

    /* -- up corner with position match Solving codes -- */
    char uPosChk;
    chkuEdge(&uPosChk);
    while(uPosChk!='A')
    {
        show3d();
        uEPosMatch();
        chkuEdge(&uPosChk);
        getche();
        system("cls");
    }
    system("cls");

    /* -- up corner with color match Solving codes -- */
    char uClrMChk;
    chkuEClr(&uClrMChk);
    while(uClrMChk!='Y')
    {
        show3d();
        uEclrMatch();
        chkuEClr(&uClrMChk);
        getche();
        system("cls");
    }

    /* setting the upper part to its position */
    if (F[0][1]==R[1][1])
    {
        show3d();
        printf("Rotate up anticlockwise i.e. UP[->]");
        rotateFace("ua");
        getche();
        system("cls");
        show3d();
    }
    if (F[0][1]==B[1][1])
    {
        show3d();
        printf("Rotate up anticlockwise two times i.e. UP[->] x2");
        rotateFace("ua");
        rotateFace("ua");
        getche();
        system("cls");
        show3d();
    }
    if (F[0][1]==L[1][1])
    {
        show3d();
        printf("Rotate up clockwise i.e. UP[<-]");
        rotateFace("uc");
        getche();
        system("cls");
        show3d();
    }
    //end of up check

    /* setting the down part to its position */
    if (F[2][1]==R[1][1])
    {
        show3d();
        printf("Rotate down clockwise i.e. DOWN[->]");
        rotateFace("ua");
        getche();
        system("cls");
        show3d();
    }
    if (F[2][1]==B[1][1])
    {
        show3d();
        printf("Rotate down clockwise two times i.e. DOWN[->] x2");
        rotateFace("ua");
        rotateFace("ua");
        getche();
        system("cls");
        show3d();
    }
    if (F[2][1]==L[1][1])
    {
        show3d();
        printf("Rotate down anticlockwise i.e. DOWN[<-]");
        rotateFace("uc");
        getche();
        system("cls");
        show3d();
    }
    //end of down check
}

int main()
{
    fullscreen();
    int colCount,rowCount,total;

    splash();

    menu:
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*             PRESS 1 TO START SOLVING CUBE.          *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*             PRESS 2 TO GO TO HELP.                  *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*             PRESS 3 TO EXIT.                        *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    char menuAsk;
    menuAsk = getche();
    if (menuAsk == '1')
    {
        system("cls");
        goto askingAgain;
    }else if (menuAsk == '2')
    {
        system("cls");
        goto help;
    }else if (menuAsk == '3')
    {
        system("cls");
        goto exitIt;
    }else
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t\t\tINVALID INPUT.\n\t\t\t\tENTER A VALID INPUT...");
        Sleep(1000);
        system("cls");
        goto menu;
    }
    askingAgain:
    total=1;
    for (colCount=0;colCount<=2;colCount++)
    {
        for (rowCount=0;rowCount<=2;rowCount++)
        {
            F[colCount][rowCount]=total+'0';
            R[colCount][rowCount]=total+'0';
            L[colCount][rowCount]=total+'0';
            U[colCount][rowCount]=total+'0';
            D[colCount][rowCount]=total+'0';
            B[colCount][rowCount]=total+'0';
            total++;
        }
    }

    /* ----- asking user the colors of unsolved cube ----- */
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*             Do not make mistake while giving        *\n");
    printf("\t\t\t\t*             colors. Otherwise you should suffer     *\n");
    printf("\t\t\t\t*             TIME WASTE.                             *\n");
    printf("\t\t\t\t*             -------------------------               *\n");
    printf("\t\t\t\t*             PRESS ANY KEY TO CONTINUE               *\n");
    printf("\t\t\t\t*             -------------------------               *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    getche();
    askColor();
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*             Please do not change the position of    *\n");
    printf("\t\t\t\t*             cube by rotating it or however...       *\n");
    printf("\t\t\t\t*             Rotate the cube as per the command      *\n");
    printf("\t\t\t\t*             of Rubik's Cube Solver                  *\n");
    printf("\t\t\t\t*             -------------------------               *\n");
    printf("\t\t\t\t*             PRESS ANY KEY TO CONTINUE               *\n");
    printf("\t\t\t\t*             -------------------------               *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    getche();
    system("cls");
    ///Checking if any error in input
    int chkAsk=2;
    chkAskBug(&chkAsk);
    if (chkAsk!=6)
    {
        printf("\n\n\n\t\t\t\tSorry! It seems like something is wrong in your cube\n\t\t\t\tYour input might be wrong.");
        getche();
        system("cls");
        goto menu;
    }
    ///checking complete
    printf("\n\n\n");
    printf("\t\t\t\tYOUR CUBE MUST BE POSITIONED LIKE THE CUBE GIVEN BELOW : \n");
    show3d();
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*             -------------------------               *\n");
    printf("\t\t\t\t*             PRESS ANY KEY TO CONTINUE               *\n");
    printf("\t\t\t\t*             -------------------------               *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    getche();
    system("cls");
    /* ----- End of user asking activity ----- */

    /* ----- Start of solving cube ----- */
    solveCube();
    /* ----- End of solving cube ----- */
    system("cls");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*             FINALLY THE CUBE IS SOLVED.             *\n");
    printf("\t\t\t\t*   [NOTE :  If the cube is not solved, It may be     *\n");
    printf("\t\t\t\t*            because of your mistake while entering   *\n");
    printf("\t\t\t\t*            colors or while rotating the cube.       *\n");
    printf("\t\t\t\t*                                                     *\n");
    printf("\t\t\t\t*                      THANK YOU                      *\n");
    printf("\t\t\t\t*                      ---------                      *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n\n\n");
    printf("\t\t\t\tPress 1 to solve the cube again.\n");
    printf("\t\t\t\tPress 2 to return in the main menu.\n");
    char slvAgain;
    slvAgain=getche();
    if (slvAgain=='1')
    {
        goto askingAgain;
    }
    else if (slvAgain=='2')
    {
        goto exitIt;
    }
    help:
    system("help\\help.htm");
    system("cls");
    goto menu;
    exitIt:
    printf("\n\n\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t*             ---------------------------------------               *\n");
    printf("\t\t\t\t*                  PRESS Y TO EXIT                                  *\n");
    printf("\t\t\t\t*                  OR                                               *\n");
    printf("\t\t\t\t*                  PRESS N TO RETURN TO MAIN MENU                   *\n");
    printf("\t\t\t\t*             ---------------------------------------               *\n");
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    char exitOrNot;
    exitOrNot = getche();
    if (toupper(exitOrNot)=='Y')
    {
            system("cls");
            printf("\n\n\n");
            printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
            printf("\t\t\t\t*                                                                   *\n");
            printf("\t\t\t\t*                                                                   *\n");
            printf("\t\t\t\t*          Exiting...                                               *\n");
            printf("\t\t\t\t*                                                                   *\n");
            printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    }else if (toupper(exitOrNot)=='N')
    {
        system("cls");
        goto menu;
    }else
    {
        system("cls");
        printf("\n\n\t\t\t\tINVALID INPUT.\n\t\t\t\tENTER A VALID INPUT...");
        goto exitIt;
    }
}






