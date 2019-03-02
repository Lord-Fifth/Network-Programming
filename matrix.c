/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 3(B)-To perform Matrix Multiplication using child processes and Addition using parent process. 
*/

#include <stdio.h>
main()
	{
	int pid,a[100][100],b[100][100],c[100][100],i,j,k,s,m,n;			// PARENT PROCESS PERFORMS MATRIX MULTIPLICATION.
											// CHILD PROCESS PERFORMS MATRIX ADDITION.
	printf("Enter the number of rows: ");
	scanf("%d",&m);
	printf("Enter the number of columns: ");
	scanf("%d",&n);
	printf("\nEnter the elements of first matrix: \n");
	for (i=0;i<m;i++)
		{
		for (j=0;j<n;j++)
			{
			scanf("%d",&a[i][j]);
			}
		}
	printf("\nEnter the elements of second matrix: \n");
	for (i=0;i<m;i++)
		{
		for (j=0;j<n;j++)
			{
			scanf("%d",&b[i][j]);
			}
		}
	pid=fork();
	if (pid==0)
		{
		printf("\nThis is the Child Process (Process ID = %d)",getpid());
		if (m!=n)
			{
			printf("Multiplication is not possible");
			}
		else
			{
			for (i=0;i<m;i++)
				{
				for (j=0;j<n;j++)
					{
					s=0;
					for (k=0;k<n;k++)
						{
						c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
						}
					}
				}
			printf("\nThe resultant matrix is: ");
			for (i=0;i<m;i++)
				{
				printf("\n");
				for (j=0;j<n;j++)
					{
					printf("%d\t",c[i][j]);
					}
				}
			}
		}
	else if (pid<0)
		{
		printf("ERROR: No Child process is created.\n");
		}
	else
		{
		printf("\nThis is the Parent Process (Process ID= %d)",getpid());
		for (i=0;i<m;i++)
			{
			for (j=0;j<n;j++)
				{
				c[i][j]=a[i][j]+b[i][j];
				}
			}
		printf("\nThe resultant matrix is: ");
		for (i=0;i<m;i++)
			{
			printf("\n");
			for (j=0;j<n;j++)
				{
				printf("%d\t",c[i][j]);
				}
			}
		}
	printf("\n");
	}

/*
OUTPUT

Enter the number of rows: 2
Enter the number of columns: 2

Enter the elements of first matrix: 
1
5
3
8

Enter the elements of second matrix: 
3
6
9
4

This is the Parent Process (Process ID= 3307)
The resultant matrix is: 
4	11	
12	12	

This is the Child Process (Process ID = 3309)
The resultant matrix is: 
48	26	
81	50	
*/
