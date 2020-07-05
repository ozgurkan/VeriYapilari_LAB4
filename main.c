#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#define N 11
    /*Asýl matrisimiz 9x9 köþelerdeki elemanlarýn 4 komþusu
    olmasý için 11x11 lik matris oluþturduk.
    */

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


int  DFS(char matris1[N][N],int X,int Y);
void PrintMatrix(char matris1[N][N]);

char matris2[N][N];
int i,j;

int main() {
    system("Color F0");
     char matris[N][N] = {
         '0','0','0','0','0','0','0','0','0','0','0',
         '0','B','0','B','1','B','0','B','1','B','0',
         '0','1','0','1','0','0','0','1','0','1','0',
         '0','B','1','B','0','B','1','B','0','B','0',
         '0','0','0','1','0','1','0','0','0','1','0',
         '0','B','0','B','1','B','0','B','1','B','0',
         '0','1','0','0','0','0','0','1','0','0','0',
         '0','B','1','B','1','B','0','B','0','B','0',
         '0','0','0','1','0','1','0','1','0','0','0',
         '0','B','1','B','1','B','1','B','1','B','0',
         '0','0','0','0','0','0','0','0','0','0','0',
         };


        char matris1[N][N] = {
         '0','0','0','0','0','0','0','0','0','0','0',
         '0','B','0','B','1','B','0','B','1','B','0',
         '0','1','0','1','0','0','0','1','0','1','0',
         '0','B','1','B','0','B','1','B','0','B','0',
         '0','0','0','1','0','1','0','0','0','1','0',
         '0','B','0','B','1','B','0','B','1','B','0',
         '0','1','0','0','0','0','0','1','0','0','0',
         '0','B','1','B','1','B','0','B','0','B','0',
         '0','0','0','1','0','1','0','1','0','0','0',
         '0','B','1','B','1','B','1','B','1','B','0',
         '0','0','0','0','0','0','0','0','0','0','0',
         };



/*EKRANA YAZDIRMA MATRSÝ VE LABÝRENT ÞEKLÝNDE*/
      for(i=0;i<N;i++){
            /*MATRÝSÝ YAZDIRMA*/
            printf("\t\t");
            printf(GREEN);
            for(j=0;j<N;j++){
                printf( "%c ",matris[i][j]);
            }
            printf(RESET);
            printf("\t\t");

            /*YANINA LABÝRENTÝ YAZDIRMA*/
            printf(BOLDBLUE);
            for(j=0;j<N;j++){
               if(i%2==0 && j%2==0 && matris[i][j]=='0'){
                printf("+ ");
               }
               else if(i%2==0 && j%2!=0 && matris[i][j]=='0'){
                printf("- ");
               }
                else if(i%2!=0 && j%2==0 && matris[i][j]=='0'){
                printf("| ");
               }
               else if(i==1 && j==1 && matris[i][j]=='B'){;
                printf(RED"* "RESET);
                printf(BOLDBLUE);
               }
               else if(i==N-2 && j==N-2){;
                printf(RED"X "RESET);
                printf(BOLDBLUE);
               }
               else {
                 printf("  ");
               }
            }
             printf(RESET);
           printf("\n");
    }

    DFS(matris1,1,1);// DFS FONKSÝYON YOLLARI BULMAK ÝÇÝN ÇAÐIRILDI VE YEDEK MATRÝS GÖNDERÝLDÝ.

    if(matris2[N-2][N-2]!='9'){
        printf("\n\t\t Bu matrisin cikisi yoktur.....\n\n");
    }else{
        /*SONUÇ LABÝRENTÝ EKRANA YAZDIRILDI.*/
        printf("\n");
        for(i=0;i<N;i++){
                printf("\t\t");
            for(j=0;j<N;j++){
               if(i%2==0 && j%2==0 && matris[i][j]=='0'){
                printf("+ ");
               }
                else if(i%2==0 && j%2!=0 && matris[i][j]=='0'){
                printf("- ");
               }
                else if(i%2!=0 && j%2==0 && matris[i][j]=='0'){
                printf("| ");
               }
                else if(i==1 && j==1 && matris[i][j]=='B'){
                printf(BOLDRED"* "RESET);
               }
                else if(matris2[i][j]=='9' && matris[i][j]=='B'){
                printf(BOLDRED);
                printf("I ");
                printf(RESET);
               }
                else if(matris[i][j]=='X'){;
                printf(BOLDRED"X "RESET);
               }
                else {
                 printf("  ");
               }
            }
            printf("\n");
        }
    }
}

void PrintMatrix(char matris1[N][N]){
    printf("\n");
     for(i=0;i<N;i++){
         printf("\t\t");
        for(j=0;j<N;j++){

                if(matris1[i][j]=='9'){
                    printf(BOLDRED);
                        printf("%c ",matris1[i][j]);
                    printf(RESET);
                }
                else if(matris1[i][j]=='T'){
                    printf(BOLDMAGENTA);
                        printf("%c ",matris1[i][j]);
                    printf(RESET);
                }
                else{
                printf("%c ",matris1[i][j]);
                }
        }
           printf("\n");
    }
    printf("\n");
}



int DFS(char matris1[N][N],int X,int Y){
    printf("\n \t \t X=%d Y=%d ",X,Y);

    if(X!=N-2 || Y!=N-2){
            //KUZEY
            if(matris1[X-1][Y]!='9' && matris1[X-1][Y]!='0'){
            matris1[X][Y]='9';
            PrintMatrix(matris1);
            DFS(matris1,X-1,Y);
            }
    //DOÐU
            if(matris1[X][Y+1]!='9' && matris1[X][Y+1]!='0'){
            matris1[X][Y]='9';
            PrintMatrix(matris1);
            DFS(matris1,X,Y+1);
            }
        //GÜNEY
            if( matris1[X+1][Y]!='9' && matris1[X+1][Y]!='0'){
            matris1[X][Y]='9';
            PrintMatrix(matris1);
            DFS(matris1,X+1,Y);
            }


        //BATI
            if(matris1[X][Y-1]!='9' && matris1[X][Y-1]!='0'){
            matris1[X][Y]='9';
            PrintMatrix(matris1);
            DFS(matris1,X,Y-1);
            }
            matris1[X][Y]='T';//ÇIKMAZ YOLLAR T OLARAK ÝÞARETLENDÝ.

    }
    else {
        printf("cikis bulundu.");
        matris1[X][Y]='9';
        PrintMatrix(matris1);
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
              matris2[i][j]=matris1[i][j];
              matris1[i][j]='9';
            }
        }
    }
}

