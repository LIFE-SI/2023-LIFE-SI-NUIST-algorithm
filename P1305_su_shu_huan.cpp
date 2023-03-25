#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
bool vis[maxn];
int nums[maxn];
int n;

int jude(int x)
{
    if(x==2)
        return 1;
    else
    {
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
                return 0;
        }
    }
    return 1;
}

void dfs(int x,int len)
{
    if(len==n)
    {
        if(jude(x+1))
        {
            cout<<1;//这格式真无语了！！！
            for(int i=2;i<=n;i++)
            {
                cout<<" "<<nums[i];
            }
            cout<<endl;
            return ;
        }
        //cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            if(jude(x+i))
            {
                vis[i]=1;
                nums[len+1]=i;
                dfs(i,len+1);
                vis[i]=0;
            }
        }
    }

}

int main()
{
    int sign=1;
    while(cin>>n)
    {
        if(sign!=1)
            cout<<endl;//这格式真无语了！！
        cout<<"Case "<<sign++<<":"<<endl;
        vis[1]=1;
        nums[1]=1;
        dfs(1,1);
        //cout<<endl;
    }
    return 0;
}