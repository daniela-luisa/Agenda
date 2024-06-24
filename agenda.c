#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct
{
    char nome[50];
    int telefone;
} Contato;

void consultarContato(Contato *array, int *size, char nome[50]);
void listaContatos(Contato *contato, int *size);
void deletarContato(Contato *array, int *size, char nome[50]);

int main()
{
    int op1, op2;
    int size = 0;

    Contato contato[MAX_SIZE];

    FILE *arquivo;
    arquivo = fopen("contatos.bin", "wb");
  

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do{
        printf("   _____________________\n");
        printf("  /                      \\\n");
        printf(" /          MENU          \\\n");
        printf("/__________________________\\\n");
        printf(" |                       |\n");
        printf(" |1) Adicionar contato   |\n");
        printf(" |2) Consultar contato   |\n");
        printf(" |3) Excluir contato     |\n");
        printf(" |4) Sair                |\n");
        printf(" |_______________________|\n");
        printf("\nEscolha uma opção: ");
        scanf("%i", &op1);
        system("clear");

        switch (op1){
        case 1:
            printf(" **ADICIONAR CONTATO**\n ");
            printf("\nPreencha as informações\n");
            printf("\nNome: ");
            scanf(" %[^\n]", &contato[size].nome);
            printf("Telefone: ");
            scanf("%i", &contato[size].telefone);
            system("clear");
            fwrite(&contato, sizeof(Contato), 1, arquivo);
            size++;
            break;

        case 2:
            char nome[50];
            printf("       **CONSULTAR CONTATO**\n");
            printf(" _________________________________\n");
            printf(" |                               |\n");
            printf(" |1) Consultar um contato apenas |\n");
            printf(" |2) Consultar todos os contatos |\n");
            printf(" |_______________________________|\n");
            printf(" Escolha uma opção: ");
            scanf("%i", &op2);
            system("clear");
            switch (op2)
            {
            case 1:
                consultarContato(contato, &size, nome);
                break;

            case 2:
                listaContatos(contato, &size);
                break;
            }

            break;
        case 3:
            deletarContato(contato, &size, nome);
            break;
        default:
            break;
        }
    } while (op1 != 4);
    fclose(arquivo);
}
//---------------------------------------------------------------
void consultarContato(Contato *array, int *size, char nome[50]){

    int i;
    printf("**CONSULTAR CONTATO**\n ");
    printf("\nDigite o nome do contato que deseja consultar: ");
    scanf(" %[^\n]", nome);
    system("clear");

    for (i = 0; i < *size; i++){
        if (strcmp(array[i].nome, nome) == 0){ /* se o nome for o que queremos consultar */
            printf("CONTATO ENCONTRADO\n");
            printf("---------------------\n");
            printf("|Nome:%s \n|Telefone: %i\n", array[i].nome, array[i].telefone);
            printf("---------------------\n");
            return;
        }
    }
    printf("\nNão foi possível encontrar o contato com o nome %s\n", nome);
}

void listaContatos(Contato *contato, int *size){

    int i;
        printf(" **LISTA DE CONTATOS**\n");
        printf("-----------------------\n");
    for (i = 0; i < *size; i++){
        printf("|Nome: %s \n|Telefone: %i\n", contato[i].nome, contato[i].telefone);
        printf("-----------------------\n");
    }
}

void deletarContato(Contato *array, int *size, char nome[50]){
    int i;

    printf("**EXCLUIR CONTATO**\n ");
    printf("\nDigite o nome do contato que deseja excluir: ");
    scanf(" %[^\n]", nome);
    system("clear");

    for (i = 0; i < *size; i++){
        if (strcmp(array[i].nome, nome) == 0) /* se o nome for o que queremos remover */
        {
            array[i] = array[*size - 1]; /* Substitui o elemento que queremos remover pelo último elemento */
            (*size)--;                   /* Reduz o tamanho do array */

            printf("\nA pessoa com o nome %s foi removida com sucesso.\n", nome);
            printf("---------------------\n");
            return; /* Saindo da função */
        }
    }
    printf("Não foi possível encontrar o contato com o nome %s.\n", nome);
}