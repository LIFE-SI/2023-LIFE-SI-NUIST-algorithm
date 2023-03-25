#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int a[maxn];
signed main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int tag;
        cin>>tag;
        int sign=lower_bound(a,a+n,tag)-a;
        if(sign==n)
            cout<<a[n-1]<<endl;
        else if(a[sign]==tag)
        {
            cout<<tag<<endl;
        }
        else
        {
            if(a[sign]-tag<tag-a[sign-1])
                cout<<a[sign]<<endl;
            else
                cout<<a[sign-1]<<endl;
        }
    }
    return 0;
}