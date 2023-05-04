#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include"BiaryTrees.h"
#endif
class SumOfTheLeftLeaves
{
private:
    /* data */
public:
    int maxLen=INT_MIN;//全局变量，来记录最大深度
    int maxleftValue;//全局变量，最大深度最左节点的数值
    /*左叶子之和*/
    int SumOfTheLeftLeaves_Arec(TreeNode*node);
    /*先序遍历，左叶子之和，迭代版*/
    int SumOfTheLeftLeaves_Atra(TreeNode*node);
    /*中序遍历，左叶子之和，迭代版*/
    int SumOfTheLeftLeaves_Btra(TreeNode*node);
    /*树左下角的值*/
    void MaxLeft_Arec(TreeNode*node,int leftLen);
    /*树左下角的值，层序遍历*/
    int MaxLeft_Alay(TreeNode*node);
};
/*计算给定的树的左叶子的和
如果左节点不为空，且此节点的左右节点都为空，那么这个节点就是左叶子节点
也就是说当一个节点的左节点不为空，且这个节点的左结点与右结点都为空，那么该节点的左结点就是左叶子
if(node->left!=NULL&&(node->left->left==NULL&&node->left->right==NULL)){
    左叶子处理逻辑;
}
1.确定递归函数参数及返回值：传入根节点，返回左叶子的和int
int SumOfTheLeftLeaves_Arec(TreeNode*node);
2.确定递归终止条件：
if(node==NULL)return 0;
3.确定单层递归逻辑：当遇到左叶子的时候记录左叶子的值，通过递归求取左子树左叶子的和，右子树左叶子的和，相加
int L_nums=SumOfTheLeftLeaves_Arec(node->left);
int R_nums=SumOfTheLeftLeaves_Arec(node->right);
int M_nums=0;
if(node->left!=NULL&&(node->left->left==NULL&&node->left->right==NULL)){
    M_num=node->left->val;
}
int sum=M_num+L_num+R_num;
return sum;
*/
int SumOfTheLeftLeaves::SumOfTheLeftLeaves_Arec(TreeNode*node){
    if(node==NULL)return 0;
    int sum=0;
    if(node->left!=NULL&&(node->left->left==NULL&&node->left->right==NULL)){
        sum+=node->left->val;
    }
    return sum+SumOfTheLeftLeaves_Arec(node->left)+SumOfTheLeftLeaves_Arec(node->right);
}
/*先序遍历左叶子之和，迭代版, 通过深度优先遍历来计算
判断当前节点的左结点是否为左叶子*/
int SumOfTheLeftLeaves::SumOfTheLeftLeaves_Atra(TreeNode*node){
    if(node==NULL)return 0;
    stack<TreeNode*>st;
    st.push(node);
    int result=0;
    while(!st.empty()){
        TreeNode*ptr=st.top();
        st.pop();
        if(ptr->left!=NULL&&(ptr->left->left==NULL&&ptr->left->right==NULL)){
            result+=ptr->left->val;
        }
        if(ptr->right)st.push(ptr->right);
        if(ptr->left)st.push(ptr->left);
    }
    return result;
}
/*中序遍历，左叶子之和，迭代版*/
int SumOfTheLeftLeaves::SumOfTheLeftLeaves_Btra(TreeNode*node){
    if(node==NULL)return 0;
    stack<TreeNode*>st;
    st.push(node);
    int result=0;
    while(!st.empty()){
        TreeNode*ptr=st.top();
        if(ptr){
            st.pop();
            if(ptr->right)st.push(ptr->right);
            st.push(ptr);
            st.push(NULL);
            if(ptr->left)st.push(ptr->left);
        }else{
            st.pop();
            ptr=st.top();
            st.pop();
            if(ptr->left!=NULL&&(ptr->left->left==NULL&&ptr->left->right==NULL)){
                result+=ptr->left->val;
            }
        }
    }
    return result;
}
/*树左下角的值，给定一棵树，求树的最后一行最左边的值
1.确定递归函数参数及返回值：输入根节点，int类型变量来记录深度，不需要返回值
int maxLen=INT_MIN//全局变量，来记录最大深度
int maxleftValue;//全局变量，最大深度最左节点的数值
void MaxLeft_Arec(TreeNode*node,int leftLen)
2.确定递归终止条件：当遇到叶子节点时开始统计最大深度
if(node->left==NULL&&node->right==NULL){
    if(leftLen>maxLen){
        maxLen=leftLen;
        maxleftValue=node->val;
    }
    return;
}
3.确定单层递归逻辑：递归过程中使用回溯
if(node->left){
    leftLen++;
    MaxLeft_Arec(node->left,leftLen);
    leftLen--;//回溯减一
}
if(node->right){
    leftLen++;
    MaxLeft_Arec(node->right,leftLen);
    leftLen--;
}*/
void SumOfTheLeftLeaves::MaxLeft_Arec(TreeNode*node,int leftLen){
    if(node->left==NULL&&node->right==NULL){
        if(leftLen>maxLen){
            maxLen=leftLen;
            maxleftValue=node->val;
        }
        return ;
    }
    if(node->left)MaxLeft_Arec(node->left,leftLen+1);
    if(node->right)MaxLeft_Arec(node->right,leftLen+1);
}
/*每次记录每层最左边的值，覆盖到最后一层*/
int SumOfTheLeftLeaves::MaxLeft_Alay(TreeNode*node){
    if(node==NULL)return 0;
    queue<TreeNode*>que;
    que.push(node);
    int L_num;
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            TreeNode*ptr=que.front();
            que.pop();
            if(ptr->left)que.push(ptr->left);
            if(ptr->right)que.push(ptr->right);
            if(i==0)L_num=ptr->val;
        }
    }
    return L_num;
}
