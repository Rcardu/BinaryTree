#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiaryTrees.h"
#include"BiTreeNode.h"
#include<queue>
#include<stack>
#endif
using namespace std;

class NumberOfNodes
{
private:
    /* data */
    
public:
    int result;
    /*二叉树结点个数*/
    int NumberOfNodes_Arec(TreeNode*node);
    /*二叉树结点个数，递归版层序遍历*/
    int NumberOfNodes_ALay(TreeNode*node);
    /*完全二叉树,完全二叉树的节点的个数*/
    int NumberOfNodes_Acom(TreeNode*node);
    /*求二叉树的深度*/
    int NumberOfNodes_maxDepth(TreeNode*node);
    /*求二叉树的深度，先序遍历*/
    void getDopth(TreeNode*node,int depth);
    /*平衡二叉树,递归，后序遍历*/
    int NumberOfNodes_Abance(TreeNode*node);
    /*平衡二叉树的判断，辅助函数*/
    bool Abance_feel(TreeNode*node);
    /*平衡二叉树，迭代法，后序遍历，用来寻找每一个节点为根节点的最大深度*/
    int NumberOfNodes_Bbance(TreeNode*node);
    /*平衡二叉树的判断，迭代法，先序遍历，用来判断是否为平衡二叉树*/
    bool Bbance_feel(TreeNode*node);


};
/*普通二叉树求法，以及完全二叉树求法
1.确定递推函数返回值及参数：传入根节点，返回节点个数
int NumberOfNodes_Arec(TreeNode*node);
2.确定递推函数终止条件如果节点为空，就返回
if(node==NULL)return 0;
3.确定单层递归逻辑，先求左子树的节点数量，再求右子树节点数量，最后返回值+1*/
int NumberOfNodes::NumberOfNodes_Arec(TreeNode*node){
    if(node==NULL)return 0;
    int L_nums=NumberOfNodes_Arec(node->left);
    int R_nume=NumberOfNodes_Arec(node->right);
    int nums=L_nums+R_nume+1;
    return nums;
}
int NumberOfNodes::NumberOfNodes_ALay(TreeNode*node){
    if(node==NULL)return 0;
    queue<TreeNode*>que;
    que.push(node);
    int result=0;
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            TreeNode*ptr=que.front();
            que.pop();
            result++;
            if(ptr->left)que.push(ptr->left);
            if(ptr->right)que.push(ptr->right);
        }
    }
    return result;
}
/*情况一，满二叉树，直接使用2^树的深度-1来计算，
情况二，组后一层叶子节点没有满分别递归左孩子，有孩子，到某一深度一定会有某个孩子为满，使用一来计算*/
int NumberOfNodes::NumberOfNodes_Acom(TreeNode*node){
    if(node==NULL)return 0;
    TreeNode*left=node->left;
    TreeNode*right=node->right;
    int leftnums=0,rightnums=0;
    while(left){
        //求左子树深度
        left=left->left;
        leftnums++;
    }
    while(right){
        right=right->right;
        rightnums++;
    }
    if(leftnums==rightnums){
        return (2<<leftnums)-1;//（2<<1)相当于2^2
    }
    return NumberOfNodes_Acom(node->left)+NumberOfNodes_Acom(node->right);  
}
/*求二叉树节点的深度,先序遍历*/
void NumberOfNodes::getDopth(TreeNode*node,int depth){
    result=result>depth?result:depth;//中间节点

    if(node->left==NULL&&node->right==NULL)return;

    if(node->left){//左
        depth++;//深度加一
        getDopth(node->left,depth);//优化getDopth(node->left,depth+1);
        depth--;//回溯，深度减一
    }
    if(node->right){
        depth++;
        getDopth(node->right,depth);
        depth--;
    }
    return ;
}
/*求二叉树节点的最大深度*/
int NumberOfNodes::NumberOfNodes_maxDepth(TreeNode*node){
    result=0;
    if(node==NULL)return result;
    getDopth(node,1);
    return result;
}
/*平衡二叉树,左右子树高度相差不超过1的树，就是平衡二叉树，这里以根节点为1开始计算
1.确定递归函数参数及返回值：传入指针节点即可，返回值要传入节点为根节点的树的深度
    如果当前传入节点为根节点的二叉树已经不是平衡二叉树了，还返回高度的话，就没有意义了
    如果不是平衡二叉树的话，可以返回-1来标记已经不符合平衡树的规则
    int NumberOfNodes_Abance(TreeNode*node);
2.确定递归终止条件：遇到空节点就终止，返回0，表示当前节点为根节点的树的高度为0
    if(node==NULL)return 0;
3.确定单层递归逻辑：判断这一层的树是否时平衡树的关键在于，左右子树高度相差不过1返回当前树的高度，否则返回-1*/
int NumberOfNodes::NumberOfNodes_Abance(TreeNode*node){
    if(node==NULL)return 0;
    int L_len=NumberOfNodes_Abance(node->left);//左
    if(L_len==-1)return -1;
    int R_len=NumberOfNodes_Abance(node->right);//右
    if(R_len==-1)return -1;

    int result;
    if(abs(L_len-R_len)>1){//中
        result=-1;
    }else{
        result=1+max(L_len,R_len);
    }
    return result;
    /*优化版
    return abs(L_len-R_len)>1?-1:1+max(L_len,R_len);
    */
}
 /*平衡二叉树的判断，辅助函数*/
bool NumberOfNodes::Abance_feel(TreeNode*node){
    return NumberOfNodes_Abance(node)==-1?false:true;
}
/*平衡二叉树，迭代法,后序遍历，求深度*/
int NumberOfNodes::NumberOfNodes_Bbance(TreeNode*node){
    stack<TreeNode*>st;
    if(node!=NULL)st.push(node);
    int len=0;
    int result=0;
    while(!st.empty()){
        TreeNode*ptr=st.top();
        if(ptr){
            st.pop();
            len++;
            st.push(ptr);
            st.push(NULL);
            if(ptr->right)st.push(ptr->right);
            if(ptr->left)st.push(ptr->left);
        }else{
            st.pop();
            len--;
            ptr=st.top();
            st.pop();
        }
        result=result>len?result:len;
    }
    return result;
}
/*平衡二叉树的判断，迭代法，先序遍历，用来判断是否为平衡二叉树*/
bool NumberOfNodes::Bbance_feel(TreeNode*node){
    if(node==NULL)return true;
    stack<TreeNode*>st;
    if(node!=NULL)st.push(node);
    while(!st.empty()){
        TreeNode*ptr=st.top();
        st.pop();
        if(abs(NumberOfNodes_Bbance(ptr->left)-NumberOfNodes_Bbance(ptr->right))>1){
            return false;
        }
        if(ptr->right)st.push(ptr->right);
        if(ptr->left)st.push(ptr->left);
    }
    return true;
}
