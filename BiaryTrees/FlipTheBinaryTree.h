#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiaryTrees.h"
#include<algorithm>
#include<stack>
#include<queue>
#endif



using namespace std;

class FlipTheBinaryTree{
public:
/*把每一个结点的左右孩子反转一下就好了
使⽤前序遍历和后序遍历都可以，唯独中序遍历不⾏，因为中序遍历会把某些节点的左右孩⼦翻转了两次！*/
/*先序遍历，递归法*/
TreeNode*FlipTheBinaryTree_Apro(TreeNode*node);
/*先序遍历，迭代法*/
TreeNode*FlipTheBinaryTree_Bpro(TreeNode*node);
/*先序遍历，迭代法（统一格式）*/
TreeNode*FlipTheBinaryTree_Cpro(TreeNode*node);
/*后序遍历，递归法*/
TreeNode*FlipTheBinaryTree_Apost(TreeNode*node);
/*后序遍历，迭代法（统一格式）*/
TreeNode*FlipTheBinaryTree_Cpost(TreeNode*node);
/*广度优先遍历*/
TreeNode*FlipTheBinaryTree_Arec(TreeNode*node);
};
/*确定递归函数参数以及返回值，传递参数为node树就行
返回值要求返回root结点的指针即，TreeNode*类型
确定终止条件，当前结点为空的时候就返回
确定单层递归逻辑，因为是先序遍历，所以先交换当前结点的左右孩子，再进入左子树反转，再进入右子树反转
swap(node->left,node->right);
FlipTheBinaryTree(node->left);
FlipTheBinaryTerr(node->right);*/
TreeNode*FlipTheBinaryTree::FlipTheBinaryTree_Apro(TreeNode*node){
    if(node==NULL)return node;
    swap(node->left,node->right);
    FlipTheBinaryTree_Apro(node->left);
    FlipTheBinaryTree_Apro(node->right);
    return node;
}
TreeNode*FlipTheBinaryTree::FlipTheBinaryTree_Bpro(TreeNode*node){
    stack<TreeNode*>st;
    if(node!=NULL)st.push(node);
    while(!st.empty()){
        TreeNode*ptr=st.top();
        st.pop();
        swap(ptr->left,ptr->right);
        if(ptr->right)st.push(ptr->right);
        if(ptr->left)st.push(ptr->left);
    }
    return node;
}
TreeNode*FlipTheBinaryTree::FlipTheBinaryTree_Cpro(TreeNode*node){
    stack<TreeNode*>st;
    if(node!=NULL)st.push(node);
    while(!st.empty()){
        TreeNode*ptr=st.top();
        if(ptr){
            st.pop();
            if(ptr->right)st.push(ptr->right);
            if(ptr->left)st.push(ptr->left);
            st.push(ptr);
            st.push(NULL);
        }else{
            st.pop();
            ptr=st.top();
            st.pop();
            swap(ptr->left,ptr->right);
        }
    }
    return node;
}
//后序遍历
TreeNode*FlipTheBinaryTree::FlipTheBinaryTree_Apost(TreeNode*node){
    if(node==NULL)return node;
    FlipTheBinaryTree_Apost(node->left);
    FlipTheBinaryTree_Apost(node->right);
    swap(node->left,node->right);
    return node;
}
TreeNode*FlipTheBinaryTree::FlipTheBinaryTree_Cpost(TreeNode*node){
    stack<TreeNode*>st;
    if(node!=NULL)st.push(node);
    while(!st.empty()){
        TreeNode*ptr=st.top();
        if(ptr){
            st.pop();
            st.push(ptr);
            st.push(NULL);
            if(ptr->right)st.push(ptr->right);
            if(ptr->left)st.push(ptr->left);
        }else{
            st.pop();
            ptr=st.top();
            st.pop();
            swap(ptr->left,ptr->right);
        }
    }
    return node;
}
//广度优先遍历
TreeNode*FlipTheBinaryTree::FlipTheBinaryTree_Arec(TreeNode*node){
    queue<TreeNode*>que;
    if(node!=NULL)que.push(node);
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            TreeNode*ptr=que.front();
            que.pop();
            swap(ptr->left,ptr->right);
            if(ptr->left)que.push(ptr->left);
            if(ptr->right)que.push(ptr->right);
        }
    }
    return node;
}