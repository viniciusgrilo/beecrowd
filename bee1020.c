#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int idade = 0, dia = 0, mes = 0, ano = 0;
	
	scanf("%d", &idade);
	
	ano = idade / 365;
	mes = idade % 365 / 30;
	dia = (idade % 365) % 30;
	
	
	printf("%d ano(s)\n", ano);
	printf("%d mes(es)\n", mes);
	printf("%d dia(s)", dia);
	
	printf("\n");
	return 0;
}