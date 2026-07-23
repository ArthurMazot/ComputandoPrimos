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
    //Inicialização
    int flag;
    int tam = 2;
    int num = 5;
    int *vet = malloc(MAX*sizeof(int));
    vet[0] = 2;
    vet[1] = 3;

    clock_t start = clock();
    //Computa os primos
    while(num < MAX){
        double raiz = sqrt(num);
        flag = 1;
        for(int i = 1; vet[i] <= raiz; i++)
            if(!(num % vet[i])){
                flag = 0;
                break;}

        if(flag)
            vet[tam++] = num;

        num += 2;
    }

    clock_t end = clock();
    
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);
    printf("\nTempo de execução: %f segundos\n", (1.0*(end - start))/CLOCKS_PER_SEC);

    free(vet);}