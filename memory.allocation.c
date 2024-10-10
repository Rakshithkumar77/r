#include <stdio.h>
#include <conio.h>
void main()
{
	int frag[10], b[10], f[10], i, j, nb, nf, temp;
	int isalloted[10], allotedb[10];
	printf("\n\t Memory Management Scheme - First Fit");
	printf("\n Enter the number of blocks:");
	scanf("%d", &nb);
	printf(" Enter the number of files:");
	scanf("%d", &nf);
	printf("\n Enter the size of the blocks:-\n");
	for (i = 1; i<= nb; i++)
	{
		printf(" Block %d:", i);
		scanf("%d", &b[i]);
	}
	printf(" Enter the size of the files :-\n");
    for (i = 1; i<= nf; i++)
    {
    	printf("File %d:", i);
		scanf("%d", &f[i]);
    }
	for (i = 1; i<= nf; i++)
	{
	temp=-1;
	for (j = 1; j <= nb; j++)
	{
		if (isalloted[j] != 1)
	{
		if(b[j]>=f[i])
	{
		frag[i]= b[j] - f[i];
		allotedb[i] = j;
		temp=j;
		isalloted[j]=1;
		break;
	}
	}
	}
	if (temp==-1)
	allotedb[i]=-1;
	}
	printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
	for (i = 1; i<= nf; i++)
	{
		if(allotedb[i]!=-1)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], allotedb[i], b[allotedb[i]], frag[i]);
	}
	else
	{
		printf("\n%d\t\t%d\t\t", i, f[i]);
		printf(" not allocated\n");
	}
	}
}