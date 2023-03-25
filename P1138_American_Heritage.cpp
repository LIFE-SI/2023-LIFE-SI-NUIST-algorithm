#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	char data;
	node* left;
	node* right;
	
}node, * TreeNode;

char pre[30],vin[30];

TreeNode solve(char pre[],char vin[],int s)
{
	if(s<=0)
		return NULL;
	int temp=pre[0];
	TreeNode root=(TreeNode)malloc(sizeof(node));
	root->data=temp;
	int index=0;
	for(int i=0;i<s;i++)
	{
		if(vin[i]==pre[0])
		{
			index=i;
			break;
		}
	}
	root->left=solve(pre+1,vin,index);
	root->right=solve(pre+index+1,vin+index+1,s-index-1);
	return root;
}


void OUT(TreeNode T)  //后序遍历 
{
	if(T==NULL)
		return;
	else{
		OUT(T->left);
		OUT(T->right);
	    cout<<T->data;
	}
} 

int main()
{
	while(cin>>vin>>pre)
	{
		TreeNode tr=(TreeNode)malloc(sizeof(node));
		tr=solve(pre,vin,strlen(pre));
		//cout<<strlen(pre);
		OUT(tr);
		cout<<endl;
		free(tr);
	}
return 0;
}