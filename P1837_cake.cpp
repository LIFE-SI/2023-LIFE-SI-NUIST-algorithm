#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn][maxn];
int dp[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];
            }
        }
        int ans=-0x3f3f3f3f;
        for(int k=0;k<=n;k++)
        {
            for(int i=1;i+k<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    int temp=0;
                    for(int l=i;l<=i+k;l++)
                    {
                        temp=temp+a[l][j];
                    }
                    dp[j]=max(temp,dp[j-1]+temp);
                    ans=max(ans,dp[j]);
                }
                memset(dp,-1,sizeof(dp));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}