//bit stuffing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp,*fp1;
	char c,c1;
	int flag=1;
	int ct=0;
	fp=fopen("bisout.txt","w");
	fp1=fopen("bisinter.txt","r");
	while((c=fgetc(fp1))!=EOF)
	{
		 if(c=='1')
		 {
			ct=0;
			while(c=='1')
			{
				fputc(c,fp);
				ct++;
				c=fgetc(fp1);
				if(ct==5)
					break;
			}
			if(ct!=5)
				ungetc(c,fp1);
		 }
		 else
		 {
			fputc(c,fp);
		 }
	}
	//fputc('1',fp);
	fclose(fp1);
	fclose(fp);
	fp=fopen("bisin.txt","r");
	fp1=fopen("bisout.txt","r");
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
