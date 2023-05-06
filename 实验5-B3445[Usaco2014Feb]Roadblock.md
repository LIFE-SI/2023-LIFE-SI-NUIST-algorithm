# 实验5

## 1．实验目的

（1）熟悉图算法中的多种单源最短路径求解方法

（2）理解基于图的多种单元最短路算法的设计原理

（3）编写能够求解单源最短路径问题的图算法程序

（4）能够分析解题所用算法的时间复杂度

## 2．实验内容

- 题目描述

> 有一个无向图，共 N 个节点，编号 1 至 N，共 M 条边。FJ 在节点 1，它想到达节点 N。FJ 总是会选择最短路径到达节点 N。作为捣蛋的奶牛 Bessie，它想尽量延迟 FJ 到达节点 N 的时间，于是 Bessie 决定从 M 条边之中选择某一条边，使得改边的长度变成原来的两倍，由于智商的问题，Bessie 不知道选择加倍哪条边的长度才能使得 FJ 到达 N 号节点的时间最迟。注意：不管 Bessie 选择加倍哪条边的长度，FJ 总是会从 1 号节点开始走最短路径到达 N 号点。 输入描述第一行，两个整数 N 和 M. 1 <=N<=250, 1<=M<=250000。接下来有 M 行，每行三个整数：A，B，L，表示节点 A 和节点 B 之间有一条长度为 L 的无向边。1<=L<=1000000。

- 输出描述

> 一个整数。Bessie 选择了加倍某一条边的长度后，奶牛 FJ 从节点 1 到达节点 N 的最短路径是多少。但是输出的格式有变化，假设 Bessie 没有加倍某一条边的长度之前，FJ 从 1 号节点到达 N 号节点的最短路径是 X；在 Bessie 加倍某一条边的长度之后，FJ 从 1 号节点到达 N 号节点的最短路径是 Y，那么你输出的结果是 Y-X。 

- 样例输入

> 5 7
2 1 5
1 3 1
3 2 8
3 5 7
3 4 3
2 4 7
4 5 2 

- 样例输出

> 2

## 3．算法实现和实验结果

```C++
#include<bits/stdc++.h>
using namespace std;
const int maxn=252;
int n,m;
queue<int> que;
int vis[maxn];
int e[maxn][maxn];
int dis[maxn];
int st[250001],en[250001];
void SPFA(int x)
{  
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f3f3f,sizeof(dis));
    vis[x]=1;
    dis[x]=0;
    que.push(x);
    while(!que.empty())
    {
        int temp=que.front();   
        for(int i=1;i<=n;i++)
        {
            if(e[temp][i]!=0x3f3f3f)
                if(dis[i]>dis[temp]+e[temp][i])
                {
                    dis[i]=dis[temp]+e[temp][i];
                    if(vis[i]==0)
                    {
                        vis[i]=1;
                        que.push(i);
                    }
                }
        }
        que.pop();
        vis[temp]=0;
    }
}

int main()
{
    int u,v,w;
    cin>>n>>m;
    memset(e,0x3f3f3f,sizeof(e));
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        e[u][v]=w;
        e[v][u]=w;
        st[i]=u;
        en[i]=v;
    }
    SPFA(1);
    int res=dis[n];
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        e[st[i]][en[i]]*=2;
        e[en[i]][st[i]]*=2;
        SPFA(1);
        ans=max(ans,dis[n]);
        e[st[i]][en[i]]/=2;
        e[en[i]][st[i]]/=2;
    }
    cout<<ans-res<<endl;
    return 0;
}
```

![image](https://user-images.githubusercontent.com/95600943/236593591-5b1318a8-ecac-43c2-a507-9683d59c4984.png)

## 4．分析与讨论（算法时间复杂度分析和讨论）

本题可使用 $Bellman-Ford$ 算法求得初始状态的最短路径所需要行走的距离 $dis[n]$ ，然后对于每条边，将其长度变为 $2$ 倍，再次使用 $Bellman-Ford$ 算法 ，求其最短路径所需行走的距离，维护最短路径需要行走的距离的最大值 $MAX$ ，按照要求输出 $MAX-dis[n]$ 。

$Bellman-Ford$ 算法时间复杂度为 $O(n*m)$, k是V入队的次数；本题在此基础上，还要考虑每条边加倍后的 $Bellman-Ford$ ,所以时间复杂度为 $O(m*n^2)$ 。

由于此题 $n$ 的范围较小，可以用过此题。

当 $n$ 较大时可以考虑 $SPFA$ 算法。
