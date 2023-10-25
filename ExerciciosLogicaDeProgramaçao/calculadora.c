/* Ler dois valores e realiza opera��o aritim�tica de acordo com a escolha do usu�rio.

Universidade Veiga de Almeida
Aluno: Augusto Fernando Santos de Carvalho 
An�lise e Desenvolvimento de Sistema
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


//Fun��o de Soma
void soma(){
    
    float v1, v2, resultado;

    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);
    printf("Digite o segundo valor: ");
    scanf("%f", &v2);
    resultado = v1 + v2;

    printf(" A soma de %.2f + %.2f = %.2f . ", v1, v2, resultado);
    system("pause");
    system("cls");
   
    menu();
    
}

//Fun��o de Subtra��o
void subtrai(){
    
    float v1, v2, resultado;

    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);
    printf("Digite o segundo valor: ");
    scanf("%f", &v2);
    resultado = v1 -v2;

    printf(" A subtra��o de %.2f - %.2f = %.2f . ", v1, v2, resultado);
    system("pause");
    system("cls");
    menu();

}

// Fun��o de Multiplica��o 
void multiplica(){
    
    float v1, v2, resultado;

    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);
    printf("Digite o segundo valor: ");
    scanf("%f", &v2);
    resultado = v1 * v2;

    printf(" A multiplica��o de %.2f * %.2f = %.2f . ", v1, v2, resultado);
    system("pause");
    system("cls");
    menu();

}

void divide(){
    
    float v1, v2, resultado;

    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);
    printf("Digite o segundo valor: ");
    scanf("%f", &v2);
    
    while (v2 == 0)
    {
        printf(" \n N�o existe divis�o por zero, digite outro valor:  ");
        scanf("%f", &v2);
    }

    resultado = v1 / v2;
    printf(" A divis�o de %.2f / %.2f = %.2f . ", v1, v2, resultado);
  
    system("pause");
    
    system("cls");

    menu();

}


// Menu com as op��es de opera��o
int menu(){
    
    int opcao;
    char selecionar;
   
    printf("=============================================\n");
    printf("=============================================\n");    
    printf("                 CALCULADORA                 \n");
    printf("=============================================\n");
    printf("=============================================\n\n\n");

    printf(" Escolha uma opera��o matem�tica !!!\n\n");
    printf("\t1 -> Adi��o \n");
    printf("\t2 -> Subtra��o \n");
    printf("\t3 -> Divis�o \n");
    printf("\t4 -> Multiplica��o \n");
    printf("\t5 -> Sair da Calculadora \n");
    scanf("%d", &opcao);

       if (opcao == 1)
    {
        soma();
    }
    else if (opcao == 2)
    {
        subtrai();
    }
    else if (opcao == 3)
    {
        divide();
    }
    else if (opcao == 4)
    {
        multiplica();
    }
    else if (opcao == 5)
    {       
        system("exit"); // fecha o programa
        printf(" Voc� saiu do Programa...\n");// Exibe mensagem na tela
        printf(" CALCULADORA Version 1.0.0 By Augusto\n\n\n\n ");// Exibe a vers�o do programa
        system("cls");
    }
    else
    {
        printf("Op��o invalida, quer tentar novamente? [s] ou [n]. \n\n\n");
        scanf("%s", &selecionar);

        if (selecionar == 's' || selecionar == 'S')// Retorna ao menu
        {                           
            menu();
        }
        else if ( selecionar == 'n' || selecionar == 'N')// Limpa a tela
        {
            system("cls");
            printf("\n\n\n\n Obrigado por usar nossa calculadora! At� a pr�xima....\n\n\n\n");
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    setlocale (LC_ALL, "Portuguese_Brazil"); // Exibe ps caracteres como acentua��o, etc.
    menu();
    system("pause");
    return 0;
}
