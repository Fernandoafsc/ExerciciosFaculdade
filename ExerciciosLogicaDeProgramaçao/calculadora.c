/* Ler dois valores e realiza operação aritimética de acordo com a escolha do usuário.

Universidade Veiga de Almeida
Aluno: Augusto Fernando Santos de Carvalho 
Análise e Desenvolvimento de Sistema
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


//Função de Soma
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

//Função de Subtração
void subtrai(){
    
    float v1, v2, resultado;

    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);
    printf("Digite o segundo valor: ");
    scanf("%f", &v2);
    resultado = v1 -v2;

    printf(" A subtração de %.2f - %.2f = %.2f . ", v1, v2, resultado);
    system("pause");
    system("cls");
    menu();

}

// Função de Multiplicação 
void multiplica(){
    
    float v1, v2, resultado;

    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);
    printf("Digite o segundo valor: ");
    scanf("%f", &v2);
    resultado = v1 * v2;

    printf(" A multiplicação de %.2f * %.2f = %.2f . ", v1, v2, resultado);
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
        printf(" \n Não existe divisão por zero, digite outro valor:  ");
        scanf("%f", &v2);
    }

    resultado = v1 / v2;
    printf(" A divisão de %.2f / %.2f = %.2f . ", v1, v2, resultado);
  
    system("pause");
    
    system("cls");

    menu();

}


// Menu com as opções de operação
int menu(){
    
    int opcao;
    char selecionar;
   
    printf("=============================================\n");
    printf("=============================================\n");    
    printf("                 CALCULADORA                 \n");
    printf("=============================================\n");
    printf("=============================================\n\n\n");

    printf(" Escolha uma operação matemática !!!\n\n");
    printf("\t1 -> Adição \n");
    printf("\t2 -> Subtração \n");
    printf("\t3 -> Divisão \n");
    printf("\t4 -> Multiplicação \n");
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
        printf(" Você saiu do Programa...\n");// Exibe mensagem na tela
        printf(" CALCULADORA Version 1.0.0 By Augusto\n\n\n\n ");// Exibe a versão do programa
        system("cls");
    }
    else
    {
        printf("Opção invalida, quer tentar novamente? [s] ou [n]. \n\n\n");
        scanf("%s", &selecionar);

        if (selecionar == 's' || selecionar == 'S')// Retorna ao menu
        {                           
            menu();
        }
        else if ( selecionar == 'n' || selecionar == 'N')// Limpa a tela
        {
            system("cls");
            printf("\n\n\n\n Obrigado por usar nossa calculadora! Até a próxima....\n\n\n\n");
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    setlocale (LC_ALL, "Portuguese_Brazil"); // Exibe ps caracteres como acentuação, etc.
    menu();
    system("pause");
    return 0;
}
