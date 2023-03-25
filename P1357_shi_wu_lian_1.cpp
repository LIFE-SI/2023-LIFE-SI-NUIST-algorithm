#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
vector<int> a[maxn];
int ch[maxn],ru[maxn];
int n,m,ans=0;
void dfs(int x,int len)
{
	if(ans<len)
		ans=len;
	int temp=a[x].size();
	for(int i=0;i<temp;i++)
	{
		dfs(a[x][i],len+1);
	}
}


int main()
{
	while(cin>>n>>m)
	{
		memset(ch,0,sizeof(ch));
		memset(ru,0,sizeof(ru));
		for(int i=1;i<=m;i++)
		{
			int from,to;
			cin>>from>>to;
			//a[from]=to;
			a[from].push_back(to);
			ch[from]=1;
			ru[to]=1;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(ru[i]==0&&ch[i]!=0)
				dfs(i,1);//生物数
		}
		cout<<ans<<endl;
		for(int i=0;i<maxn;i++)
			a[i].clear();
	}
	return 0;
}