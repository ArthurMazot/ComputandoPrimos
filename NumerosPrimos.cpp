#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
using namespace std;

#define TAM 10000000

int abreArquivo(int *primos){
    ifstream arq("NumerosPrimos.txt");
    primos[0] = 2;
    primos[1] = 3;
    if(!arq.is_open()) return 2;
    int tam;
    arq >> tam;
    for(int i = 0; i < tam; i++)
        arq >> primos[i];
    arq.close();
    return tam;}

bool ePrimo(int *primos, int teste){
    int n = sqrt(teste);
    for(int i = 1; primos[i] <= n; i++)
        if(!(teste % primos[i])) return false;
    return true;}

void salvaArquivo(int *primos){
    ofstream arq("NumerosPrimos.txt");
    arq << TAM << endl;
    for(int i = 0; i < TAM; i++)
        arq << primos[i] << (((i%100) == 99) ? '\n' : ' ');
    arq.close();}

int main(){
    int *primos = (int*)malloc(TAM*sizeof(int));
    int tam = abreArquivo(primos);
    clock_t start = clock();

    for(int i = (tam <= 2) ? 5 : primos[tam - 1] + 2; tam < TAM; i += 2){
        if(ePrimo(primos, i)) primos[tam++] = i;}

    clock_t end = clock();
    cout << "Demorou " << 1.0*(end - start)/CLOCKS_PER_SEC << " segundos" << endl;
    salvaArquivo(primos);
    delete primos;}