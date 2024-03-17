#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct {
  int cod;
  char nome[20];
  char titulo[20];
  char autor[20];
  char editora[20];
} Livros;

int livros_cadastrados = 0;

void cadastrar_livro(Livros livro[], int n) {
  printf("\n\t > CADASTRO DE LIVROS \n");
  printf("Quantos livros quer cadastrar? \n");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Digite o codigo do livro: \n");
    scanf("%d", &livro[i].cod);
    getchar();

    printf("Digite o nome do livro:\n");
    fgets(livro[i].nome, 100, stdin);

    printf("Digite o autor:\n");
    fgets(livro[i].autor, 100, stdin);

    printf("Digite a editora:\n");
    fgets(livro[i].editora, 100, stdin);

    printf("\tLivro adicionado com sucesso!\n");
    livros_cadastrados++;
  }
}

void exibir_livro(Livros livro[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("\nLivro: %s", livro[i].nome);
    printf("Codigo: %d\n", livro[i].cod);
    printf("Editora: %s", livro[i].editora);
    printf("Autor: %s\n\n", livro[i].autor);
  }
}

void consultar_livro(Livros livro[], int tamanho) {

  printf("\n\t> CONSULTA DE LIVROS \n");
  int opc_cod, opc;
  char opc_livro_info;
  char opc_livro_nome[20];
  char opc_livro_editora[20];
  char opc_livro_autor[20];

  while (opc != 0) {
    printf("1. Consultar por codigo\n2. Consultar por autor\n3. Consultar por "
           "editora\n0. Sair\n");
    scanf("%d", &opc);

    switch (opc) {
    case 1: {
      printf("Digite o codigo do livro:\n");
      scanf("%d", &opc_cod);

      for (int i = 0; i < tamanho; i++) {
        if (opc_cod == livro[i].cod) {
          printf("\n\tLivro encontrado!\n");
          printf("Deseja ver mais informacoes do livro? (s ou n)\n\n");
          scanf(" %s", &opc_livro_info);

          if (tolower(opc_livro_info) == 's') {
            exibir_livro(livro, livros_cadastrados);
            break;
          } else {
            return;
          }
        } else {
          printf("ERRO! Codigo invalido!");
          return;
        }
      }
    }

    case 2: {
      getchar();
      printf("Digite o nome do autor:\n");
      fgets(opc_livro_autor, 20, stdin);

      for (int i = 0; i < strlen(opc_livro_autor); i++) {
        opc_livro_autor[i] = tolower(opc_livro_autor[i]);
      }
      for (int i = 0; i < strlen(livro[i].autor); i++) {
        livro[i].autor[i] = tolower(livro[i].autor[i]);
      }

      for (int i = 0; i < tamanho; i++) {
        if (strcmp(opc_livro_autor, livro->autor) == 0) {
          printf("\n\tLivro encontrado!\n");
        } else {
          printf("ERRO! Autor nao encontrado!");
          break;
        }
      }

      printf("Deseja ver mais informacoes do livro? (s ou n)\n\n");
      scanf(" %s", &opc_livro_info);

      if (tolower(opc_livro_info) == 's') {
        exibir_livro(livro, livros_cadastrados);
      } else {
        break;
      }
      break;
    }
    case 3: {
      getchar();
      printf("Digite o nome da editora:\n");
      fgets(opc_livro_editora, 20, stdin);

      for (int i = 0; i < strlen(opc_livro_editora); i++) {
        opc_livro_editora[i] = tolower(opc_livro_editora[i]);
      }
      for (int i = 0; i < strlen(livro[i].editora); i++) {
        livro[i].editora[i] = tolower(livro[i].editora[i]);
      }

      for (int i = 0; i < tamanho; i++) {
        if (strcmp(opc_livro_editora, livro->editora) == 0) {
          printf("\n\tLivro encontrado!\n");
          printf("Deseja ver mais informacoes do livro? (s ou n)\n\n");
          scanf(" %s", &opc_livro_info);

          if (tolower(opc_livro_info) == 's') {
            exibir_livro(livro, livros_cadastrados);
          } else {
            return;
          }
        } else {
          printf("ERRO! Editora nao encontrada!");
          return;
        }
      }
      break;
    }
    }
  }
}

int main(void) {
  int i, opc, cod, n = 0;
  Livros livro[TAM];

  while (opc != 0) {
    printf("\n\t----------- LIVRARIA BOOKS ------------\n");
    printf("0 - Sair\n1 - Cadastrar livro \n2 - Exibir livros\n3 - Consultar "
           "livro\n");
    scanf("%d", &opc);

    switch (opc) {
    case 1: {
      cadastrar_livro(livro, n);
      break;
    }
    case 2: {
      exibir_livro(livro, livros_cadastrados);
      break;
    }
    case 3: {
      consultar_livro(livro, livros_cadastrados);
    }
    }
  }

  return 0;
}