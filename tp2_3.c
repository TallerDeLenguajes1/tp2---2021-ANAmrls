#include <stdio.h>
#include <stdlib.h>

#define FILAS 15

void pares(int **matriz, int columnas);

int main () {
    int columnas;
    int **p_matriz = (int**) malloc(sizeof(int*) * FILAS);    

    for (int i = 0; i < FILAS; i++)
    {
        columnas = 5 + rand() % 11;
        p_matriz[i] = (int*) malloc(sizeof(int) * columnas);

        for (int j = 0; j < columnas; j++)
        {
            p_matriz[i][j] = 100 + rand() % 900;
            printf("%d ", p_matriz[i][j]);
        }//for end
        printf("\n");
    }//for end

    printf("\n");

    pares(p_matriz, columnas);

    for (int k = 0; k < FILAS; k++)
    {
        free(p_matriz[k]);
    }//for end    

    free(p_matriz);

    getchar();
    
    return 0;
}

//Función para contar números pares en cada fila de una matriz y guardarlos en un vector

void pares(int **matriz, int columnas) {
    int contar = 0;
    int *p_vector = (int*) malloc(sizeof(int) * FILAS);

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] % 2 == 0)
            {
                contar++;
            }//if end            
        }//for end
        
        p_vector[i] = contar;
        printf("Fila %d = %d pares\n", i+1, p_vector[i]);
        contar = 0;
        
    }//for end

    free(p_vector);
    
}