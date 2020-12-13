//byte stuffing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp,*fp1;
	char c,c1;
	int flag=1;
	fp=fopen("bysinter.txt","r");
	fp1=fopen("bysout.txt","w");
	while((c=fgetc(fp))!=EOF)
	{
		if(c=='E')
		{
			c1=fgetc(fp);
			fputc(c1,fp1);
		}
		else if(c=='F')
		{
		}
		else
		{
			fputc(c,fp1);
		}
	}
	//fputc('x',fp1);
	fclose(fp1);
	fclose(fp);
	fp=fopen("bysin.txt","r");
	fp1=fopen("bysout.txt","r");
	while(((c=fgetc(fp))!=EOF) && ((c1=fgetc(fp1))!=EOF))
	{
		if(c!=c1)
			flag=-1;
	}
	if(fgetc(fp)!=EOF || fgetc(fp1)!=EOF)
		flag=-1;
	fclose(fp1);
	fclose(fp);
	if(flag==-1)
	{
		printf("\n\nERROR occurred in the input,RETRANSMIT the data");
	}
	else
	{
		printf("\n\nData ACCEPTED");
	}
}

