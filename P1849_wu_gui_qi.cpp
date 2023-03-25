#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[400],cnt[5]; 
int dp[30][30][30];

inline int read()
{
    int w=1,s=0;
    char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return w*s;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    for(int i=1,temp;i<=m;i++)
    {
        temp=read();
        cnt[temp]++;
    }
    dp[0][0][0]=0;
    for(int i=0;i<=cnt[1];i++)
    {
        for(int j=0;j<=cnt[2];j++)
        {
            for(int k=0;k<=cnt[3];k++)
            {
                for(int l=0;l<=cnt[4];l++)
                {
                    int pos=i*1+j*2+k*3+l*4+1;
                    if(j)
                    {
                        dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]);
                    }
                    if(k)
                    {
                        dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]);
                    }
                    if(l)
                    {
                        dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]);
                    }
                    dp[j][k][l]=dp[j][k][l]+a[pos];
                }
            }
        }
    }
    printf("%d\n",dp[cnt[2]][cnt[3]][cnt[4]]);
    return 0;
}