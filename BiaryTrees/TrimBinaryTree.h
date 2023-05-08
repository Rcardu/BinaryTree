#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiTreeNode.h"
#include"BiaryTrees.h"
#include"ConstructBinaryTree.h"
#include<queue>
#include<stack>
#endif

using namespace std;

class TrimBinaryTree
{
private:
    /* data */
public:
    /*修建二叉搜索树，使其节点的值都在固定区间内*/
    TreeNode*TrimBinaryTree_Rec(TreeNode*node,int low,int high);
    /*修建二叉搜索树，使其节点的值都在固定区间内,迭代*/
    TreeNode*TrimBinaryTree_Iter(TreeNode*node,int L,int R);

};
/*修建二叉搜索树，使其节点的值都在固定区间内
1.确定递归函数参数及返回值，传入根节点以及区间p，q
需要遍历整个区间，且需要返回值来连接修剪所剩下的叶子
TreeNode*TrimBinaryTree_Rec(TreeNode*node,int low,int high);
2.确定递归终止条件：修剪的操作不是在终止条件上进行的，所以遇到空节点直接返回即可
if(node==NULL)return nullptr;
3.确定单层递归逻辑：如果当前节点的值小于low，那么就应该递归右子树，返回右子树符合条件的节点
if(node->val<low){
    TreeNode*left=TrimBinaryTree_Rec(node->right,low,high);
    return right;
}
如果当前节点的值大于high，那么就应该递归左子树，返回左子树符合条件的节点
即，当前节点的值大于high时，其右子树的值也必然比high大，需要全部裁掉，保留左子树的值
if(node->val>high){
    TreeNode*right=TrimBinaryTree_Rec(node->left,low,high);
    return left;
}
接下来将左子树处理完的结果赋给node->left,右子树处理完的结果赋给node->right;
node->left=(node->left,low,high);
node->right=(node->right,low,high);
return node;
*/
TreeNode*TrimBinaryTree::TrimBinaryTree_Rec(TreeNode*node,int low,int high){
    if(node==NULL)return nullptr;
    if(node->val<low){
        TreeNode*right=TrimBinaryTree_Rec(node->right,low,high);
        return right;
    }
    if(node->val>high){
        TreeNode*left=TrimBinaryTree_Rec(node->left,low,high);
        return left;
    }
    node->left=TrimBinaryTree_Rec(node->left,low,high);
    node->right=TrimBinaryTree_Rec(node->right,low,high);
    return node;
}


TreeNode*TrimBinaryTree::TrimBinaryTree_Iter(TreeNode*node,int L,int R){
    if(node==NULL)return nullptr;

    //处理头节点使其在[L,R]的范围内
    while(node->val<L&&node->val>R){
        if(node->val<L)node=node->right;
        else node=node->left;
    }
    TreeNode*ptr=node;
    //此时node已经在[L,R]内,处理左子树小于L的情况
    while(ptr!=NULL){
        while(ptr->left&&ptr->left->val<L){
            ptr->left=ptr->left->right;
        }
        ptr=ptr->left;
    }
    ptr=node;
    while(ptr!=NULL){//处理右子树大于R的情况
        while(ptr->right!=NULL&&ptr->right->val>R){
            ptr->right=ptr->right->left;
        }
        ptr=ptr->right;
    }
    return node;
}