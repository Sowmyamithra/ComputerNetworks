//cyclic redundancy check
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char* xor(char *F,char *G)
{
	char res[10];
	int i=0;
	while(i<strlen(F))
	{
		if((F[i]=='0' && G[i]=='0') || (F[i]=='1' && G[i]=='1'))
			res[i]='0';
		else
			res[i]='1';
		i++;
	}
	res[i]='\0';
	return(res);
}
char xor1(char c,char c1)
{
	if((c=='1' && c1=='1') || (c=='0' && c1=='0'))
		return('0');
	else
		return('1');
}
void main()
{
	FILE *fp,*fp1;
	char c,c1,G[100],rem[10],F[100];
	int ct=0,i,degree=0,j=0,k=0,ft=0;
	printf("\nEnter G(x) : ");
	gets(G);
	fp=fopen("crcin.txt","w");
	while((c=getchar())!=EOF)
	{
		fputc(c,fp);
		ft=ftell(fp);
	}
	fclose(fp);
	for(i=0;i<strlen(G);i++)
	{
		if(G[i]=='1')
		{
			degree=i;
			break;
		}
	}
	degree=strlen(G)-1-degree;
	fp=fopen("crcin.txt","a");
	while(ct<degree)
	{
		fputc('0',fp);
		ct++;
		ft++;
	}
	fclose(fp);
	j=0;
	ct=0;
	strcpy(F,"");
	fp=fopen("crcin.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		while(ct<=degree)
		{
			F[j]=c;
			j++;
			ct++;
			printf("\n c : %c",c);
			c=fgetc(fp);
		}
		F[j]='\0';
		strcpy(rem,"");
		strcpy(rem,xor(F,G));
		rem[4]='\0';
		printf("\nF : %s , G : %s , rem : %s",F,G,rem);
		i=0;
		while(i<strlen(rem))
		{
			if(rem[i]=='1')
				break;
			i++;
		}
		k=0;
		j=0;
		strcpy(F,"");
		while(i<strlen(rem))
		{
			F[j]=rem[i];
			i++;
			j++;
			k++;
		}
		ct=k;
		ungetc(c,fp);
	}
	fclose(fp);
	j=0;
	fp=fopen("crcin.txt","r");
	fp1=fopen("crcinter.txt","w");
	while((c=fgetc(fp))!=EOF)
	{
		if(ftell(fp)>=(ft-degree))
		{
			c1=rem[j];
			j++;
			fputc(xor1(c,c1),fp1);
		}
		else
		{
			fputc(c,fp1);
		}
	}
	fclose(fp1);
	fclose(fp);
}