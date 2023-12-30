#include <stdio.h>
#include <string.h>

typedef struct {
   char nome[15];
   double potencia;
   double tempoAtivo;
}Eletrodomestico;

int main() {
  Eletrodomestico eletro[5];
  int i;
  double tempoTotal , consumoTotal , consumoRelativo;
  tempoTotal= 0;
  consumoTotal = 0;
  consumoRelativo = 0;

  for (i = 0 ; i < 2 ; i++) {
      printf("\nElerodomestico %d: \n",i+1);
      
      printf("Digite o nome (com no maximo 15 letras): \n");
      
      fgets(eletro[i].nome,15,stdin);
    
      printf("Digite a potencia (em W): \n");
      scanf("%lf",&eletro[i].potencia);
    
      printf("Digite o tempo ativo por dia (em horas) eletrodomestico: \n");
      scanf("%lf",&eletro[i].tempoAtivo);
      getchar();
  }
  
  printf("Digite quantos dias os aparelhos ficaram em uso: \n");
  scanf("%lf",&tempoTotal);

   for (i = 0 ; i < 2 ; i++) {
     consumoTotal += eletro[i].potencia * eletro[i].tempoAtivo * tempoTotal;
   }
  
  printf("\tCONSUMO TOTAL NA CASA: %.2lf kWh\n\n", (double)consumoTotal/1000);
  printf("\tCONSUMO RELATIVO:\n ");

   for (i = 0 ; i < 2 ; i++) {
     consumoRelativo =  (eletro[i].potencia * eletro[i].tempoAtivo * tempoTotal) / consumoTotal * 100.0;

     printf("\t%s=\t%.2lf%%\n", eletro[i].nome, consumoRelativo);
   }

  
return 0;
}
