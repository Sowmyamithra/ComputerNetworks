//parity
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp,*fp1;
	int i=0,ct=0,ct1=0;
	char c;
	fp=fopen("parin.txt","r");
	while((c=fgetc(fp))!=EOF)
		i=ftell(fp);
	fclose(fp);
	fp1=fopen("parout.txt","w");
	fp=fopen("parinter.txt","r");
	i=(int)(i/4);
	while(ct1<=3)
	{
		ct=0;
		c=fgetc(fp);
		while(ct<=3)
		{
			fputc(c,fp1);
			ct++;
			c=fgetc(fp);
		}
		ct1++;
	}
	fclose(fp1);
	fclose(fp);
}