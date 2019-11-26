#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int numero;
	char aux;
	
	for (;;)
	{
		printf("insira um numero de 1 a 3:\n");
		scanf("%c",&aux);
		if(aux > '3' || aux < '1') 
		{
			fflush(stdin);
			continue;
		}
		numero = aux-'0';
		break;	
	}
	return 0;
}


