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
/*给定⼀个⼆叉树，检查它是否是镜像对称的*/
class SymmetricalBinaryTree{
public:
/*镜像对称,递归法*/
bool SymmetricalBinaryTree_Atraver(TreeNode*left,TreeNode*right);
/*中间传入函数*/
bool is_Atraver(TreeNode*node);
/*镜像对称，迭代法，使用队列*/
bool SymmetricalBinaryTree_Atque(TreeNode*node);
/*镜像对称，迭代法，使用栈*/
bool SymmetricalBinaryTree_Atsta(TreeNode*node);

};
/*需要通过递归函数的返回值来比较两颗子树的里侧和外侧是否相等
准确来说就是一个树采用左右中，一颗树采用右左中
1.确定递归函数参数即返回值，判断是否对称，返回值为bool。判断目标为左右子树，故参数为左右结点
2.确定终止条件，首先，结点为空该怎么办:
    ~左节点为空，右节点不为空，不对称，返回false
    ~左不为空，右为空，返回false
    ~左右都为空，返回true
其次，左右不为空：
    ~比较左右节点的值
    if(left==NULL&&right!=NULL)return false;
    else if(left!=NULL&&right==NULL)return false;
    else if(left==NULL&right==NULL)return ture;
    else if(left->val!=right->val)return false;
    else
3.确定单层递归逻辑，这时处理左右结点都不为空
    ~比较二叉树外侧是否对称，传入二叉树左结点的左孩子，右节点的右孩子
    ~比较二叉树内侧是否对称，传入左结点右孩子，右结点左孩子
    ~如果左右都对称就返回true，有一侧不对称就返回false*/
bool SymmetricalBinaryTree::SymmetricalBinaryTree_Atraver(TreeNode*left,TreeNode*right){
    if(left==NULL&&right!=NULL)return false;
    else if(left!=NULL&&right==NULL)return false;
    else if(left==NULL&&right==NULL)return true;
    //处理完结点为空的情况，再处理不为空的情况
    else if(left->val!=right->val)return false;
    bool is_outside=SymmetricalBinaryTree_Atraver(left->left,right->right);//左子树：左，右子树：右
    bool is_inside=SymmetricalBinaryTree_Atraver(left->right,right->left);//左子树：右，右子树：左
    bool is_same=is_outside&&is_inside;//逻辑处理,在递归中，有一个false出现，那么全程都是false，即树不对称
    return is_same;
    /*以上判断左右子树都有的情况可以整理如下：
    else return SymmetricalBinaryTree_Atraver(left->left,right->right)&&SymmetricalBinaryTree_Atraver(left->right,right->left);
    */
}
bool SymmetricalBinaryTree::is_Atraver(TreeNode*node){
    if(node==NULL)return true;//空本来就对称
    return SymmetricalBinaryTree_Atraver(node->left,node->right);
}
/*用一个队列将左子树的左，右子树的右，左子树的右，右子树的左依次放入
判断两两是否满足镜像条件*/
bool SymmetricalBinaryTree::SymmetricalBinaryTree_Atque(TreeNode*node){
    if(node==NULL)return true;
    queue<TreeNode*>que;
    que.push(node->left);
    que.push(node->right);
    while(!que.empty()){
        TreeNode*Leftptr=que.front();que.pop();
        TreeNode*Rightptr=que.front();que.pop();
        if(!Leftptr&&!Rightptr){//都为空对称的，返回并判断下一组
            continue;
        }
        //左右一个不为空，或者都不为空但是值不相等，不是镜像，返回false
        if((!Leftptr||!Rightptr||(Leftptr->val!=Rightptr->val)))return false;
        que.push(Leftptr->left);//左树的左
        que.push(Rightptr->right);//右树的右
        que.push(Leftptr->right);//左树的右
        que.push(Rightptr->left);//右树的左
    }
    return true;//遍历完成后，即镜像对称
}
/*方法类队列，两两比较*/
bool SymmetricalBinaryTree::SymmetricalBinaryTree_Atsta(TreeNode*node){
    if(node==NULL)return true;
    stack<TreeNode*>st;
    st.push(node->left);
    st.push(node->right);
    while(st.empty()){
        TreeNode*Leftptr=st.top();st.pop();
        TreeNode*Rightptr=st.top();st.pop();
        if(!Leftptr&&!Rightptr)continue;
        if((!Leftptr||!Rightptr||(Leftptr->val!=Rightptr->val)))return false;
        st.push(Leftptr->left);
        st.push(Rightptr->right);
        st.push(Leftptr->right);
        st.push(Rightptr->left);
    }
    return true;
}