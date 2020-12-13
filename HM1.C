//hamming code
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<conio.h>
int K,index[20];
struct table
{
	char s[20];
}t[100];
char* bin(int n,int x)
{
	char s[10];
	int i=0,r;
	while(n>0)
	{
		r=n%2;
		if(r==0)
		{
			s[i]='0';
		}
		else
		{
			s[i]='1';
		}
		n=n/2;
		i++;
	}
	s[i]='\0';
	//printf("\nstrlen : %d",strlen(s));
	if(strlen(s)<x)
	{
		while(1)
		{
			if(strlen(s)==x)
			{
				break;
			}
			else
			{
				s[i]='0';
				i++;
				s[i]='\0';
			}
		}
	}
	s[i]='\0';
	strrev(s);
	//printf("\n*strlen : %d",strlen(s));
	return(s);
}
void construct_table(int n)
{
	int i,x=0;
	while(1)
	{
		if(n>=pow(2,x))
		{
			x++;
		}
		else
		{
			break;
		}
	}
	//printf("\n x : %d",x);
	for(i=1;i<=n;i++)
	{
		strcpy(t[i].s,bin(i,x));
		//printf("\n%s",t[i].s);
	}
}
void get_indices(int n)
{
	int i,j=0;
	for(i=1;i<=n;i++)
	{
		if(t[i].s[K]=='1')
		{
			index[j]=i;
			j++;
		}
	}
	index[j]=-1;
      /*	printf("\n\n");
	for(i=0;i<=j;i++)
		printf("\t%d",index[i]);  */
	K--;
}
void main()
{
	FILE *fp,*fp1;
	char c,str[100];
	int m,r,n=0,i,k,ct,s;
	//clrscr();
	printf("\n\n");
	fp=fopen("hmin.txt","w");
	while((c=getchar())!=EOF)
	{
		fputc(c,fp);
		m=ftell(fp);
	}
	fclose(fp);
	r=0;
	while(1)
	{
	    s=pow(2,r);
	    if((m+r+1)<=s)
	    {
		break;
	    }
	    else
	    {
		r++;
	    }
	}
	n=m+r;
	//printf("\n n : %d",n);
	k=0;
	i=1;
	fp=fopen("hmin.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		s=pow(2,k);
		if(i==s)
		{
			str[i]='-';
			ungetc(c,fp);
			k++;
		}
		else
		{
			str[i]=c;
		}
		i++;
	}
	fclose(fp);
	str[i]='\0';
	construct_table(n);
	K=m-2;
	for(i=1;i<=n;i++)
	{
		if(str[i]=='-')
		{
			get_indices(n);
			m=0;
			ct=0;
			while(index[m]!=-1)
			{
				if(str[index[m]]=='1')
					ct++;
				m++;
			}
			if(ct%2==0)
				str[i]='0';
			else
				str[i]='1';
		}
		printf("\n%c",str[i]);
	}
	str[i]='\0';
	/*printf("\n\n");
	for(i=1;i<strlen(str);i++)
		printf("%c",str[i]);  */
	fp=fopen("hminter.txt","w");
	for(i=1;i<=n;i++)
		fputc(str[i],fp);
	fclose(fp);
}