/*
 * @Description: 
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#endif
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};
class BiaryTree{
private:
    void CreatTree(int *trees,int sub,int len,TreeNode* &root){
        if((trees[0]=='#')||len==0)return ;
        if(sub>=len){root=NULL;return;}
        if(trees[sub]=='#')root=NULL;
        else{
            root=(TreeNode*)malloc(sizeof(TreeNode));
            root->val=(trees[sub]);
            int m=trees[sub];
            CreatTree(trees,sub*2+1,len,root->left);
            CreatTree(trees,sub*2+2,len,root->right);
        }
    }
    void CreatTree(vector<int>trees,int sub,int len,TreeNode* &root){
        if((trees[0]=='#')||len==0)return ;
        if(sub>=len){root=NULL;return;}
        if(trees[sub]=='#')root=NULL;
        else{
            root=(TreeNode*)malloc(sizeof(TreeNode));
            root->val=(trees[sub]);
            int m=trees[sub];
            CreatTree(trees,sub*2+1,len,root->left);
            CreatTree(trees,sub*2+2,len,root->right);
        }
    }
public:
    //输入函数
    void RecursiveTraversalOfBinaryTrees(){
        int trees[]={1,2,3,4,5,6,7};
        TreeNode*root;
        int sub=0;
        int len=(sizeof(trees)/sizeof(int));
        CreatTree(trees,sub,len,root);
        Print(root);
    }
    //输入函数重载
    void RecursiveTraversalOfBinaryTrees(int N){
        TreeNode*root;
        vector<int>trees(N);
        for(int i=0;i<N;i++)cin>>trees[i];
        int sub=0;
        int len=trees.size();
        CreatTree(trees,sub,len,root);
        Print(root);
    }
    //输出函数
    void Print(TreeNode*p){
        if(p==NULL)return ;
        cout<<" "<<p->val;
        Print(p->left);
        Print(p->right);
    }

};
