#include <stdio.h>
#include <stdlib.h>

#define NAME_ARQ "test sum matrix.txt"

int main()
{
    int i, m, total_l, total_c;

    int **matriz1, **matriz2, **matriz_res;

    FILE *arq = fopen(NAME_ARQ, "r");

    fscanf(arq, "%d %d", &total_l, &total_c);

    matriz1 = (int **)calloc(total_l, sizeof(int *));
    for(i=0; i<total_l; i++){
        matriz1[i] = (int *)calloc(total_c, sizeof(int));
    }

    matriz2 = (int **)calloc(total_l, sizeof(int *));
    for(i=0; i<total_l; i++){
        matriz2[i] = (int *)calloc(total_c, sizeof(int));
    }

    matriz_res = (int **)calloc(total_l, sizeof(int *));
    for(i=0; i<total_l; i++){
        matriz_res[i] = (int *)calloc(total_c, sizeof(int));
    }

    for(i=0; i<total_l; i++){
        for(m=0; m<total_c; m++){
            fscanf(arq, "%d", &matriz1[i][m]);
        }
    }

    for(i=0; i<total_l; i++){
        for(m=0; m<total_c; m++){
            fscanf(arq, "%d", &matriz2[i][m]);
        }
    }

    for(i=0; i<total_l; i++){
        for(m=0; m<total_c; m++){
            matriz_res[i][m] = matriz1[i][m] + matriz2[i][m];
        }
    }

    printf("\t\tResultado\n\n");
    for(i=0; i<total_l; i++){
        for(m=0; m<total_c; m++){
            printf("%3d", matriz_res[i][m]);
            if(m == total_c-1){
                printf("\n");
            }
        }
    }
}
