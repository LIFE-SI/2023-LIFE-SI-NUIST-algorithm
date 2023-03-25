#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int fish[maxn];
//vector<int>fish;
int Left,Right,num;
int safe(int x)
{
    for(int i=1;i<=num;i++)
    {
        if((x>=fish[i]*2&&x<=fish[i]*10)||(fish[i]>=x*2&&fish[i]<=x*10))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    while(cin>>Left>>Right>>num)
    {
        for(int i=1;i<=num;i++)
        {
            cin>>fish[i];
        }
        int cnt=0;
        for(int i=Left;i<=Right;i++)
        {
            if(safe(i))
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}