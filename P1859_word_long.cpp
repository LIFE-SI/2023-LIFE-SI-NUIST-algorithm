#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
string str[maxn];
int n,vis[maxn];
int res;

inline int read()
{
    int w=1,s=0;
    char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))
        ch=getchar();
    if(ch=='-')
    {
        w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return w*s;
}

int check(string a,string b)
{
    int lena=a.length(),lenb=b.length();
    for(int i=1;i<min(lena,lenb);i++)
    {
        int flag=1;
        for(int j=0;j<=i-1;j++)
        {
            if(a[lena-i+j]!=b[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            return i;
    }
    return 0;
}

void dfs(string a,int len)
{
    res=max(res,len);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]<2)
        {
            int l=check(a,str[i]);
            if(l>0)
            {
                vis[i]++;
                dfs(str[i],len+str[i].length()-l);
                vis[i]--;
            }
        }
    }
    return ;
}
int main()
{
    n=read();
    for(int i=1;i<=n+1;i++)
    {
        cin>>str[i];
    }
    dfs(' '+str[n+1],1);
    cout<<res<<endl;
    return 0;
}