#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5005;
const ll INF=9e18;//一定要很大！！！我~无语！！！
struct node
{
    ll x,y;
}a[maxn];
int t,n;
ll res;
bool vis[maxn];
ll dis[maxn][maxn],w[maxn];
ll slen(int i,int j)
{
    ll ans=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
    return ans;
}
ll prim()
{
    for(int i=1;i<=n;i++)
        w[i]=INF,vis[i]=0;
    ll u=1;
    vis[u]=1;
    w[u]=0;
    ll ans=0;
    for(ll i=1;i<n;i++)
    {
        for(int v=1;v<=n;v++)
        {
            if(!vis[v]&&w[v]>dis[u][v])
            {
                w[v]=dis[u][v];
            }
        }
        ll minlen=INF;
        for(int v=1;v<=n;v++)
        {
            if(!vis[v]&&minlen>w[v])
            {
                minlen=w[v];
                u=v;
            }
        }
        vis[u]=1;
        ans=max(ans,minlen);
        
    }
    return ans;
}

int main()
{
    cin>>t;
    while(t--)
    {
        memset(dis,0,sizeof(dis));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y;
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                dis[i][j]=dis[j][i]=slen(i,j);
            }
        }
        res=prim();
        cout<<res<<endl;
    }
    return 0;
}