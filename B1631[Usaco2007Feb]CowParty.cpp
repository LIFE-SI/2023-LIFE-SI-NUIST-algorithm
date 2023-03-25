#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct edge
{
	int v,w;
};
int n,m,x;
int u,v,w;
queue<int> que;
int vis[maxn];
int dis[2][maxn];
vector<edge> e[2][maxn];

void SPFA(int k)
{	
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	dis[k][x]=0;
	que.push(x);
	while(!que.empty())
	{
		int temp=que.front();
		que.pop();
		vis[temp]=0;
		int len=e[k][temp].size();
		for(int i=0;i<len;i++)
		{
			int v=e[k][temp][i].v,w=e[k][temp][i].w;
			if(dis[k][v]>dis[k][temp]+w)
			{
				dis[k][v]=dis[k][temp]+w;
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
	cin>>n>>m>>x;
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge temp;
		temp.v=v;
		temp.w=w;
		e[0][u].push_back(temp);
		temp.v=u;
		e[1][v].push_back(temp);
	}
	SPFA(0);
	SPFA(1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dis[0][i]+dis[1][i]);
	}
	cout<<ans<<endl;
	return 0;
}