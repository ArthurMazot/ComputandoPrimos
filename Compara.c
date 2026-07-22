#include <stdio.h>
#include <stdlib.h>

int main(int n, char **args){
    FILE *arq1 = fopen(args[1], "r");
    if(!arq1){
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", args[1]);
        return 1;
    }

    FILE *arq2 = fopen(args[2], "r");
    if(!arq2){
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", args[2]);
        fclose(arq1);
        return 1;
    }

    int num1, num2;
    while(fscanf(arq1, "%d", &num1) == 1 && fscanf(arq2, "%d", &num2) == 1){
        if(num1 != num2){
            printf("Os arquivos são diferentes. %d, %d\n", num1, num2);
            fclose(arq1);
            fclose(arq2);
            return 0;
        }
    }
    
    printf("Os arquivos são iguais.\n");
    fclose(arq1);
    fclose(arq2);
    return 0;
}