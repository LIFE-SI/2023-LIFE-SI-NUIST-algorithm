#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n, m, dp[maxn], p[maxn], x[maxn],s;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        s = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&p[i],&x[i]);
        }
        dp[0] = p[0] + x[0],s = p[0];
        for (int i = 0; i < n; i++)
        {
            if (dp[i] < p[i + 1])
            {
                s = s + p[i + 1] - dp[i];
                dp[i + 1] = p[i + 1] + x[i + 1];
            }
            else
            {
                if (dp[i] < p[i + 1] + x[i + 1])
                {
                    dp[i + 1] = p[i + 1] + x[i + 1];
                }
                else 
                {
                    dp[i + 1] = dp[i];
                }
            }
        }
        if (dp[n - 1] < m)
            s = s + m - dp[n - 1];
        printf("%d\n",s);
    }
    return 0;
}