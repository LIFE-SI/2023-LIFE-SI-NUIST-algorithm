#include<bits/stdc++.h>
using namespace std;
#define int long long//此题需要借助龙龙的力量才能A
const int maxn=1e4+5;
//vector<pair<int ,int>>node;
int pret[maxn],preh[maxn],dp[maxn];
bool jud[maxn];
int ans;

inline int read()
{
    int w=1,s=0;
    char c=' ';
    while(c!='-'&&(c<'0'||c>'9'))
    {
        c=getchar();
    }
    if(c=='-')
    {
        w=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        s=s*10+c-'0';
        c=getchar();
    }
    return w*s;
}


struct node
{
    int t,b,h;
}a[maxn];

bool cmp(node x,node y)
{
    return x.b<y.b;
}

signed main()
{
    int N=read(),T=read();
    //cin>>N>>T;
    for(int i=1;i<=N;i++)
    {
        a[i].t=read(),a[i].b=read(),a[i].h=read();
        //cin>>a[i].t>>a[i].b>>a[i].h;
    }
    sort(a+1,a+1+N,cmp);
    jud[0]=true;
    //cout<<1<<endl;
    for(int i=1;i<=N;i++)
    {
        //cin>>a[i].t>>a[i].b>>a[i].h;
        
        pret[i]=pret[i-1]+a[i].t;
        preh[i]=preh[i-1]+a[i].h;
        if(pret[i]<=T&&jud[i-1]&&pret[i]<=a[i].b)
        {
            jud[i]=true;
        }
    }
    //\cout<<1<<endl;
    for(int i=N;i>=0;i--)
    {
        for(int j=T;j>=a[i+1].t;j--)
        {
            dp[j]=dp[j];
            if(j>=a[i+1].t)
            {
                dp[j]=max(dp[j],dp[j-a[i+1].t]+a[i+1].h);
            }
        }
        if(jud[i]==true)
        {
            int temp=min(T,a[i+1].b-1)-pret[i];
            ans=max(ans,dp[temp]+preh[i]);
        }
        

    }
    //  for(int i=N;i>=1;i--)
    //  {
        
    //  }
    //printf("%lld\n",ans);
    cout<<ans<<endl;
    return 0;
}