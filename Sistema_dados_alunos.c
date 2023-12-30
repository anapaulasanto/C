#include <stdio.h>

typedef struct {
  int matricula,codDisciplina;
  double nota1,nota2,media;
  char nome[20];
}Alunos;

int main(void) {

  Alunos aluno[2];
  int i;

  for (i = 0; i < 2 ; i++) {
    printf("\nAluno %d:\n\n",i+1);

    printf("Digite o nome do aluno:\n");
    fgets(aluno[i].nome,20,stdin);
    
    printf("Digite o codigo da disciplina:\n");
    scanf("%d",&aluno[i].codDisciplina);

    printf("Digite a nota da primeira prova do aluno:\n");
    scanf("%lf",&aluno[i].nota1);

    printf("Digite a nota da segunda prova do aluno:\n");
    scanf("%lf",&aluno[i].nota2);
    getchar();
    
    aluno[i].media  = (double) (aluno[i].nota1*1.0 + aluno[i].nota2*2.0) / 2.0;
  }

   for (i = 0; i < 2 ; i++) {
     printf("\nALUNO: %s\n\nMEDIA FINAL = %.2lf",aluno[i].nome , aluno[i].media);
   }
  
  return 0;
}
