//并查集
#include<bits/stdc++.h>
using namespace std;
int fa[105];

int find(int x)
{
	if(fa[x]==x)
		return x;
	else
	{
		return find(fa[x]);
	}
}

int main()
{
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		fa[i]=i;
	}
	int u,v;
	for(int i=1;i<=M;i++)
	{
		cin>>u>>v;
		int l=find(u),r=find(v);
		if(l!=r)
		{
			fa[l]=r;
		}
	}
	int flag=0;
	for(int i=1;i<=N;i++)
	{
		if(fa[i]==i)
			flag++;
	}
	if(flag==1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}