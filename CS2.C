//checksum
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char* dbin(int num)
{
	int r,i=0;
	char s[20];
	while(num>0)
	{
		r=num%2;
		if(r==0)
			s[i]='0';
		else
			s[i]='1';
		i++;
		num=num/2;
	}
	s[i]='\0';
	if(strlen(s)<4)
	{
		for(r=i;strlen(s)<4;r++)
		{
			s[r]='0';
		}
	}
	strrev(s);
	return(s);
}
int bind(char *s)
{
	int sum=0,l=0,i;
	for(i=strlen(s)-1;i>=0;i--)
	{
		if(s[i]=='1')
		{
			sum=sum+pow(2,l);
		}
		l++;
	}
	return(sum);
}
void main()
{
	FILE *fp,*fp1;
	int ct=0,index=0,i=0,sum=0;
	char c,s[20],s1[10],s2[10];
	fp=fopen("csinter.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		ct=0;
		strcpy(s,"");
		index=0;
		while(ct<=3)
		{
			s[index]=c;
			index++;
			ct++;
			c=fgetc(fp);
		}
		s[index]='\0';
		sum=sum+bind(s);
		ungetc(c,fp);
		strcpy(s,"");
	}
	fclose(fp);
	strcpy(s,dbin(sum));
	i=(strlen(s)-4)-1;
	index=0;
	while(index<=i)
	{
		s2[index]=s[index];
		index++;
	}
	s2[index]='\0';
	i=0;
	while(index<strlen(s))
	{
		s1[i]=s[index];
		index++;
		i++;
	}
	s1[i]='\0';
	sum=0;
	sum=bind(s1)+bind(s2);
	strcpy(s,dbin(sum));
	printf("\n\n s = %s",s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='1')
			s[i]='0';
		else
			s[i]='1';
	}
	printf("\n\n s = %s",s);
	if(strcmp(s,"0000")==0)
	{
		fp=fopen("csin.txt","r");
		fp1=fopen("csout.txt","w");
		while((c=fgetc(fp))!=EOF)
		{
			fputc(c,fp1);
		}
		fclose(fp1);
		fclose(fp);
		printf("\n\nData ACCEPTED");
	}
	else
	{
		printf("\n\nERROR occurred,RETRANSMIT the data");
	}
}