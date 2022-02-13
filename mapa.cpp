#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define N 20
#define llindar 1


int main () 
{
    
    int mapa[N][N]={0}, i , j, contador1 = 0, contador = 0, Fila = 0, casos; 
    //longitudMAX = 3,275849152 longitudMIN= 0,25057195 latitudMAX = 42,838367921 latitudMIN = 40,5428638
    float DadesMunicipis[1000][7] = {0}, codiMunicipi;
    char lector, lector1;
    bool trobat = false, trobat1=false;

    scanf("%c",&lector);     
    while(lector != '#') // guardem les dades a DadesMunicipi[][] codi municipi, longitud , latitud
    {              
        scanf("%c",&lector);
        if(isdigit(lector))
        {
            trobat=true;
        }
        if(lector == ',' && trobat)
        {
            contador++;            
        }
        if(contador == 1 && trobat)
        {                   
            scanf("%f", &DadesMunicipis[Fila][0]);     
        }
        if(contador == 9 && trobat)
        {
            scanf("%f", &DadesMunicipis[Fila][1]);
        }
        if(contador == 10 && trobat)
        {
            scanf("%f", &DadesMunicipis[Fila][2]);   
        }
        if(lector == '\n' && trobat)
        {
            DadesMunicipis[Fila][4] = floor((3.275849152-DadesMunicipis[Fila][1])*(19/(3.275849152-0.25057195)));//Fòrmula per a convertir les coordenades reals a les coordenades de la taula
            DadesMunicipis[Fila][5] = floor((42.838367921-DadesMunicipis[Fila][2])*(19/(42.838367921-40.5428638)));
            contador = 0;
            Fila++;
            trobat = false;                    
        } 
    }
    
    Fila = 0;
    scanf("%c",&lector1);
    while(!isdigit(lector1))
        {
            scanf("%c",&lector1);
        }		             
    while(lector1 != '#')
    {
        if(lector1 == ',')
        {
            contador++;                
        }
        if(contador == 3)
        {
            scanf("%f", &codiMunicipi);
            for(Fila = 0; codiMunicipi != DadesMunicipis[Fila][0]; Fila++)// comparem els codis Municipals, 1 del document de localitzacio i un del de registre
            {
            }     
        }
        if(contador == 8)
        {
            scanf("%i", &casos);
            if(casos >= llindar)
            {
                DadesMunicipis[Fila][3] = 1;
                Fila=0;
            }
        }
        if(lector1 == '\n' )
        {
            contador = 0;
        }
    scanf("%c", &lector1);    
    }

    for(i = 0  ; i < N; i++)// omplim mapa
    {
       for(j = 0 ; j < N; j++)
        {
            for(Fila = 0; Fila < 949 ;Fila++)
            { 
                if(DadesMunicipis[Fila][4] == i && DadesMunicipis[Fila][5] == j &&  DadesMunicipis[Fila][3] == 1 )
                {
                    mapa[i][j] = 1;
                }
            }              
        }
    }   
    // imprimim mapa 
    for(j = 0;j < N ;j++)
    {
        for(i = 19;i >= 0 ;i--)
        {  
            printf("%i", mapa[i][j]);
        }
        printf("\n");
    }
    printf("#\n");
}
