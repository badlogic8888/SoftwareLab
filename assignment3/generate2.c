#include<stdio.h>
//#include"function.h"

#define UNASSIGNED 0

/*the solve() function uses backtracking to generate all possible subsets from a given set of values, which satisfies the given constraint and print them out*/

int assign[]={0,0,0,0};
int lim;

int issafe(int arr[],int num,int pos)
{
int i;
for (i=0;i<4;i++)
{
	if (arr[i]==num)
		return 0;
}
arr[pos]=num;
if (arr[0]+arr[1]+arr[2]*arr[3]>lim)
{	
	arr[pos]=UNASSIGNED;
	assign[pos]=0;
	return 0;
}

return 1;
}

int findnextunassigned(int arr[],int *pos)
{
int i=0;
for(i=0;i<4;i++)
{
	if(arr[i]==UNASSIGNED && assign[i]==0)
	{
		assign[i]=1;
		*pos=i;
		return 1;
	}
}
return 0;
}

int solve(int arr1[],int arr2[],int len)
{
int pos,i=0;
if (!findnextunassigned(arr1,&pos))
{
	for(i=0;i<4;i++)
		printf("%d ",arr1[i]);
	printf("\n");
	return 0;
}

for (i=0;i<len;i++)
{
	if(issafe(arr1,arr2[i],pos))
	{
		solve(arr1,arr2,len);
		assign[pos]=0;
		arr1[pos]=UNASSIGNED;
	}
}
return 0;
}

int main()
{
int arr2[4],num=0,i=0,temp;
char ch;
printf("Enter Array: ");
if(scanf("%d,%d,%d,%d,%d",arr2,(arr2+1),(arr2+2),(arr2+3),&temp)!=4)
{
	printf("Input format error\n");
	exit(-1);
}
printf("Enter Limit: ");
scanf("%d",&lim);
int arr1[]={UNASSIGNED,UNASSIGNED,UNASSIGNED,UNASSIGNED};
solve(arr1,arr2,4);
}
	
	
	
	
	
	
	
