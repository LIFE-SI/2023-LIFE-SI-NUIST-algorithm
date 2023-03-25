#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int edge[maxn],dot[maxn];
int fa[maxn];

int find(int x)
{
    if(fa[x]==x)
        return x;
    else
    {
        return fa[x]=find(fa[x]);
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int sign=1;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        //cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
            dot[i]=1;
            edge[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            //cin>>u>>v;
            scanf("%d%d",&u,&v);
            int x=find(u),y=find(v);
            if(x!=y)
            {
                fa[x]=y;
                edge[y]=edge[y]+edge[x]+1;
                dot[y]=dot[y]+dot[x];
            }
            else
            {
                edge[x]++;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(fa[i]==i)
            {
                if(edge[i]>dot[i])//小于最大为-1
                    ans=ans+edge[i]-dot[i];
            }
        }
        //cout<<"Case #"<<sign++<<": "<<ans<<endl;
        printf("Case #%d: %d\n",sign++,ans);
    }
    return 0;
}