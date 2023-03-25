#include<bits/stdc++.h>
using namespace std;

struct node
{
	double m,v;
	double w; 
}a[1005];

bool cmp(node &a,node &b)
{
	return a.w>b.w; 
}

int main()
{
	int N,T;
	double ans=0;
	cin>>N>>T;
	for(int i=0;i<N;i++)
	{
		cin>>a[i].m>>a[i].v;
		a[i].w=a[i].v/a[i].m;
	}
	sort(a,a+N,cmp);
	for(int i=0;i<N;i++)
	{
		if(T>a[i].m)
		{
			ans=ans+a[i].v;
			T=T-a[i].m;
		}
		else
		{
			ans=ans+a[i].w*T;
			break;
		}
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
