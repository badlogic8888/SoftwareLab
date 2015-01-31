/** 
 *  @file	main_prog.c
 *  @brief	Find all possible subsets(a,b,c,d) such that a + b + c * d < k where k & set S are to be read from user as comma-separated values
 */
#include<stdio.h>
#include "function.h"

/**
 * Global array
 */
int arr[100]; 
/**
 * Global variable
 */
int i=0;
/**
 * Global variable
 */
int digit=0;
/**
 * Global variable
 */
int flag=0;

/*! \fn char func()
\brief The function takes input from the user through the stdin, it takes character by character input and keeps populating the array dynamically, the values to be entered is comma separated and unique. Also a number cannot be more than 6 digits long
*/
char func()
{
char ch=getchar();

if(ch=='-')
	flag=1;
	
else if(ch>='0' && ch<='9')
{
	digit++;
	if(flag)
		arr[i]=-arr[i]*10-(ch-'0');
	else
		arr[i]=arr[i]*10+ch-'0';
	if(digit>=6)
	{
	printf("Too Long input..exiting \n");
	exit(-1);
	}
}
else if(ch==',')
{
	flag=0;
	
	i++;
	digit=0;
	arr[i]=0;
}
else if (ch=='\n')
	return 'e';
	
else
{
	printf("Illegal Input format");
	exit(-1);
}

return 'o';
}

/*! \fn int main()
\brief Main function
\return an integer 0 upon exit success
*/
int main()
{
arr[0]=0;
int j=0,lim;

printf("Enter array:");
while(func()!='e');

for(j=0;j<=i;j++)
	printf("%d\n",arr[j]);
	
printf("Enter Limit:");
scanf("%d",&lim);	

i++;
generate(arr,i,lim);

	return 0;
}
