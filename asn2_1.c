/*
Author:B M Sowrab
Function:Sales Based Application
Description:Computes the net profit/loss of the enterprise for one day.
Parameter: A csv File
Returns:Profit/Loss Amount
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void CreateLog(char *);
int getProfit(char *);

int main(int argc,char *argv[])
{
	int Profit=0,flag=0;
	char *cvalue1=NULL;
	int c;
	while((c=getopt(argc,argv,"f:"))!=-1)
	switch(c)
	{
		case 'f': 
	  			cvalue1=optarg;
				break;
	
		default:    
	  			printf("Please enter as -f <input_file>\n");
	        	return 1;
	}
	if(cvalue1==NULL)
	{
		printf("\nParameters required ");
		return 0;
	}
	Profit=getProfit(cvalue1);
	if(Profit>0)
		printf("Net Profit=Rs %d",Profit);
	else if(Profit<0)
		printf("Net Loss=Rs %d",(-1*Profit));
	else
		printf("\nNeither loss nor Profit");	
	return 0;

	
return 0;
}


int getProfit(char *cvalue1)
{
	FILE *fp,*f1;
	char str[100];
	int CostPrice,SellPrice,Profit=0;
	int i=0,j;


	char Cost[10],Sell[10];
	fp=fopen(cvalue1,"r");
	if(!fp)
	{
		printf("\nError opening file ");
		exit(1);
	}
	fgets(str,100,fp);
	while(!feof(fp))
	{
		i=0;j=0;
		fgets(str,100,fp);
		for(i=0;str[i]!=',';i++);
		i++;
		j=0;
		while(str[i]!=',')
		{
			if(!isdigit(str[i]))
			{
			printf("\nThe cost price field in csv file has to be digits ");
			exit(0);
			}
			Cost[j]=str[i];
			i++;j++;	
		}
		i++;
		Cost[j]='\0';
		j=0;
		while(str[i]!='\n')
		{	
			Sell[j]=str[i];
			i++;j++;
		}
		Sell[j]='\0';													
		CostPrice=atoi(Cost);
		SellPrice=atoi(Sell);
		Profit=Profit+(SellPrice-CostPrice);
	}
	fclose(fp);
	return Profit;
}

