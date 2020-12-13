//physical layer code violation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp,*fp1;
	char c;
	fp=fopen("phyin.txt","w");
	while((c=getchar())!=EOF)
	{
		fputc(c,fp);
	}
	fclose(fp);
	fp=fopen("phyin.txt","r");
	fp1=fopen("phyinter.txt","w");
	fputs("10001",fp1);
	while((c=fgetc(fp))!=EOF)
	{
		if(c=='\n')
		{
			fputs("01101",fp1);
			fputc(c,fp1);
			fputs("10001",fp1);
		}
		else
		{
			fputc(c,fp1);
		}
	}
	fputs("01101",fp1);
	fclose(fp1);
	fclose(fp);
}