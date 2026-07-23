#include <stdio.h>
#include <time.h>

int main(int argc, char **argv){
    if(argc != 2){
        printf("Quantidade de argumentos inválida\n");
        printf("esperado: ./%s <numero inteiro>\n", argv[0]);
        return 1;
    }

    int MAX = atoi(argv[1]);
    clock_t start = clock();
    for(int i=2; i<=MAX; i++){
        int primo = 1;
        for(int j=2; j<i; j++){
            if(i%j == 0){
                primo = 0;
                break;
            }
        }
        if(primo){
            printf("%d ", i);
        }
    }

    clock_t end = clock();
    printf("\nTempo de execução: %f segundos\n", (1.0*(end - start))/CLOCKS_PER_SEC);
    return 0;
}