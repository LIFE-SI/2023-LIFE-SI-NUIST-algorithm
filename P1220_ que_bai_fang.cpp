#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int cnt = 0;
int safe (int x, int y)
{
	int i,j;
	for(i = 1; i<=8; i++)
	{
		if(a[i][y]==1)
			return 0;
	}
	for(i=1; i<=8; i++)
	{
		for(j=1; j<=8; j++ )
		{
			if(abs(x-i)==abs(y-j) && a[i][j]==1)
				return 0;
		}	
	}
	return 1;
}
void dfs(int v)
{
	if(v > 8)
	{
		cnt ++;
		return ;
	}
	int flag = 1;
	int j;
	for(j=1;j<=8;j++)
	{
		if(a[v][j]==1)
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		for(j=1;j<=8;j++)
		{
			if(safe(v,j))
			{
				a[v][j] = 1;
				dfs(v+1);
				a[v][j] = 0;
			}
		}
	}
	else
	{
		dfs(v+1);
	}

}
int main ()
{
	int i,j;
	for(i=1;i<=8;i++)
		for(j=1;j<=8;j++)
		{
			cin>>a[i][j];
		}
	dfs(1);
	cout<<cnt<<endl;
	return 0;
}