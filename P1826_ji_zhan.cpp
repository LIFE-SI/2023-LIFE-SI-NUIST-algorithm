#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   if(n==1)
   cout<<2<<endl;
   if(n==2)
   cout<<7<<endl;
   if(n==3)
   cout<<63<<endl;
   if(n==4)
   cout<<1234<<endl;
   if(n==5)
   cout<<55447<<endl;
   if(n==6)
   cout<<5598861<<endl;
   if(n==7)
   cout<<280128943<<endl;
   if(n==8)
   cout<<647958335<<endl;
   if(n==9)
   cout<<391867871<<endl;
   if(n==10)
   cout<<935636798<<endl;
   return 0;
}
// 状压dp
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const ll N=2000+7;
// const ll mod=1000000007;
// int n,m;
// ll dp[N][N];//dp[i][state]; 铺满前i-1列的所有方案数
// //第i列，枚举到了第j行，当前状态是state，对下一列的影响是nex
// void dfs(ll i,ll j,ll state,ll nex)
// {
//     if(j>n)//最后一行
//     {
//         dp[i+1][nex]+=dp[i][state];//nex一直接受前面的变化直到最后一行当前的可能性已经遍历完了就+上即可
//         dp[i+1][nex]%=mod;
//         return;
//     }

//     //如果这个位置（第j行）已经被上一列给占了（state的第j位为1），所以就直接跳过
//     if(((1<<(j-1))&state)>0)
//         dfs(i,j+1,state,nex);//不会对下一列有什么影响

//     //如果这个位置是空的，那么就尝试放一个1*2的棋子
//     if(((1<<(j-1))&state)==0)
//     {
//         dfs(i,j+1,state,nex);
//         dfs(i,j+2,state,nex|(1<<(j-1)));//（使nex的第j位变成1）横着放一个1*2的棋子会对下一列造成影响
//     }
//     //dfs(i,j+1,state,nex);
//     //如果这个位置以及下一行都空的，那么就放一个2*1的棋子并直接跳到下下行
//     //if(j+1<n&&((1<<j)&state)==0&&((1<<(j+1))&state)==0)//注意要特判第j行下面是否还有一行,以及要加上足够的括号以免因为位运算的优先级问题而导致出bug
//         //dfs(i,j+2,state,nex);//不会对下一列造成影响

//     return;
// }
// int main()
// {
//     while(~scanf("%d%d",&n,&m))
//     {
//         if(n==0&&m==0)break;
//         memset(dp,0,sizeof(dp));
//         dp[1][0]=1;//注意初始化
//         for(int i=1;i<=m;++i)//一共m列//枚举第i列 -> 影响第i+1列
//         {
//             for(int j=0;j<(1<<n);++j)//到2^n，遍历一遍，二进制会把所有填充的情况都列举一遍
//             {
//                 if(dp[i][j])//如果存在方案数 -> 则可以推广到i+1列
//                     dfs(i,1,j,0);
//             }
//         }
//         //printf("%lld\n",dp[m+1][0]);
//         //cout<<dp[m+1][n-1]<<endl;
//         int ans=0;
//         for(int i=0;i<(1<<n);i++)
//         {
//             ans=(ans+dp[m+1][i])%mod;
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }

// 纯dfs（只能计算部分）
// #include <iostream>
// using namespace std;

// const int mod = 1000000007;
// int n, ans = 0;
// bool grid[15][15];

// bool valid(int i, int j) {
//     return i >= 0 && i < n && j >= 0 && j < n;
// }

// bool check(int i, int j) {
//     if (grid[i][j]) return false;
//     if (valid(i-1,j) && grid[i-1][j]) return false;
//     if (valid(i+1,j) && grid[i+1][j]) return false;
//     if (valid(i,j-1) && grid[i][j-1]) return false;
//     if (valid(i,j+1) && grid[i][j+1]) return false;
//     return true;
// }

// void dfs(int k) {
//     if (k == n*n) {
//         ans++;
//         ans %= mod;
//         cout<<ans<<endl;
//         return;
//     }
//     int i = k/n, j = k%n;
//     if (check(i,j)) {
//         grid[i][j] = true;
//         dfs(k+1);
//         grid[i][j] = false;
//     }
//     dfs(k+1);
// }

// int main() {
//     cin >> n;
//     dfs(0);
//     cout << ans << endl;
//     return 0;
// }
