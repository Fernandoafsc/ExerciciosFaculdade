/* ?O usu�rio realiza a digita��o de dois n�meros (n�mero inicial e n�mero final).
    E atrav�s de uma estrutura de repeti��o, verifica se os n�meros alimentados s�o pares
    ou �mpares, retornando o status se s�o pares ou �mpares.?
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    int valor1, valor2, i;

    printf("Digite um n�mero inicial: ");
    scanf("%d", &valor1);
    printf("Digite um n�mero final: ");
    scanf("%d", &valor2);

    for (i = valor1; i <= valor2; i++){
  
    if (i % 2 == 0)
    {
        printf("O n�mero %d � PAR \n", i);
    }
    else if (i % 2 != 0)
    {
        printf("O n�mero %d � �MPAR\n", i);
    }
    }
    
    return 0;
}