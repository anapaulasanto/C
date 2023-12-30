#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
  char nome[50];
  char ddd[4];
  char telefone[14];
  char tipo_num[7];
}Contato;

void cadastrarContato(Contato agenda[], int *numContatos) {
  
  if (*numContatos < MAX_CONTATOS) {
    printf("Digite o nome ou digite 'Fim' para sair: \n");
    fgets(agenda[*numContatos].nome, sizeof(agenda[*numContatos].nome), stdin);
    
    if (strcmp(agenda[*numContatos].nome, "Fim") == 0) {
      return;
  }
    printf("Digite o ddd do numero:");
    scanf("%s", agenda[*numContatos].ddd);

    printf("Digite o número do telefone: ");
    scanf("%s", agenda[*numContatos].telefone);

    printf("Digite o tipo do número (Fixo ou Móvel): ");
    scanf("%s", agenda[*numContatos].tipo_num);

    (*numContatos)++;
  } else {
    printf("Agenda de contatos cheia.\n");
  }
} 

void consultarPorNome(Contato agenda[] , int numContatos) {
   char nomeBusca[50];
      int encontrado = 0;

      printf("Digite o nome para consulta (ou 'Fim' para encerrar): ");
      scanf("%s", nomeBusca);

      while (strcmp(nomeBusca, "Fim") != 0) {
          encontrado = 0;
          for (int i = 0; i < numContatos; i++) {
              if (strcmp(nomeBusca, agenda[i].nome) == 0) {
                  printf("Nome: %s\n", agenda[i].nome);
                  printf("DDD: %s\n", agenda[i].ddd);
                  printf("Telefone: %s\n", agenda[i].telefone);
                  printf("Tipo: %s\n", agenda[i].tipo_num);
                  printf("\n");
                  encontrado = 1;
                  break;
              }
          }

          if (!encontrado) {
              printf("Contato não encontrado na agenda.\n");
          }

          printf("Digite o nome para consulta (ou 'Fim' para encerrar): ");
          scanf("%s", nomeBusca);
      }
  }

  int main() {
      struct Contato agenda[MAX_CONTATOS];
      int numContatos = 0;

      printf("=== Cadastro de Agenda Telefônica ===\n");

      // Procedimento para cadastrar contatos até que seja digitado "Fim"
      cadastrarContato(agenda, &numContatos);

      printf("\n=== Consulta de Agenda Telefônica ===\n");

      // Procedimento para realizar consultas até que seja digitado "Fim"
      consultarPorNome(agenda, numContatos);

      printf("Programa encerrado.\n");

      return 0;
  }
