#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int nums[maxn][5];
int sum[4000010];
int ans=0;
//int sum2[400010];

void Find(int left,int right,int x)
{
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(sum[mid]==x)
        {
            ans++;
            int i=mid-1,j=mid+1;
            while(sum[i--]==x)
                ans++;
            while(sum[j++]==x)
                ans++;
            return ;
        }
        else if(sum[mid]<x)
        {
            left=mid+1;
        }
            //return find(mid+1,right,x);
        else
        {
            right=mid-1;
        }
            //return find(left,mid,x);
    }
    return ;
}

// void find(int x,int length)
// {
//     int left = 1, right = length-1;
//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         if (sum[mid] == x)
//         {
//             ans++;
//             int i=mid,j=mid;
//             while (sum[i - 1] == x)
//             {
//                 ans++;
//                 i--;
//             }
//             while (sum[j + 1] == x)
//             {
//                 ans++;
//                 j++;
//             }
//             return;
//         }
//         else if (sum[mid] > x)       
// 			right = mid - 1;
//         else                                      
// 			left = mid + 1;
//     }
//     return ;
// }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=4;j++)
            {
                cin>>nums[i][j];
            }
        }
        int k=1;
        for(int i=1;i<=n; i++)
        {
            for(int j=1;j<=n;j++)
            {
                sum[k]=nums[i][1]+nums[j][2];
                //sum2[k]=nums[i][3]+nums[j][4];
                k++;
            }
        }
        sort(sum+1,sum+k);
        //int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int tag=-1*(nums[i][3]+nums[j][4]);
                Find(1,k-1,tag);
                //find(tag,k);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}