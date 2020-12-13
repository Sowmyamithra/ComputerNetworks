//Dijkstras Algorithm for shortest path
#include<bits/stdc++.h>

using namespace std;

struct Edge
{
	int v,d;
	public:
	Edge(int inV,int inD)
	{
		v = inV;
		d = inD;
	}
};

vector<pair<int,int>> list;
int nv,ne;
map<int,vector<Edge>> network;
int src,dest;
vector<int> dist;
vector<int> parent;
vector<bool> visited;

int getMinVertex()
{
	int mn = INT_MAX;
	int mnV = -1;
	for(int v = 1;v <= nv;v++)
	{
		if(!visited[v] && dist[v] < mn)
		{
			mn = dist[v];
			mnV = v;
		}
	}
	return mnV;
}
void getShortestPath()
{
	for(int i = 0;i <= nv;i++)
	{
		dist.push_back(INT_MAX);
		parent.push_back(-1);
		visited.push_back(false);	
	}
	dist[src] = 0;
	parent[src] = -1;
	
	//algorithm starts
	while(true)
	{
		int u = getMinVertex();//get the unvisited vertex with minimum distance4
		if(u == -1)
		{
			break;
		}	
		for(int i = 0;i < network[u].size();i++)
		{
			int v = network[u][i].v;
			int d = network[u][i].d;
			if(visited[v])
			{
				continue;
			}
			int alt = dist[u] + d;
			if(alt < dist[v])
			{
				dist[v] = alt;
				parent[v] = u;
				list.push_back(pair(u,v));
			}
		}
		visited[u] = true;	
	}
}

int main()
{
	//creating the adjacency list
	printf("\nGet the number of vertices and edges : ");
	scanf("%d%d",&nv,&ne);
	int u,v,dis;
	for(int i = 0;i < ne;i++)
	{
		printf("\nenter the edge in u-->v and also the distance");
		scanf("%d%d%d",&u,&v,&dis);
		network[u].push_back(Edge(v,dis));
		network[v].push_back(Edge(u,dis));
	}
	
	//to find shortest path between given source and destination
	printf("\nEnter the source : ");
	scanf("%d",&src);
	getShortestPath();	
	printf("\nBroadcast tree : ");
	for(int i = 0;i < list.size();i++)
	{
		printf("\n %d -> %d",list[i].first,list[i].second);
	}
	return 0;
}