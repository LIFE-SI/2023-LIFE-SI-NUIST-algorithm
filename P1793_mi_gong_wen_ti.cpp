#include<bits/stdc++.h>
using namespace std;
const int maxn=10;

int mov[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[maxn][maxn];
char a[maxn][maxn];

void dfs(int x,int y)
{
	if(x==7&&y==7)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(vis[i][j]==1)
					printf(" ");
					//cout<<" ";
				else 
					//cout<<a[i][j];
					printf("%c",a[i][j]);
			}
			//cout<<endl; //换行过多，导致超时
			printf("\n");
		}
		return ;
	}
	for(int k=0;k<4;k++)
	{
		if(vis[x+mov[k][0]][y+mov[k][1]]==0&&a[x+mov[k][0]][y+mov[k][1]]=='O')
		{
			vis[x+mov[k][0]][y+mov[k][1]]=1;
			dfs(x+mov[k][0],y+mov[k][1]);
			//vis[x+mov[k][0]][y+mov[k][1]]=0;
		}
	}
}

int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*///没用！！

	//char temp;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			//cin>>a[i][j];
			scanf("%c",&a[i][j]);
		}
		//scanf("%c",&temp);
		getchar();//吸收换行符
	}
	vis[0][0]=1;
	dfs(0,0);
	return 0;

}