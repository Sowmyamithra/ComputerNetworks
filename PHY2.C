//physical layer code violation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp,*fp1;
	char c,c1;
	int ct=0,flag=1;
	fp=fopen("phyinter.txt","r");
	fp1=fopen("phyout.txt","w");
	c='\n';
	while(1)
	{
		if(c=='\n')
		{
			ct=0;
			while(ct<5 && c!=EOF)
			{
				c=fgetc(fp);
				ct++;
			}
			ct=0;
			while(ct<4 && c!=EOF)
			{
				c=fgetc(fp);
				fputc(c,fp1);
				ct++;
			}
			ct=0;
			while(ct<5 && c!=EOF)
			{
				c=fgetc(fp);
				ct++;
			}
			c=fgetc(fp);
			if(c!=EOF)
			{
				fputc('\n',fp1);
			}
		}
		if(c==EOF)
			break;
	}
	fclose(fp1);
	fclose(fp);
	fp=fopen("phyin.txt","r");
	fp1=fopen("phyout.txt","r");
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
		printf("\n\nERROR occurred,RETRANSMIT the data");
	else
		printf("\n\nData ACCEPTED");
}