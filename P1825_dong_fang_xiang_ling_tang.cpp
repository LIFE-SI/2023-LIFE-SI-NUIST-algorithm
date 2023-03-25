#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int a[5005];
int N,K;
int main()
{
	while(cin>>N>>K)
	{
		for(int i=1;i<=N;i++)
			cin>>a[i];
		sort(a+1,a+N+1);
		int sum=0;
		for(int i=1;i<=N;i++)
		{
			sum=sum+a[i];
			if(sum>K)
			{
				cout<<i-1<<endl;
				break;
			}
		}
	}
	return 0;
}