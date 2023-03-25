#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int a[maxn];
int s[maxn];
int j=1;

void sout(int sign)
{
    for(int i=1;i<=sign;i++)
    {
        if(sign==pow(2,i))
        {
            s[j++]=0;
            return ;
        }
        if(sign<pow(2,i))
        {
            s[j++]=sign-pow(2,i-1)+1;
            return ;
        }
    }
}

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        memset(s,-1,sizeof(s));
        j=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==k)
                sout(i);
        }
        int res=0;
        for(int i=1;i<j;i++)
        {
            if(s[i]==0||res>=s[i])
                res++;
            else if(res<s[i])
                res=s[i];//s[i];
        }
        cout<<res<<endl;
    }
    return 0;
}
