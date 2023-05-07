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

class BinarySearchTree
{
private:
    /* data */
    vector<int>result;
    /*使用中序遍历组成有序数组*/
    void SearchTree_ionder(TreeNode*node){
        if(node==NULL)return ;
        SearchTree_ionder(node->left);
        result.push_back(node->val);
        SearchTree_ionder(node->right);
    }
    TreeNode*pre=NULL;//用来记录前一个结点
public:
    /*⼆叉搜索树的最⼩绝对差,有序数组版*/
    int SearchTree_ionderFeel(TreeNode*node){
        result.clear();
        if(result.size()<2)return 0;
        int val=INT_MAX;
        for(int i=1;i<result.size();i++){
            val=min(val,(result[i]-result[i-1]));
        }
        return val;
    }
    /*二叉搜索树的最小差值，递归版*/
    int reval=INT_MAX;//记录最小差值
    void SearchTree_ionderRec(TreeNode*node);
    /*二叉搜索树的最小差值，迭代版*/
    int SearchTree_ionderIter(TreeNode*node);
};
/*二叉搜索树的最小差值，递归版*/
void BinarySearchTree::SearchTree_ionderRec(TreeNode*node){
    if(node==NULL)return ;
    SearchTree_ionderRec(node->left);
    if(pre!=NULL){
        reval=min(reval,(node->val-pre->val));
    }
    pre=node;
    SearchTree_ionderRec(node->right);
}
/*二叉搜索树的最小差值，迭代版*/
int BinarySearchTree::SearchTree_ionderIter(TreeNode*node){
    if(node==NULL)return 0;
    stack<TreeNode*>st;
    TreeNode*ptr=node;
    TreeNode*cur=NULL;//记录前一个结点
    int result=INT_MAX;
    while(ptr!=NULL||!st.empty()){
        if(ptr!=NULL){
            st.push(ptr);
            ptr=ptr->left;
        }else{
            ptr=st.top();
            st.pop();
            if(cur!=NULL){
                result=min(result,(ptr->val-cur->val));
            }
            cur=ptr;
            ptr=ptr->right;
        }
    }
    return result;
}