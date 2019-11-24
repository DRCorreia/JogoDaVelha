int verifica_linhas(char matriz)
{
int i , j ,  somaX=0 ,  somaO=0;
	for(i=0;i<3;i++)
	{
		for(j=0;i<3;i++)
		{
			if(matriz[i][j]=='X')somaX+=1;
			if(matriz[i][j]=='O')somaO+=1;
			if(somaX==3 || somaO==3) return 1;
		}
	 somaX=0;
	 somaO=0;
	}
return 0;
}
