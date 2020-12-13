//byte stuffing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp,*fp1;
	char c;
	fp=fopen("bysin.txt","w");
	while((c=getchar())!=EOF)
	{
		fputc(c,fp);
	}
	fclose(fp);
	fp=fopen("bysin.txt","r");
	fp1=fopen("bysinter.txt","w");
	fputc('F',fp1);
	while((c=fgetc(fp))!=EOF)
	{
		if(c=='\n')
		{
			fputc('F',fp1);
			fputc(c,fp1);
			fputc('F',fp1);
		}
		else if(c=='E')
		{
			fputc('E',fp1);
			fputc(c,fp1);
		}
		else if(c=='F')
		{
			fputc('E',fp1);
			fputc(c,fp1);
		}
		else
		{
			fputc(c,fp1);
		}
	}
	fputc('F',fp1);
	fclose(fp1);
	fclose(fp);
}

