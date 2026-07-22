#include <stdio.h>
#include <time.h>

#define MAX 1000000

int main(){
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
    printf("\nTempo de execução: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}