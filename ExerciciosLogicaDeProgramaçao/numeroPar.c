/* ?O usuário realiza a digitação de dois números (número inicial e número final).
    E através de uma estrutura de repetição, verifica se os números alimentados são pares
    ou ímpares, retornando o status se são pares ou ímpares.?
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    int valor1, valor2, i;

    printf("Digite um número inicial: ");
    scanf("%d", &valor1);
    printf("Digite um número final: ");
    scanf("%d", &valor2);

    for (i = valor1; i <= valor2; i++){
  
    if (i % 2 == 0)
    {
        printf("O número %d é PAR \n", i);
    }
    else if (i % 2 != 0)
    {
        printf("O número %d é ÍMPAR\n", i);
    }
    }
    
    return 0;
}