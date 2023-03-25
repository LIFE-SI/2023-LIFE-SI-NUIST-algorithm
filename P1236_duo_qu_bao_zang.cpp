#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn][maxn],dp[maxn][maxn];
int m,n;
int main()
{
	while(cin>>m>>n)
	{
		//memset(dp,0,sizeof(dp));
		//WSXNH：此题可以不初始化，因为每次dp都会使用被覆盖过的值
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);
			}
		}
		cout<<dp[m][n]<<endl;
	}
	
}