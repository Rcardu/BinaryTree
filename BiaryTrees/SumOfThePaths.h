#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include"BiaryTrees.h"
#endif
using namespace std;
class SumOfThePaths
{
private:
    /* data */
public:
    /*给定一个目标和，判断该树中是否存在根节点到叶子节点的路径上，所有的节点值相加等于目标和*/
    /*递归版,先序*/
    bool SumOfThePaths_Arec(TreeNode*node,int count);
    /*迭代版*/
    bool SumOfThePaths_Apro(TreeNode*node,int count);
};
/*目标和==路径和，深度优先遍历
1.确定递归函数及返回值：需要根节点指针，一个int计数器来判断一条边上的总和是否等于目标和
如果需要搜索整颗⼆叉树，那么递归函数就不要返回值，如果要搜索其中⼀条符合条件的路
径，递归函数就需要返回值，因为遇到符合条件的路径了就要及时返回。
寻找最深的节点时，需要搜索整个树来做对比，所以不需要返回值
寻找树的一条路径时，若满足条件就要及时返回，也就是当前叶子节点不满足条件时，返回false进行回溯，进入另一条路
当满足条件时，返回true
bool SumOfThePaths_Arec(TreeNode*node,int count);
2.确定递归终止条件：使用递减count来判断当达到叶子节点时是否为0来进行终止
if(!node->left&&!node->right&&count==0)return true;
if(!node->left&&!node->right)return false;
3.确定单层递归逻辑：首先，不能遍历空节点，其次，当找到路径时，直接返回true即可
if(node->left){
    count-=node->left->val;//递归，处理总和
    if(SumOfThePaths_Arec(node->left,count))return true;
    count+=node->left->val;//回溯，回复总和
}
if(node->right){
    count-=node->right->val;
    if(SumOfThePaths_Arec(node->right,count))return true;
    count+=node->right->val;
}
return false;
*/
bool SumOfThePaths::SumOfThePaths_Arec(TreeNode*node,int count){
    if(!node->left&&!node->right&&count==0)return true;
    if(!node->left&&!node->right)return false;
    if(node->left){
        if(SumOfThePaths_Arec(node->left,count-node->left->val))return true;
    }
    if(node->right){
        if(SumOfThePaths_Arec(node->right,count-node->right->val))return true;
    }
    return false;
}
/*使用栈进行先序遍历*/
bool SumOfThePaths::SumOfThePaths_Apro(TreeNode*node,int count){
    if(node==NULL)return 0;
    stack<pair<TreeNode*,int>>st;
    //<节点，路径值>
    st.push(pair<TreeNode*,int>(node,node->val));
    while(!st.empty()){
        pair<TreeNode*,int>ptr=st.top();
        st.pop();
        //如果该节点时叶子节点，就比较路径和是否满足条件
        if(!ptr.first->left&&!ptr.first->right&&ptr.second==count)return true;
        //右结点，压入一个节点的时候，将其路径也记录下来
        if(ptr.first->right)st.push(pair<TreeNode*,int>(ptr.first->right,ptr.second+ptr.first->right->val));
        if(ptr.first->left)st.push(pair<TreeNode*,int>(ptr.first->left,ptr.second+ptr.first->left->val));
    }
    return false;
}
