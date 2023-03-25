#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int dp[maxn],a[maxn];
int n,m,k;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int temp;
		cin>>temp;
		a[temp]=1;
	}
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+a[i];
		for(int j=1;j<=k&&i-j>=1;j++)
		{
			dp[i]=min(dp[i],dp[i-j]+a[i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;

}