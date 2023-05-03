/*求最小深度，根节点到叶子结点的最少结点数，叶子结点就是当前结点左右子树为空*/
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiTreeNode.h"
#include"BiaryTrees.h"
#include<queue>
#endif

using namespace std;

class TheMinmumBiaryTrees{
public:
    /*求最小深度，递归版*/
    int TheMinmumBiaryTrees_Arec(BiTreeNode<int>*node);
    /*求最小深度，迭代法*/
    int TheMinmumBiaryTrees_ATra(TreeNode*node);
};
/*求最小深度，递归版
1.确定递归函数参数及返回值，传入根结点的指针即可，返回长度
int TheMinmumBiaryTrees_Arec(BiTreeNode<int>*node)
2.确定递归终止条件，空结点返回0，表示高度为0
if(node==NULL)return 0;
3.确定单层递归逻辑
    ~当左子树为空，右子树不为空，返回右子树深度+1
    ~当右子树为空同理
    ~当左右子树都不为空，返回左右子树最小深度+1*/
int TheMinmumBiaryTrees::TheMinmumBiaryTrees_Arec(BiTreeNode<int>*node){
    if(node==NULL)return 0;
    int L_len=TheMinmumBiaryTrees_Arec(node->left);
    int R_len=TheMinmumBiaryTrees_Arec(node->right);
    if(node->left==NULL&&node->right!=NULL)return R_len+1;
    else if(node->left!=NULL&&node->right==NULL)return L_len+1;
    else return min(L_len,R_len)+1;
}
/*当左右孩子都为空，才算到最低点，否则不是*/
int TheMinmumBiaryTrees::TheMinmumBiaryTrees_ATra(TreeNode*node){
    if(node==NULL)return 0;
    int depth=0;
    queue<TreeNode*>que;
    que.push(node);
    while(!que.empty()){
        int size=que.size();
        depth++;
        for(int i=0;i<size;i++){
            TreeNode*ptr=que.front();
            que.pop();
            if(ptr->left)que.push(ptr->left);
            if(ptr->right)que.push(ptr->right);
            if(!ptr->left&&!ptr->right){
                //当左右孩子都为空时，说明是最低点了，退出
                return depth;
            }
        }
    }
    return depth;
}