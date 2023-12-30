#include <stdio.h>
#include <string.h>

typedef struct {
  int hora,minuto,segundo;
}Horario;

typedef struct {
  int dia, mes, ano;
}Data;

typedef struct {
  Data data;
  Horario horario;
  char texto[100];
}Compromisso;

int main() {
 Compromisso compromisso;
  
  printf("Escreva um texto que resuma o seu conteudo:\n ");
  fgets(compromisso.texto,100,stdin);

  printf("Digite o horario (no formato hora minuto segundos):\n ");
  scanf("%d %d %d", &compromisso.horario.hora, &compromisso.horario.minuto , &compromisso.horario.segundo);

  printf("Digite a data (no formato dd mm aaaa):\n ");
  scanf("%d %d %d", &compromisso.data.dia, &compromisso.data.mes , &compromisso.data.ano);

  printf("\nHORARIO: %d:%d:%d\n" , compromisso.horario.hora, compromisso.horario.minuto , compromisso.horario.segundo);
  printf("DATA: %d/%d/%d",compromisso.data.dia, compromisso.data.mes , compromisso.data.ano);
  printf("\nDESCRICAO DO COMPROMISSO: %s\n",compromisso.texto);
  
  return 0;
}
