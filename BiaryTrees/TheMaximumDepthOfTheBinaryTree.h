#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHA_H_
#include<iostream>
#include<vector>
#include"BiaryTrees.h"
#include"BiTreeNode.h"
#include<queue>
#include<stack>
#endif
using namespace std;
class TheMaximumDepthOfTheBinaryTree{
public:
/*递归版*/
int TheMaximumDepthOfTheBinaryTree_Arec(BiTreeNode<int>*node);
/*迭代版，在层序遍历的过程中记录深度*/
int TheMaximumDepthOfTheBinaryTree_Alay(BiTreeNode<int>*node);


};
/*⼆叉树的深度为根节点到最远叶⼦节点的最长路径上的节点数
1.确定递归函数参数及返回值，传入树的根结点，返回树的最长深度
int TheMaximumDepthOfTheBinaryTree_Arec(BiTreeNode<int>*node)
2.确定递归终止条件，如果结点为空的话就返回0，说明高度为0
if(node==NULL)return 0;
3.确定单层递归逻辑，先求左子树深度，再求右子树深度，最后取左右子树最大的值+1，就是目前结点为根结点的树的深度*/
int TheMaximumDepthOfTheBinaryTree::TheMaximumDepthOfTheBinaryTree_Arec(BiTreeNode<int>*node){
    if(node==NULL)return 0;
    int L_len=TheMaximumDepthOfTheBinaryTree_Arec(node->left);
    int R_len=TheMaximumDepthOfTheBinaryTree_Arec(node->right);
    int S_len=max(L_len,R_len)+1;
    /*以上可简化为：
    return max(TheMaximumDepthOfTheBinaryTree_Arec(node->left),TheMaximumDepthOfTheBinaryTree_Arec(node->right))+1*/
    return S_len;
}
/*层序遍历，记录深度*/
int TheMaximumDepthOfTheBinaryTree::TheMaximumDepthOfTheBinaryTree_Alay(BiTreeNode<int>*node){
    if(node==NULL)return 0;
    queue<BiTreeNode<int>*>que;
    que.push(node);
    int len=0;
    while(!que.empty()){
        int size=que.size();
        len++;
        for(int i=0;i<size;i++){
            BiTreeNode<int>*ptr=que.front();
            que.pop();
            if(ptr->left)que.push(ptr->left);
            if(ptr->right)que.push(ptr->right);
        }
    }
    return len;
}