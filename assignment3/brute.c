/** 
 *  @file	brute.c
 *  @brief	This c file contains function generate() which is called in main function of main_prog.c
 */
#include<stdio.h>
#include "function.h"

/**
 * A global integer value.
 */
int store[999999][4];
int k=-1; //!< Global variable


/*! \fn int iscopy(int a,int b,int c,int d)
\brief iscopy copies the four elements of set S entered by user
\param a One of the elements of set S 
\param b One of the elements of set S
\param c One of the elements of set S
\param d One of the elements of set S
\return integer 0 or 1
*/ 
int iscopy(int a,int b,int c,int d)
{
int i=0;
if (k==-1)
{	
	k++; 
	store[k][0]=a;store[k][1]=b;store[k][2]=c;store[k][3]=d;
	return 0;
}
else
{
	for(i=0;i<=k;i++)
	{
		if(store[i][0]==a && store[i][1]==b && store[i][2]==c && store[i][3]==d)
		return 1;
	}
	k++;
	store[k][0]=a;store[k][1]=b;store[k][2]=c;store[k][3]=d;
	return 0;
}
}

/*! \fn void generate(int arr[],int len,int lim)
\brief The generate function takes as an input a 1D array of length 'len' and the limit set as constraint, then applies the brute force approach to generate all len choose 4 combinations from the array elements. Each permutation is checked to satisfy the constraint or not, if the combination satisfies the constraint then it is outputted to the screen
\param arr An integer array
\param len Length of integer array (arr)
\param lim Limit or constraint for the expression (a + b + c * d)
\return Returns nothing as void function
*/ 
void generate(int arr[],int len,int lim)
{
	int i,j,k,l;
	int a,b,c,d,count=0;
	
	
	for(i=0;i<len;i++)
	{
		a=arr[i];
		for(j=0;j<len;j++)
		{	if(j!=i) 
				b=arr[j];
			else
				continue;
			
			for(k=0;k<len;k++)
			{	
				if(k!=i && k!=j) 
					c=arr[k];
				else
					continue;
				
				for(l=0;l<len;l++)
				{	
					if(l!=i && l!=j && l!=k) 
					d=arr[l];
					else
					continue;
				
					if ((a+b+c*d)<=lim && !iscopy(a,b,c,d))
						{printf("\n(%d,%d,%d,%d)\n",a,b,c,d);count++;}
				}
			}
		}
	}
	if(count)
	printf("Size: %d\n",count);
	else
	printf("No Solution Exits! \n");
}
			
