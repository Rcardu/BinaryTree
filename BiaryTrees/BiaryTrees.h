/*
 * @Description: 
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#endif
#include<queue>
#include<vector>


using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode*next;
    TreeNode(int x):val(x),left(NULL),right(NULL),next(NULL){};
};

class BiaryTree{
public:
    //输入函数，动态数组
    void CreatTree(int *trees,int sub,int len,TreeNode* &root);
    //输入函数，容器vector,当前位置，数组长度，根节点
    void CreatTree(vector<int>trees,int sub,int len,TreeNode* &root);
    
    /*给定⼀个完美⼆叉树，其所有叶⼦节点都在同⼀层，每个⽗节点都有两个⼦节点。⼆叉树定义如下：
    填充它的每个 next 指针，让这个指针指向其下⼀个右侧节点。如果找不到下⼀个右侧节点，则将 next 指针设置为 NULL。
    初始状态下，所有 next 指针都被设置为 NULL。*/
    TreeNode*LayerOrderTraversal_connect(TreeNode*node);
    //输出函数
    void Print(TreeNode*p);
    //输出函数next指针链接
    void LayerOrderTraversal_connectFormat(TreeNode*node);
};

void BiaryTree::CreatTree(int *trees,int sub,int len,TreeNode* &root){
        if((trees[0]==-1)||len==0)return ;
        if(sub>=len){root=NULL;return;}
        if(trees[sub]==-1)root=NULL;
        else{
            root=(TreeNode*)malloc(sizeof(TreeNode));
            root->val=(trees[sub]);
            int m=trees[sub];
            CreatTree(trees,sub*2+1,len,root->left);
            CreatTree(trees,sub*2+2,len,root->right);
        }
}
void BiaryTree::CreatTree(vector<int>trees,int sub,int len,TreeNode* &root){
    if((trees[0]==-1)||len==0)return ;
    if(sub>=len){root=NULL;return;}
    if(trees[sub]==-1)root=NULL;
    else{
        root=(TreeNode*)malloc(sizeof(TreeNode));
        root->val=(trees[sub]);
        int m=trees[sub];
        CreatTree(trees,sub*2+1,len,root->left);
        CreatTree(trees,sub*2+2,len,root->right);
    }
}
TreeNode*BiaryTree::LayerOrderTraversal_connect(TreeNode*node){
    queue<TreeNode*>que;
    if(node!=NULL)que.push(node);
    while(!que.empty()){
        int size=que.size();
        vector<int>vec;
        TreeNode*nodePre;
        TreeNode*ptr;
        for(int i=0;i<size;i++){
            if(i==0){
                nodePre=que.front();
                que.pop();
                ptr=nodePre;
            }else{
                ptr=que.front();
                que.pop();
                nodePre->next=ptr;
                nodePre=nodePre->next;
            }
            if(ptr->left)que.push(ptr->left);
            if(ptr->right)que.push(ptr->right);
        }
        nodePre->next=NULL;
    }
    return node;
}
void BiaryTree::Print(TreeNode*p){
    if(p==NULL)return ;
    cout<<" "<<p->val;
    Print(p->left);
    Print(p->right);
}
void BiaryTree::LayerOrderTraversal_connectFormat(TreeNode*node){
    //头部都在左结点，只需要遍历左节点即可
    queue<TreeNode*>que;
    if(node!=NULL)que.push(node);
    while(!que.empty()){
        TreeNode*Nodeptr;
        TreeNode*ptr;
        int size=que.size();
        for(int i=0;i<size;i++){
            if(i==0){
                Nodeptr=que.front();
                que.pop();
                ptr=Nodeptr;
                cout<<ptr->val<<" ";
            }else{
                ptr=que.front();
                que.pop();
                cout<<ptr->val<<" ";
                Nodeptr=Nodeptr->next;
            }
            if(ptr->left)que.push(ptr->left);
            if(ptr->right)que.push(ptr->right);
        }
        if(Nodeptr->next==NULL)cout<<"#"<<" ";
        cout<<endl;
        
    }

}
