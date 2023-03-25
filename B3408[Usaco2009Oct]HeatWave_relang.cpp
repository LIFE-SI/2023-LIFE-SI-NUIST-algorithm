#include<bits/stdc++.h>
using namespace std;
const int maxn=6205;
struct edge
{
	int v,w;
};
int n,m,s,t;
int u,v,w;
queue<int> que;
int vis[maxn];
int dis[maxn];
vector<edge> e[maxn];

void SPFA(int x)
{	
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	dis[x]=0;
	que.push(x);
	while(!que.empty())
	{
		int temp=que.front();
		que.pop();
		vis[temp]=0;
		int len=e[temp].size();
		for(int i=0;i<len;i++)
		{
			int v=e[temp][i].v,w=e[temp][i].w;
			if(dis[v]>dis[temp]+w)
			{
				dis[v]=dis[temp]+w;
				if(!vis[v])
				{
					vis[v]=1;
					que.push(v);
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m>>s>>t;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge temp;
		temp.v=v;
		temp.w=w;
		e[u].push_back(temp);
		temp.v=u;
		e[v].push_back(temp);//无向
	}
	SPFA(s);
	cout<<dis[t]<<endl;
	return 0;
}
