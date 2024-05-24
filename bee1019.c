#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int valor, hora = 0, minuto = 0, segundo = 0;
	
	scanf("%d", &valor);
	
	hora = valor / 3600;
	minuto = valor % 3600 / 60;
	segundo = valor % 60;
	
	
	
	printf("%d:%d:%d", hora, minuto, segundo);
	printf("\n");
	return 0;
}