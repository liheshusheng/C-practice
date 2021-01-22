#include<stdio.h>

int main(void)
{
	int i, j;
	int a[1024][1024];
	for (i = 0; i < 1024; i++)
		for (j = 0; j < 1024; j++)
			//for (k = 0; k < 4096; k++)
		{

			a[i][j] = i + j;
			printf("%d\t", a[i][j]);
		}
	return 0;
}
