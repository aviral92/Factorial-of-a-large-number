// PROGRAM TO FIND FACTORIAL OF A BIG NUMBER WHICH CANNOT FIT IN A SINGLE VARIABLE.
/***********************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 200
void initarr(int num[]);
void factorial(int num[],int fact[]);
int  checkif0(int num[]);
void copyarr(int a[],int num[]);
void decrement(int a[]);
void multiply(int num[],int fact[],int a[]);

/************************************************************************************************/

int main()
{
    int num[MAX],fact[MAX],i,l,n;
	char s[MAX+1];  /*extra space for NULL*/
	  clrscr();
	printf("Enter the number : ");
	scanf("%s",s);

	l=strlen(s);
	n=l;
      /*initialising to zero*/
	initarr(num);
	initarr(fact);

	/*creating numeric array from string*/
	for(i=0;i<l;i++)
		num[MAX-i-1]=s[l-i-1]-'0';

	factorial(num,fact);

	printf("\n\nFactorial of the number is : ");

	for(i=0;fact[i]==0;i++);

	for(;i<MAX;i++)
	{
		printf("%1d",fact[i]);
	}

	getch();
    return 0;
}


void initarr(int num[])
{   	int i;
	for(i=0;i<MAX;i++)
		num[i]=0;
	return;
}
int checkif0(int num[])
{
	int i;

	for(i=0;i<MAX;i++)
		if(num[i]!=0)
			return 0;
	return 1;
}

void copyarr(int a[],int num[])
{
	int i;
	for(i=0;i<MAX;i++)
		a[i]=num[i];
	return;
}


void factorial(int num[],int fact[])
{
	int i,a[MAX];

	if(checkif0(num))
	{
		for(i=0;i<MAX-1;i++)
			fact[i]=0;

		fact[i]=1;
	}
	else
	{
		copyarr(a,num); /* copies original array num to temorary a*/

		decrement(a); /* reduce number by 1*/

		factorial(a,fact);									// finds factorial of a and puts it in f.

		initarr(a);

		multiply(num,fact,a);

		copyarr(fact,a);									// copies a to f.
	}

	return;
}

  void decrement(int b[])
  {                                                                                           int i;
  for(i=MAX-1;i>=0;i--)
  {
    if(b[i]==0)
     {
	b[i]=9;
	}
    else
      {b[i]--;
       break;
  }     }
 }

/************************************************************************************************/

void multiply(int n[],int f[],int a[])
{
	int i=0,j,k,c=0;

	while(n[i]==0)
		  i++;

	for(;i<MAX;i++)
	{                       c=0;
		for(j=MAX-1;j>=0;j--)
		{
			a[j]=a[j]+c+(n[i]*f[j]);
			if(a[j]>9)
			{
				c=a[j]/10;
				a[j]=a[j]%10;
			}
			else
				c=0;
		}
		for(k=0;k<MAX-1;k++)
			a[k]=a[k+1];
		a[k]=0;
	}

	for(k=MAX-2;k>=0;k--)
	{
		a[k+1]=a[k];
	}

	a[0]=0;

	return;
}

output:

Enter the number : 33


Factorial of the number is : 8683317618811886495518194401280000000


Enter the number : 60


Factorial of the number is :8320987112741390144276341183223364380754172606361245952449277696409600000000000000