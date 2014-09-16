/*
Author:B M Sowrab
Function:Sales Based Application
Description:Computes the net profit/loss of the enterprise for one day.
Parameter: A csv File
Returns:Profit/Loss Amount of used and unused item 
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void CreateLog(char *);
int getProfit(char *,int*);

int main(int argc,char *argv[])
{
	int flag=0;
	char *cvalue1=NULL;
	int c;
	int Profit[2]={0,0};
	
	while((c=getopt(argc,argv,"f:"))!=-1)
	switch(c)
	{
		case 'f': 
	  			cvalue1=optarg;
				break;
	
		default:    
	  			printf("Please enter as -f <input_file> \n");
	        	return 1;
	}
	if(cvalue1==NULL)
	{
		printf("\nParameters required ");
		return 0;
	}
	getProfit(cvalue1,Profit);
	if(Profit[0]>0)
		printf("\nNet Profit(Used items)=Rs %d",Profit[0]);
	else if(Profit[0]<0)
		printf("\nNet Loss(Used items)=Rs %d",(-1*Profit[0]));
	else
		printf("\nNeither loss nor Profit(Used items)");	
	if(Profit[1]>0)
		printf("\nNet Profit(Unused items)=Rs %d",Profit[1]);
	else if(Profit[1]<0)
		printf("\nNet Loss(Unused items)=Rs %d",(-1*Profit[1]));
	else
		printf("\nNeither loss nor Profit(Unused items)");	

return 0;

}


int getProfit(char *cvalue1,int *Profit)
{
	FILE *fp,*f1;
	char str[100],item_type[50];
	int CostPrice,SellPrice;
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
		while(str[i]!=',')
		{
			Sell[j]=str[i];
			i++;j++;	
		}
		i++;
		Sell[j]='\0';
		j=0;
		while(str[i]!='\n')
		{
			item_type[j]=str[i];
			i++;j++;	
		}
		item_type[j]='\0';
		for(i=0;Sell[i]!='\0';i++)
		{
			if(!isdigit(Sell[i]))
			{
				printf("\nThe selling price field in csv file has to be digits ");
				exit(0);
			}
		}
		CostPrice=atoi(Cost);
		SellPrice=atoi(Sell);		
		if(item_type[1]=='s')
		{	
			Profit[0]=Profit[0]+(SellPrice-CostPrice);
		}
		else if(item_type[1]=='n')
		{
			Profit[1]=Profit[1]+(SellPrice-CostPrice);
		}
		else 
		{
			printf("\nInvalid item type given in file");
			exit(1);		
		}
	}	
	fclose(fp);
}
