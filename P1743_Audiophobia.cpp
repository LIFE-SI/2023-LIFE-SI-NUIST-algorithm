#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f;
const int maxn=1005;
//int edge[maxn][maxn];
//int vis[maxn];
int dis[maxn][maxn];
int n,m,q;
int qu[maxn*10],qv[maxn*10];
//int maxw[maxn][maxn];
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][k]!=INF&&dis[k][j]!=INF)
                {

                    if(dis[i][k]<dis[i][j]&&dis[k][j]<dis[i][j])
                        dis[i][j]=max(dis[i][k],dis[k][j]);
                    // if(dis[i][j]>=dis[i][k]+dis[k][j])
                    // {
                    //     dis[i][j]=dis[i][k]+dis[k][j];
                    //     maxw[i][j]=max(maxw[i][k],maxw[k][j]);
                    // }
                    // else if(dis[i][j]==dis[i][k]+dis[k][j])
                    // {
                    //     dis[i][j]=dis[i][k]+dis[k][j];
                    //     maxw[i][j]=max(max(maxw[i][k],maxw[k][j]),maxw[i][j]);
                    // }
                }
                
            }
        }
    }
}
int main()
{
    int k=1;
    while(cin>>n>>m>>q)
    {
        //memset(dis,INF,sizeof(dis));
        //memset(maxw,0,sizeof(maxw));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=INF;
        // for(int i=1;i<=n;i++)
        //     dis[i][i]=0;
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            dis[u][v]=dis[v][u]=w;
            //maxw[u][v]=maxw[v][u]=w;
        }
        floyd();
        for(int i=1;i<=q;i++)
        {
            cin>>qu[i]>>qv[i];
        }
        cout<<"Case #"<<k++<<endl;
        for(int i=1;i<=q;i++)
        {
            if(dis[qu[i]][qv[i]]!=INF)
                cout<<dis[qu[i]][qv[i]]<<endl;
            else
                cout<<"no path"<<endl;
        }
    }
    return 0;
}
