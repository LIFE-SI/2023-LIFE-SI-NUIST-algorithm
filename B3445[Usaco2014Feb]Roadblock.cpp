#include<bits/stdc++.h>
using namespace std;
const int maxn=252;
int n,m;
queue<int> que;
int vis[maxn];
int e[maxn][maxn];
int dis[maxn];
int st[250001],en[250001];
void SPFA(int x)
{	
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f3f,sizeof(dis));
	vis[x]=1;
	dis[x]=0;
	que.push(x);
	while(!que.empty())
	{
		int temp=que.front();
		
		for(int i=1;i<=n;i++)
		{
			if(e[temp][i]!=0x3f3f3f)
				if(dis[i]>dis[temp]+e[temp][i])
				{
					dis[i]=dis[temp]+e[temp][i];
					if(vis[i]==0)
					{
						vis[i]=1;
						que.push(i);
					}
				}
		}
		que.pop();
		vis[temp]=0;
	}
}
int main()
{
	int u,v,w;
	cin>>n>>m;
	memset(e,0x3f3f3f,sizeof(e));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[u][v]=w;
		e[v][u]=w;
		st[i]=u;
		en[i]=v;
	}
	SPFA(1);
	int res=dis[n];
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		e[st[i]][en[i]]*=2;
		e[en[i]][st[i]]*=2;
		SPFA(1);
		ans=max(ans,dis[n]);
		e[st[i]][en[i]]/=2;
		e[en[i]][st[i]]/=2;
	}
	cout<<ans-res<<endl;
	return 0;
}
