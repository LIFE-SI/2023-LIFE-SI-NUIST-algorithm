#include<bits/stdc++.h>
using namespace std;
int a[35],b[35],dp[35][20010];
int main()
{
	int v,n;
	while(cin>>v>>n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=v;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+b[i]);
				}
			}
		}
		cout<<dp[n][v]<<endl;
	}
	return 0;
}