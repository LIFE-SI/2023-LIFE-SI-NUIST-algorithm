#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	
	while(cin>>n)
	{
		int a,sum=0,ans=-60010;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			sum=sum+a;
			if(sum<0)
				sum=0;
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}