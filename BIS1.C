//bit stuffing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp,*fp1;
	char c;
	int ct=0;
	fp=fopen("bisin.txt","w");
	while((c=getchar())!=EOF)
	{
		fputc(c,fp);
	}
	fclose(fp);
	fp=fopen("bisin.txt","r");
	fp1=fopen("bisinter.txt","w");
	while((c=fgetc(fp))!=EOF)
	{
		 if(c=='1')
		 {
			ct=0;
			while(c=='1')
			{
				fputc(c,fp1);
				ct++;
				c=fgetc(fp);
				if(ct==5)
					break;
			}
			if(ct==5)
			{
				fputc('0',fp1);
			}
			ungetc(c,fp);
		 }
		 else
		 {
			fputc(c,fp1);
		 }
	}
	//fputc('1',fp);
	fclose(fp1);
	fclose(fp);
}
