#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>

int peg1[9];
int peg2[9]; 
int peg3[9];

void display_pegs(){
     int * pegs[3] = {peg1, peg2, peg3};
     int row;
     int i;
     int disc_size;
     int peg_num;
     
     for (row = 8; row >= 0; row --){
          
          for (peg_num = 0; peg_num <= 2; peg_num ++){
          
               disc_size = pegs[peg_num][row];
               
               // Print the spaces
               i = 0;
               for( i = 0; i < (10-disc_size); i++){
                    printf(" ");
               }
               
               // Print the +
               i = 0;
               for ( i = 0; i < disc_size; i++){
                    printf("+");
               }

               printf("|");

               // Print the +
               i = 0;
               for ( i = 0; i < disc_size; i++){
                    printf("+");
               }

               // Print the spaces
               i = 0;
               for( i = 0; i < (10-disc_size); i++){
                    printf(" ");               
               }
               
               // Print the extra spaces
               for( i = 0; i <= 4; i++){
                    printf(" ");
               }
          }
     printf("\n");
     }

int j;
int k;
int l;
     // Printing the base
     for ( j = 0; j <= 2; j++){

          for (k=0; k <= 20; k++){
          printf("X");
          }
          
          for (l = 0; l <= 4; l++){
          printf(" ");
          }
     }
     printf("\n\n\n");
}


void init(int nod, int pegA[9], int pegB[9], int pegC[9]){

int j;

for (j = 0; j < 9; j++){
     pegA[j] = 0;
     pegB[j] = 0;
     pegC[j] = 0;
}
     int i;
     int temp = nod;
     for (i =0; i < temp; i++){
          pegA[i] = nod;
          nod--;
     }
} 


void move(int pego[9], int pegd[9]){     // moves top disk of pegA to pegB

     int temp;
     int i;
     int j;

     for ( i = 8; i >= 0; i --){

          if(pego[i] != 0){
               temp = pego[i];
               pego[i] = 0;
               break;
          }
     }

     for (j = 0; j <= 8; j++){

          if ( pegd[j] == 0){
               pegd[j] = temp;
               break;
          }
     }
     display_pegs();
     sleep(1);
}


void hantow(int nod, int pegA[9], int pegB[9], int pegC[9]){

     if (nod > 1){
     hantow(nod-1, pegA, pegC, pegB);
     }
     
     move(pegA, pegB);
     
     if (nod > 1){
     hantow(nod-1, pegC, pegB, pegA);
     }
}

int main(int argc, char* argv[]){

     if (argc != 2){
          printf("Incorrect number of arguments\n");
     }
     
     if(strlen(argv[1]) != 1){
          printf("argument must be a single char 1-9\n");
          return 0;
     }

     if (argv[1][0] >= '1' && argv[1][0] <= '9'){
     
          int nod = ((int)(argv[1][0] - '0'));
          
          printf("number of disks: %d\n", nod);
          init(nod, peg1, peg2, peg3);
          display_pegs();
          sleep(1);     
          hantow(nod, peg1, peg2, peg3);
          printf("done\n");

     }
     else{
          printf("Incorrect argument\n");
          return 0;
     }
     return 0;
}


