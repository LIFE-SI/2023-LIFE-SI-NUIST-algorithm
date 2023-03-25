#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],n,k;
double x;
int l=0,r=1e9;
int cnt(int x)
{
	int ans=0;
	for(int i=1;i<=n;i++)
    {
		ans=ans+a[i]/x;
	}
	if(ans>=k)
		return 1;
	else
		return 0;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
    {
		cin>>x; 
        a[i]=(int)(x*100);
	}	
	while(l<=r)
    {
		int mid=(l+r)/2;
		if(mid==0) 
            break;
		if(cnt(mid))
			l=mid+1;
		else 
			r=mid-1;
	}
    printf("%.2f\n",r/100.0);
    return 0;
} 
