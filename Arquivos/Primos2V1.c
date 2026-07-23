#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv){
    if(argc != 2){
        printf("Quantidade de argumentos inválida\n");
        printf("esperado: ./%s <numero inteiro>\n", argv[0]);
        return 1;
    }

    int MAX = atoi(argv[1]);
    int *vet; 
    int size = MAX/2;

    //Inicializa o vetor com os números ímpares até MAX
    vet = (int*)malloc(size*sizeof(int));
    vet[0] = 2;
    for(int i = 1; i < size; i++)
        vet[i] = 2*i+1;   

    clock_t start = clock();
    double raiz = sqrt(MAX);
    ///Computa os primos
    for(int i = 1; i < raiz; i++)
        if(vet[i] != 0)
            for(int j = i+vet[i]; j < size; j += vet[i])
                vet[j] = 0;

    clock_t end = clock();

    for(int i = 0; i < size; i++)
        if(vet[i] != 0)
            printf("%d ", vet[i]);
    
    printf("\nTempo de execução: %f segundos\n", 1.0*(end-start)/CLOCKS_PER_SEC);

    free(vet);
    return 0;
}