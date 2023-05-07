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
/*给定两个⼆叉树，想象当你将它们中的⼀个覆盖到另⼀个上时，两个⼆叉树的⼀些节点便会重叠。
你需要将他们合并为⼀个新的⼆叉树。合并的规则是如果两个节点重叠，那么将他们的值相
加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新⼆叉树的节点。*/
class MergeTwoBinaryTrees
{
private:
    /* data */
public:
    vector<int>result;
    /*合并两个二叉树，先序*/
    TreeNode*MergeTowBinaryTrees_Apre(TreeNode*t1,TreeNode*t2);
    /*合并两个二叉树，迭代法*/
    TreeNode*MergeTwoBinaryTrees_Bpre(TreeNode*t1,TreeNode*t2);
    /*合并两个二叉树，指向指针的指针*/
    TreeNode*MergeTwoBinaryTrees_Cpre(TreeNode*t1,TreeNode*t2){
        Bpre_Feel(&t1,&t2);
        return t1;
    }
    /*合并两个二叉树，指向指针的指针*,实现函数*/
    void Bpre_Feel(TreeNode**T1,TreeNode**T2);
    /*给定一个二叉搜索树，一个值，在树中找出该值的节点*/
    TreeNode*searchBST_Arec(TreeNode*node,int val);
    /*迭代法,二叉搜索树*/
    TreeNode*searchBST_AIter(TreeNode*node,int val);
    /*验证二叉搜索树,使用数组来判断其中序是否有序*/
    void searchBST_if(TreeNode*node){
        if(node==NULL)return ;
        searchBST_if(node->left);
        result.push_back(node->val);
        searchBST_if(node->right);
    }
    bool if_feel(){
        if(result.size()==0)return true;
        for(int i=1;i<result.size();i++){
            if(result[i-1]>result[i])return false;
        }
        return true;
    }
    /*验证是否为搜索二叉树，递归*/
    long long maxVal=LONG_MIN;//使用全局最小值记录
    TreeNode*ptr=NULL;//使用前一个结点来判断
    bool isValildBTS(TreeNode*node);
    /*迭代法，验证二叉搜索树*/
    bool isValildBTS_Iter(TreeNode*node);




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
/*给定一个二叉搜索树，一个值，在树中找出该值的节点
1.*确定递归函数参数及返回值：传入根节点与要搜索到的值，返回该值的节点
TreeNode*searchBST_Arec(TreeNode*node,int val);
2.确定递归终止条件：如果当前节点为空或者找到这个节点了，就返回
if(node==NULL||node->val==val)return root;
3.确定单层递归逻辑：如果当前节点值大于目标值，进入左子树，如果当前节点值小于目标值，进入右子树
if(node->val>val)return searchBST_Arec(node->left,val);
if(node->val<val)return searchBST_Arec(node->right,val);
return NULL
并不一定要搜索整棵树，所以当找到目标值时，直接返回*/
TreeNode*MergeTwoBinaryTrees::searchBST_Arec(TreeNode*node,int val){
    if(node==NULL||node->val==val)return node;
    if(node->val>val)return searchBST_Arec(node->left,val);
    if(node->val<val)return searchBST_Arec(node->right,val);
    return NULL;
}
/*迭代法*/
TreeNode*MergeTwoBinaryTrees::searchBST_AIter(TreeNode*node,int val){
    while(node){
        if(node->val>val)node=node->left;
        else if(node->val<val)node=node->right;
        else return node;
    }
    return NULL;
}
/*验证二叉搜索树,判断一棵树是否是二叉搜索树
1.确定递归函数参数及返回值：定义一个long long类型的全局变量最为最小值，传入根节点，返回bool类型
long long maxVal=LONG_MIN;
bool isValildBTS(TreeNode*node);
2.确定递归函数终止条件：
if(node==NULL)return true;
3.确定单层递归逻辑：在递归过程中更新maxValue一旦发现maxValue>=node-val,返回false
bool left=isValildBTS(node->left);
if(maxValue<node->val)maxValue=node->val;
else return false;
bool right=isValildBTS(node->right);
return left&&right;*/
bool MergeTwoBinaryTrees::isValildBTS(TreeNode*node){
    if(node==NULL)return true;
    bool left=isValildBTS(node->left);
    if(ptr!=NULL&&ptr->val>=node->val)return false;
    ptr=node;
    bool right=isValildBTS(node->right);
    return left&&right;
}
bool MergeTwoBinaryTrees::isValildBTS_Iter(TreeNode*node){
    stack<TreeNode*>st;
    TreeNode*ptr=node;
    TreeNode*cur=NULL;//记录前一个结点
    while(ptr!=NULL||!st.empty()){
        if(ptr!=NULL){
            st.push(ptr);
            ptr=ptr->left;
        }else{
            ptr=st.top();
            st.pop();
            if(cur!=NULL&&ptr->val<=cur->val)return false;
            cur=ptr;

            ptr=ptr->right;
        }
    }
    return true;
}