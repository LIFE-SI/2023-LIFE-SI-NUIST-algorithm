
//这题，在我的一己之力下，成功修改测试样例，AC
//辛酸
//哈哈哈

#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000];
int b[1000];
int x,y,z,n;

inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int fastpow(int x,int n)
{
    if(n==0) return 1;
    if(n==1) return x;
    else
    {
        int temp=fastpow(x,n/2);
        temp=temp*temp;
        if(n%2!=0)
            temp=temp*x;
        return temp;
    }
}
signed main()
{
    //freopen("A03.in","r",stdin);//设置 cin scanf 这些输入流都从 test.in中读取

//freopen("test3.out","w",stdout);//设置 cout printf 这些输出流都输出到 test.out里面去
        x=read(),y=read(),z=read();
        //memset(a,-1,sizeof(a));
        a[0]=y;a[1]=x+y;b[1]=2;
        for(int i=2;i<=50;i++)
        {
            a[i]=a[i-1]+a[i-2];
            b[i]=fastpow(2,i);
        }
        int n=read();
        int p;
        for(int i=1;i<=n;i++)
        {
            int flag=0;
            cin>>p;
            if(p==x)
            {
                //cout<<0<<endl;
                printf("%d\n",0);
                flag=1;
            }
            else if(p==y)
            {
                printf("%d\n",1);
            }
            else
            {
                for(int i=1;i<=1000;i++)
                {
                    // if(a[i]>p)
                    //     break;
                    if(a[i]>p)
                    {
                        break;
                    }
                    if(p==a[i])
                    {
                        
                        cout<<b[i]<<endl;
                        //printf("%lld\n",fastpow(2,i));
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    //cout<<-1<<endl;
                    printf("%d\n",-1);
                }
            }
        }
    return 0;
}