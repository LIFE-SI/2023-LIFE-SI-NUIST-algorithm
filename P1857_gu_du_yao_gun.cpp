#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
struct node
{
    int v,w;
    int p;
};
int n,m,s,t;
vector<node> gra[maxn];
int vis[maxn],peop[maxn],dis[maxn],dw[maxn];

void spfa()
{
    queue<int> q;   
    dis[s] = 0;  
    peop[s]=dw[s];
    q.push(s);    
    vis[s]=true;
    while (!q.empty()) 
    {   
        int u = q.front();    
        q.pop();   
        vis[u] = false;   
        int len=gra[u].size();
        for (int i=0;i<len;i++) 
        {   
            int v = gra[u][i].v, w = gra[u][i].w;  
            int flag=0;
            //int flag=1;
            if (peop[v]>peop[u]+dw[v]) 
            {   
                flag=1;
                peop[v]=peop[u]+dw[v];
                dis[v] = dis[u] + w;    
                if (!vis[v]) 
                {   
                    q.push(v);   
                    vis[v] = true;   
                }
            } 
            if (dis[v] > dis[u] + w && peop[v]==peop[u]+dw[v]&&flag==0) 
            {   
                dis[v] = dis[u] + w;    
                if (!vis[v]) 
                {   
                    q.push(v);   
                    vis[v] = true;   
                }
            }
            // if (dis[v] > dis[u] + w) 
            // {   
            //     dis[v] = dis[u] + w;    
            //     if (!vis[v]) 
            //     {   
            //         q.push(v);   
            //         vis[v] = true;   
            //     }
            // }
        }
    }
}

signed main()
{
    cin>>n>>m>>s>>t;
    memset(dis,INF,sizeof(dis));
    memset(peop,INF,sizeof(peop));
    for(int i=1;i<=n;i++)
    {
        cin>>dw[i];
        //gra[i].v_w=gra[i].u_w;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        node temp;
        temp.v=v,temp.w=w;
        gra[u].push_back(temp);
        temp.v=u;
        gra[v].push_back(temp);

    }
    spfa();
    cout<<peop[t]<<" "<<dis[t]<<endl;
    return 0;
}

/*
5 5 1 5
1 10 10 20 100
1 2 1
2 3 1
1 4 1
4 5 100
3 5 1

121 3
*/