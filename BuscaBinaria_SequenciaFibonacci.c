#include <stdio.h>

//variaveis globais
long long int inteiro [100]; 
int meio=0;

//imprime a sequencia de Fibonacci
void fibonacci (int tam) {
    int i=2;

    inteiro[0] = 1;
    inteiro[1] = 1;

    for (i=2; i<tam; i++) {
        inteiro[i] = inteiro[i-1] + inteiro [i-2];
    }

    for (i=0; i<=tam-1; i++) {
        printf ("%d %lld \n", i+1, inteiro[i]);
    }

}

//busca binaria
int binaria (long long int *itens, int tam, long long int chave) {
    int inicio=0, fim=0;

    fim = tam - 1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (chave < itens[meio]) {
            fim = meio - 1;
        } else {
            if (chave > itens[meio]){
                inicio = meio + 1;
            } else {
                return meio;
            }
        }
    } 
    return -1;
}

int main () {
    int usuario, retbin;
    long long int num_seq;

    printf ("Digite o numero de elementos na sequencia de Fibonacci: ");
    scanf ("%d", &usuario);

    printf ("\n");
    fibonacci(usuario);

    printf ("\n\nDigite um numero da sequencia: ");
    scanf ("%lld", &num_seq);

    if (usuario == 1) {
        if (num_seq == 1) {
            printf ("O numero 1 esta no 1 indice do vetor");
        } else {
            printf ("Valor nao encontrado no vetor.");
        }
    }

    if (usuario>=2) {

        if (num_seq == 1) {
            printf ("O numero %lld esta no 1 e 2 indices do vetor!", num_seq);
        } else {

            binaria(inteiro, usuario, num_seq);
            retbin = binaria(inteiro, usuario, num_seq);

            if (retbin == -1) {
                printf ("Valor nao encontrado no vetor.");
            } else {
                printf ("O numero %lld esta no %d indice do vetor.", num_seq, meio+1);
            }
        }
    }

    return 0;
}