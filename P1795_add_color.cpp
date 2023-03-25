#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
int vis[maxn],edge[maxn][maxn];
int n,k,m,ans=0;
int safe(int num,int x)
{
    for(int i=1;i<=n;i++)
    {
        if(edge[num][i]&&vis[i]==x)
        {
            return 0;
        }
    }
    return 1;
}
void dfs(int num)
{
    if(num>n)
    {
        ans++;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            if(safe(num,i))
            {
                vis[num]=i;
                dfs(num+1);
                vis[num]=0;
            }
        }
    }
    
}

int main()
{
    while(cin>>n>>k>>m)
    {
        memset(edge,0,sizeof(edge));
        memset(vis,0,sizeof(vis));
        //ans=0;
        for(int i=1;i<=k;i++)
        {
            int u,v;
            cin>>u>>v;
            edge[u][v]=edge[v][u]=1;
        }
        dfs(1);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
