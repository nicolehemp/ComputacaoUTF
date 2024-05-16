#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

void quicksort(int *valores, int inicio, int fim);
void bubble_sort(int *valores, int tam);

int main () {

setlocale(LC_ALL, "Portuguese_Brazil");

int tam, *vet, i=0, x=0, alg, repetidor;

do
{
printf ("Insira o tamanho: ");
scanf ("%d", &tam);

vet = malloc (tam * sizeof(int)); //recebe a quantidade de bits para armazenar na memoria

for (i=0; i<tam; i++) {
    printf ("Valor %d: ", i+1);
    scanf ("%d", &x);
    *(vet + i) = x;
}

printf ("\nEscolha um algoritmo de ordenacao:\n1-Bolha.\n2-Quicksort\n");
scanf ("%d", &alg);

clock_t start = clock();
switch (alg) {

    case 1:
    bubble_sort(vet, tam);
    break;

    case 2:
    quicksort(vet, 0, tam-1);
}
clock_t end = clock();

//imprime o vetor ordenado
for (i=0; i<tam; i++) {
    printf ("%d ", *(vet+i));
}


float dif = end - start;

printf ("\n\nTempo de execucao: %lf segundos\n", (dif/CLOCKS_PER_SEC));

printf ("\nDeseja repetir o codigo? Digite 1 para continuar ou 0 para sair: ");
scanf ("%d", &repetidor);
printf ("\n");

} while (repetidor == 1);

    return 0;
}

void bubble_sort(int *valores, int tamanho) {

    int aux, i, j;

        for (i = 0; i < tamanho; i++) {
            for (j = 0; j < tamanho-1-i; j++) {
                if (valores[j] < valores[j+1]) {
                // troca
                aux = valores[j+1];
                valores[j+1] = valores[j];
                valores[j] = aux;
                }
            }
        }
}

void quicksort(int *valores, int inicio, int fim) {
    
    int i, j, pivo, valorlido;
    i = inicio;
    j = fim;
    pivo = valores[(inicio+fim)/2];

    do {
        while (valores[i] > pivo && i < fim) i++;
        while (valores[j] < pivo && j > inicio) j--;

        if (i <= j) {
        valorlido = valores[i];
        valores[i] = valores[j];
        valores[j] = valorlido;
        i++; j--;
        }
    } while (i <= j);

    if (inicio<j) quicksort(valores, inicio, j);
    if (i<fim) quicksort(valores, i, fim);
}