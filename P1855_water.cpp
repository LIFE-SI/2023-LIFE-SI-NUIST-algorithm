#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int a[maxn],b[105];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    for(int i=m+1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    int cnt=0;
    int j=m+1;
    while(cnt!=n)
    {
        ans++;
        for(int i=1;i<=m;i++)
        {
            b[i]--;
            if(b[i]==0)
            {
                b[i]=a[j++];
                cnt++;
            }
        }
    }
    cout<<ans<<endl;
}