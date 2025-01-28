#include <iostream>
#include <fstream>
#include <ctime>
#include <thread>
#include <math.h>

using namespace std;

#define TAM 100000

int primos[TAM+4];

int abreArquivo(){
    ifstream arq("NumerosPrimosParalelos.txt");
    primos[0] = 2;
    primos[1] = 3;
    primos[2] = 5;
    if(!arq.is_open()) return 3;
    int tam;
    arq >> tam;
    for(int i = 3; i < tam; i++)
        arq >> primos[i];
    arq.close();
    return tam;}

void threads(int &c, bool &b){
    while(1){
        if(c == -1) continue;
        c = ePrimo(c);
    }
}

int ePrimo(int teste){
    int n = sqrt(teste);
    for(int i = 1; primos[i] <= n; i++)
        if(!(teste % primos[i])) return 0;
    return teste;}

void salvaArquivo(){
    ofstream arq("NumerosPrimosParalelos.txt");
    arq << TAM << endl;
    for(int i = 3; i < TAM; i++)
        arq << primos[i] << " ";
    arq.close();}

int main(){
    int tam = abreArquivo();
    int chanel[4] = {-1,-1,-1,-1};
    bool boolean[4];
    clock_t start = clock();

    thread t1([&] {threads(chanel[0], boolean[0]);});
    thread t2([&] {threads(chanel[1], boolean[1]);});
    thread t3([&] {threads(chanel[2], boolean[2]);});
    thread t4([&] {threads(chanel[3], boolean[3]);});

    for(int i = (tam <= 3) ? 7 : primos[tam - 1] + 2; tam < TAM;){
        for(char j = 0; j < 4; j++){
            
        }
    }
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    clock_t end = clock();
    //cout << "Demorou " << 1.0*(end - start)/CLOCKS_PER_SEC << " segundos" << endl;
    salvaArquivo();}