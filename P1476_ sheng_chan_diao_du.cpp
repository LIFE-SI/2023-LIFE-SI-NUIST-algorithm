#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct node
{
	int sign;
	int MIN;
}da[maxn];
bool cmp(node a,node b)
{
	return a.MIN<b.MIN;
}
int a[maxn],b[maxn],que[maxn];
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			da[i].MIN=min(a[i],b[i]);
			da[i].sign=i;
		}
		sort(da+1,da+1+n,cmp);
		int left=1,right=n;
		for(int i=1;i<=n;i++)
		{
			if(da[i].MIN==a[da[i].sign])
			{
				que[left++]=da[i].sign;
			}
			else
			{
				que[right--]=da[i].sign;
			}
		}
		int sum=a[que[1]]+b[que[1]];
		int suma=a[que[1]];
		for(int i=2;i<=n;i++)
		{
			if(suma+a[que[i]]>=sum)
			{
				sum=suma+a[que[i]]+b[que[i]];
				suma=suma+a[que[i]];
			}
			else
			{
				sum=sum+b[que[i]];
				suma=suma+a[que[i]];
			}
		}
		cout<<sum<<endl;
	}	
	return 0;
}