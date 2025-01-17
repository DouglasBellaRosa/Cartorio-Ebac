#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings

    FILE *file;         
    file = fopen(arquivo, "w"); // cria o arquivo
    if (file == NULL) {
        printf("N�o foi poss�vel criar o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s,", cpf); // salva o valor da vari�vel
    fclose(file);       

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    system("pause");
    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[100];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
        system("pause");
        return 0;
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, 100, file) != NULL) {
        printf("%s", conteudo);
    }
    printf("\n\n");

    fclose(file);
    system("pause");

    return 0;
}

int deletar() {
    char cpf[40];
    printf("Digite o CPF do registro a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Registro deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar o registro. Certifique-se de que o CPF est� correto.\n");
    }

    system("pause");
    return 0;
}

int main() 
	{
    int opcao = 0; // Definindo vari�veis
    int laco = 1;

    for (laco = 1; laco == 1;) {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

        printf("### Cartorio da EBAC ###\n\n"); // in�cio do menu
        printf("Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: "); // fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usu�rio

        system("cls");

        switch (opcao) // in�cio da sele��o
        {
        case 1:
            registro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        case 4:
        printf("Obrigado por utilizar o sistema!\n");
        return 0;
        break;     
        
        default:
            printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
        } // fim da sele��o
    }

    return 0;
}

