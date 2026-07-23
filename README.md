makefile:
Para mudar a quantidade de numeros primos calculados, tem uma variálvel (MAX) dentro do makefile na 1 linha
Caso não queira executar algum arquivo, basta remover ele da variável RUN_TARGETS

make all: Compila todos os arquivos .c
make run: Executa todos os arquivos PrimosXVY
make clean: Remove todos os executaveis e todos os resultados

Foi feito com auxilio do copilot
Por isso pode ter problemas com o Windowns, que eu não consigui testar
//========================================================//

Compara.c:
Recebe 2 nomes de arquivos e comparar eles, caso sejam diferentes mostra uma mensagem no terminal
./exec parametro1 parametro2

//========================================================//

Todos arquivos abaixo computão primos menores que "MAX" e imprime no terminal junto com seu tempo de execução
Para usar com o arquivo Compara.c: ./exec MAX > nomeArquivo

Primos.c: 
-Computa sem nenhuma otimização

Primos1V0.c: 
-Não testa numeros desconhecidos pares
-Agora possui um vetor que guarda todos os numeros primos
-Só testa o numero desconhecido com os numeros primos conhecidos do vetor

Primos1V1.c:
Um numero não primo se for dividido por um primo que lhe compõe sempre resultara em um numero inteiro, mas ao invés
de olharmos só para se um numero é inteiro ou não, podemos ver o resultado da divisão
Ex.: Para descobrimos se o numero 23 é primo
23/2 = 11.5
23/3 = 7.66
23/5 = 4.6
Depois de dividir por cinco, podemos nos perguntar, que numero primo menor que 4.6 não foi testado.
Nenhum, então 23 é primo
Podemos deduzir então que:
x/p < p
x < p^2
sqrt(x) < p
Ou seja podemos fazer sqrt(23) = 4.79, e testar os numeros primos menores que 4.79

Primos2V0.c:
Inicializa um vetor de tamanho MAX e coloca todos os numeros de 2 até MAX, e ao invés de fazer divisões, apenas marca multiplos
dos numeros primos com 0, no final só sobram numeros primos

Primos2V1.c:
-Inicializa o vetor com apenas numeros impares
-Aplica a mesma ideia do "Primos1V1.c"

Primos2V2.c:
Como estamos marcando todos os multiplos dos numeros primos, podemos evitar algumas redundacias.
Se pegarmos 7 como exemplo, como ja marcamos os primos anteriores, também ja marcamos os multiplos
de 7 menores que 7.
Ex.: 2x7, 3x7, 5x7
Ou seja podemos começar a marcar os numeros apartir de 7^2

//========================================================//

Comparações em segundos:
MAX ->          10^6       10^7       10^8
Primos.c:     55.23777   ????????   ????????
Primos1V0.c:  4.451091   317.1958   ????????
Primos1V1.c:  0.026156   0.441399   8.946505
Primos2V0.c:  0.009508   0.186275   2.373094
Primos2V1.c:  0.002315   0.057858   0.677199
Primos2V2.c:  0.001879   0.050125   0.604212