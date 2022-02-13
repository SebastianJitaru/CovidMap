#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define N 20


int main() 
{
    
    srand( time(NULL)); // Inicialitzar llavor.
    int x, y;
    x = rand(); y = rand(); // Nombre aleatori entre 0 i RAND_MAX
    x = x % N; y = y % N;
    printf("Coordenada aleatòria: %i, %i\n", x+1, 20-y); // Nombre aleatori entre 0 i N-1 
    
    int contador = 0, mapa[N+1][N+1] = {0}, i = 0, j = 0, z = 1;
    char caracter;
    
    scanf("%c",&caracter);
 
    for(j = 0; j <= N; j++)
    {
        for(i = 0; i <= N; i++)
        {    
            mapa[i][j] = caracter -'0'  ; 
            scanf("%c",&caracter);   
        }   
    }      
    
    if(mapa[x][y] == 1)
    {
    //printf("%i, %i\n", x, y);
    printf("hi ha '2'\n");
    mapa[x][y] = 2; 
        
        while(z+x <= 19  && mapa[x+z][y] == 1)//recta 0º
        {
            mapa[x+z][y] = 2;
            z++;
        }
        z = 1;
        while(z+y <= 19 && mapa[x][y+z] == 1)//recta -90º
        {
            mapa[x][y+z]=2;
            z++;
        }
        z=1;
        while(x-z >= 0  && mapa[x-z][y] == 1)//recta 180º
        {
        
            mapa[x-z][y] = 2;
            z++;
        }
        z=1;
        while(y-z >= 0  && mapa[x][y-z] == 1)//recta 90º
        {
            mapa[x][y-z] = 2;
            z++;
        }
        z=1;
        while(x+z <= 19 && y+z <= 19 && mapa[x+z][y+z] == 1)//diagonal 45º
        {
            mapa[x+z][y+z]=2;
            z++;
        }
        z=1;
        while(x-z >= 0 && y-z >= 0  && mapa[x-z][y-z] == 1)//diagonal 135º
        {
            mapa[x-z][y-z]=2;
            z++;
        }
        z=1;
        while(x-z >= 0 && y+z <= 19  && mapa[x-z][y+z] == 1)//diagonal 225º
        {
            mapa[x-z][y+z]=2;
            z++;
        }
        z=1;
        while(x+z <= 19 && y-z >= 0  && mapa[x+z][y-z] == 1)//diagonal 315º
        {
            mapa[x+z][y-z]=2;
            z++;
        }
    }
    else 
    {
        printf("No hi ha cap '2' \n");
    }
       
   //imprimim mapa
    for(j = 0;j < N ;j++)
    {
        for(i = 0;i < N ;i++)
        {  
            printf("%i", mapa[i][j]);
        }
    printf("\n");
    }
}
