#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
struct node
{
	int t,v;	
}a[maxn];

bool cmp(node a,node b)
{
	return a.v>b.v;
}
int sign[maxn];
int m,n;
int main()
{
	while(cin>>m>>n)
	{
		int s=0;
		memset(sign,0,sizeof(sign));
		for(int i=1;i<=n;i++)
			cin>>a[i].t;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].v;
			s=s+a[i].v;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			while(a[i].t--)
			{
				if(sign[a[i].t]==0)
				{
					sign[a[i].t]=1;
					s=s-a[i].v;
					break;
				}
			}
		}
		cout<<m-s<<endl;
	}
	return 0;
}