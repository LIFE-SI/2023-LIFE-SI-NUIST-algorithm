#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int p=998244353;
int a[maxn];
int vis[maxn];
int fa[maxn];
int find(int x)
{
    if(fa[x]==x)
        return x;
    else
    {
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
int quick_pow(int x,int b,int p) 
{
    if(b==0)
        return 1;
    if(b==1)
        return x%p;
    long long temp=quick_pow(x,b/2,p);
    temp=temp*temp%p;
    if(b%2==0)
        return temp;
    else
        return temp*x%p;
    
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            int x=find(i), y=find(a[i]);
            if(x!=y)
            {
                fa[x]=y;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==i)
            cnt++;
    }
    int ans=quick_pow(2,cnt,p)-1;
    cout<<ans<<endl;
    return 0;
}