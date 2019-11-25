#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int numero;
	char aux[20];
	printf("insira um numero de 1 a 3:\n");
	scanf("%c",&aux);
	numero = atoi(aux);
	if(numero==0)
	{
		while(numero==0)
		{
			printf("insira um numero de 1 a 3:\n");
			scanf("%c",&aux);
			numero = atoi(aux);
		}
	}
	else printf("numero valido");
	return 0;
}

