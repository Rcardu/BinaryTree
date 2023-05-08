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
class RecentPublicAncestors
{
private:
    /* data */
public:
    /*给定⼀个⼆叉树, 找到该树中两个指定节点的最近公共祖先。*/
    TreeNode*lowsetCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q);
    /*给定⼀个⼆叉树, 找到该树中两个指定节点的最近公共祖先。给的是节点的数值*/
    TreeNode*lowsetCommonAncestorS(TreeNode*root,int p,int q);
    /*按值找到需要的节点*/
    TreeNode*Search_RootA(TreeNode*node,int val){
        if(node==NULL)return NULL;
        if(node->val==val)return node;
        TreeNode*left=Search_RootA(node->left,val);
        TreeNode*right=Search_RootA(node->right,val);
        if(left!=NULL&&right==NULL)return left;
        else if(left==NULL&&right!=NULL)return right;
        else return NULL;
    }

};
/*给定⼀个⼆叉树, 找到该树中两个指定节点的最近公共祖先。
1.确定递归函数参数及返回值：
需要返回公共祖先节点，利用p或者q来返回
TreeNode*lowsetCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q);
2.确定递归终止条件：如果找到了p或者q节点或者空节点就返回
if(root==q||root==p||root==NULL)return root;
3.确定单层递归逻辑：区分搜索一条边与搜索整个树
搜索一条边：
    if(递归函数(root->left))return;
    if(递归函数(root->right))return;
搜索整个树：
    left=递归函数(root->left);
    right=递归函数(root->right);
    left与right的逻辑处理;
*/
TreeNode*RecentPublicAncestors::lowsetCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
    if(root==q||root==p||root==NULL)return root;
    TreeNode*left=lowsetCommonAncestor(root->left,p,q);
    TreeNode*right=lowsetCommonAncestor(root->right,p,q);
    if(left!=NULL&&right!=NULL)return root;

    if(left!=NULL&&right==NULL)return left;
    else if(left==NULL&&right!=NULL)return right;
    else{
        return NULL;
    }
}
TreeNode*RecentPublicAncestors::lowsetCommonAncestorS(TreeNode*root,int p,int q){
    if(root==NULL||root->val==q||root->val==p)return root;
    TreeNode*left=lowsetCommonAncestorS(root->left,p,q);
    TreeNode*right=lowsetCommonAncestorS(root->right,p,q);
    if(left!=NULL&&right!=NULL)return root;

    if(left!=NULL&&right==NULL)return left;
    else if(left==NULL&&right!=NULL)return right;
    else{
        return NULL;
    }
}