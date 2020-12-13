//Distance vector routing algorithm
#include<bits/stdc++.h>

using namespace std;

int nv,ne;
int network[50][50];
int dist[50][50];

void getShortestPathAll()
{
	for(int i = 1; i <= nv;i++)
	{
		for(int j = 1;j <= nv;j++)
		{
		    if(network[i][j] > 0)
			{
				dist[i][j] = network[i][j];
			}
			else if(i == j)
			{
		       dist[i][j] = 0;
			}
			else
			{
				dist[i][j] = INT_MAX;
			}
		}
	}
	
	//algorithm starts
	printf("\n");
	for(int k = 1;k < nv;k++)
	{
		for(int i = 1;i <= nv;i++)
		{
			for(int j = 1;j <= nv;j++)
			{
				long long alt = (long)dist[i][k] + dist[k][j];
				if(dist[i][j] > alt)
				{
					dist[i][j] = alt;
				}
			}
		}
	}
}

void printMat()
{
	printf("\n\n");
	for(int i = 1;i <= nv;i++)
	{
		printf("\n For vertex %d \n",i);
		for(int j = 1;j <= nv;j++)
		{
			printf("%d\t",dist[i][j]);
		}
	}
}

int main()
{
	//creating the edge list
	printf("\nenter the number of vertices and edges : ");
	scanf("%d%d",&nv,&ne);
	int u,v,dis;
	for(int i = 0;i < ne;i++)
	{
		printf("\nenter the edges in u-->v and distance");
		scanf("%d%d%d",&u,&v,&dis);
		network[u][v] = dis;
	}

	//finding the shortest path between all pair of vertices
	getShortestPathAll();
	printMat();
	return 0;
}
