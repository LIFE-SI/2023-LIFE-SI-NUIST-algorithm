#include<bits/stdc++.h>
using namespace std;
//const int maxn=1e3+5;
typedef struct node
{
    int data;
    int cnt=0;
    node *lch;
    node *rch;
}node, *tree;
tree Root;
int ans=0;
void add(tree &Tr,int x)
{
    // int x;
    // cin>>x;
    if(Tr==NULL)
    {
        Tr=(tree)malloc(sizeof(node));
        Tr->data=x;
        Tr->cnt=1;
        Tr->lch=Tr->rch=NULL;
    }
    else
    {
        if(Tr->data>x)
        {
            cout<<"<-";
            add(Tr->lch,x);
        }
        else if(Tr->data<x)
        {
            cout<<"->";
            add(Tr->rch,x);
        }
        else if(Tr->data==x)
        {
            Tr->cnt++;
        }
    }

}

void search(tree &Tr,int x)
{
    // int x;
    // cin>>x;
    if(Tr==NULL)
        return ;

    if(Tr->data>x)
    {
        cout<<"<-";
        search(Tr->lch,x);
    }
    else if(Tr->data<x)
    {
        cout<<"->";
        search(Tr->rch,x);
    }
    else if(Tr->data==x)
    {
        //cout<<endl;
        ans=Tr->cnt;
    }
    return ;
}

int main()
{
    //root=(tree)malloc(sizeof(node));
    int n;
    cin>>n;
    //while(cin>>n)
    {
        while(n--)
        {
            int opt,x;
            cin>>opt>>x;
            if(opt==1)
            {
                add(Root,x);
                cout<<endl;
            }
            if(opt==2)
            {
                ans=0;
                search(Root,x);
                cout<<endl<<ans<<endl;
            }
        }
    }
    return 0;
}