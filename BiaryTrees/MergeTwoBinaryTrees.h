#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiTreeNode.h"
#include"BiaryTrees.h"
#include"ConstructBinaryTree.h"
#include<queue>
#endif
/*给定两个⼆叉树，想象当你将它们中的⼀个覆盖到另⼀个上时，两个⼆叉树的⼀些节点便会重叠。
你需要将他们合并为⼀个新的⼆叉树。合并的规则是如果两个节点重叠，那么将他们的值相
加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新⼆叉树的节点。*/
class MergeTwoBinaryTrees
{
private:
    /* data */
public:
    /*合并两个二叉树，先序*/
    TreeNode*MergeTowBinaryTrees_Apre(TreeNode*t1,TreeNode*t2);
    /*合并两个二叉树，迭代法*/
    TreeNode*MergeTwoBinaryTrees_Bpre(TreeNode*t1,TreeNode*t2);
    /*合并两个二叉树，指向指针的指针*/
    TreeNode*MergeTwoBinaryTrees_Cpre(TreeNode*t1,TreeNode*t2){
        Bpre_Feel(&t1,&t2);
        return t1;
    }
    void Bpre_Feel(TreeNode**T1,TreeNode**T2);

};
/*合并两个二叉树，先序
1.确定递归函数参数及返回值：传入两个结点，返回合成后的节点
TreeNode*MergeTowBinaryTrees_Apro(TreeNode*t1,TreeNode*t2);
2.确定递归终止条件：如果t1为空就返回t2，反之亦然，当两个都为空，合并之后自然也为空
if(t1==NULL)return t2;
if(t2==NULL)return t1;
3.确定单层递归逻辑：重复利用t1节点，合并后就是t1了
t1->val=ti->val+t2->val;
t1->left=MergeTowBinaryTrees_Apro(t1->left,t2->left);
t1->right=MergeTowBinaryTrees_Apro(t1->right,t2->right);
return t1;*/
TreeNode*MergeTwoBinaryTrees::MergeTowBinaryTrees_Apre(TreeNode*t1,TreeNode*t2){
    if(t1==NULL)return t2;
    if(t2==NULL)return t1;
    t1->val+=t2->val;//中
    t1->left=MergeTowBinaryTrees_Apre(t1->left,t2->left);//左
    t1->right=MergeTowBinaryTrees_Apre(t1->right,t2->right);//右
    /*中序，后序都可以  */
    return t1;
}
TreeNode*MergeTwoBinaryTrees::MergeTwoBinaryTrees_Bpre(TreeNode*t1,TreeNode*t2){
    if(!t1)return t2;
    if(!t2)return t1;
    queue<TreeNode*>que;
    que.push(t1);
    que.push(t2);
    while(!que.empty()){
        TreeNode*node1=que.front();que.pop();
        TreeNode*node2=que.front();que.pop();
        node1->val+=node2->val;
        if(node1->left!=NULL&&node2->left!=NULL){
            que.push(node1->left);
            que.push(node2->left);
        }
        if(node1->right!=NULL&&node2->right!=NULL){
            que.push(node1->right);
            que.push(node2->right);
        }
        if(node1->left==NULL&&node1->left!=NULL){
            node1->left=node2->left;
        }
        if(node1->right==NULL&&node2->right!=NULL){
            node1->right=node2->right;
        }
    }
    return t1;
}
/*指向指针的指针
当都为空，直接返回，t1为空，直接返回*/
void MergeTwoBinaryTrees::Bpre_Feel(TreeNode**T1,TreeNode**T2){
    if((*T1)==NULL&&(*T2)==NULL)return ;
    if((*T1)!=NULL&&(*T2)!=NULL){
        (*T1)->val+=(*T2)->val;
    }
    if((*T1)==NULL&&(*T2)!=NULL){
        (*T1)=(*T2);
    }
    if((*T1)!=NULL&&(*T2)==NULL)return ;
    Bpre_Feel(&((*T1)->left),&((*T2)->left));
    Bpre_Feel(&((*T1)->right),&((*T2)->right));
}