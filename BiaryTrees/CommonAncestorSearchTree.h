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

class CommonAncestorSearchTree
{
private:
    /* data */
    TreeNode*parent;//记录父节点
public:
    /*二叉搜索树的最近公共祖先，递归*/
    TreeNode*CommonAncestorSearchTree_ARec(TreeNode*node,int p,int q);
    /*二叉搜索树的最近公共祖先，迭代*/
    TreeNode*CommonAncestorSearchTree_AIter(TreeNode*node,int p,int q);
    /*在二叉搜索树中插入元素*/
    TreeNode*CommonAncestorSearchTree_InsertRec(TreeNode*node,int val);
    /*在二叉搜索树中插入元素*/
    void CommonAncestorSearchTree_InsertRecS(TreeNode*node,int val);
    TreeNode*Insert_RecS(TreeNode*node,int val){
        TreeNode*parent=new TreeNode(0);
        if(node==NULL){
            node=new TreeNode(val);
        }
        return node;
    }
    /*在二叉搜索树中插入元素,迭代*/
    TreeNode*CommonAncestorSearchTree_InsertIter(TreeNode*node,int val);
    /*删除搜索二叉树的一个节点*/
    TreeNode*CommonAncestorSearchTree_DeleteRec(TreeNode*node,int key);
    /*删除二叉树中的节点*/



};
/*二叉搜索树的最近公共祖先，递归
1.确定递归函数参数及返回值：参数就是当前的节点，以及节点p，q,返回公共祖先的节点
TreeNode*CommonAncestorSearchTree_ARec(TreeNode*node,int p,int q);
2.确定递归终止条件：
if(node==NULL)return NULL;
3.确定单层递归逻辑：在遍历二叉树的时候也就是寻找区间[p,q]，
    如果node->val大于p，同时又大于q，那么就应该向左遍历，因为不知道p与q谁大，则需要先判断
if(node->val>p&&node->val>q->val){
    TreeNode*left=CommonAncestorSearchTree_ARec(node->left,p,q);
    if(left!=NULL){
        return left;
    }
}
    如果p，q同时小于node->val，那么就应该向右递归;
if(node->val<p&&node->val<q){
    TreeNode*right=CommonAncestorSearchTree_ARec(node->right,p,q);
    if(right!=NULL){
        return right;
    }
}
剩下的就是node->val在p与q中间了，返回他们的公共祖先即可
return node;*/
TreeNode*CommonAncestorSearchTree::CommonAncestorSearchTree_ARec(TreeNode*node,int p,int q){
    if(node==NULL)return NULL;
    
    if(node->val>p&&node->val>q){
        return CommonAncestorSearchTree_ARec(node->left,p,q);
    }else if(node->val<p&&node->val<q){
        return CommonAncestorSearchTree_ARec(node->right,p,q);
    }else return node;
}
/*二叉搜索树的最近公共祖先，迭代*/
TreeNode*CommonAncestorSearchTree::CommonAncestorSearchTree_AIter(TreeNode*node,int p,int q){
    while(node){
        if(node->val>p&&node->val>q){
            node=node->left;
        }else if(node->val<p&&node->val<q){
            node=node->right;
        }else return node;
    }
    return NULL;
}
/*在二叉搜索树中插入元素
1.确定递归函数参数及返回值：可以利用返回值完成新加入节点与其父节点的赋值操作，传入根节点及要插入的元素即可
TreeNode*CommonAncestorSearchTree_InsertRec(TreeNode*node,int val);
2.确定递归终止条件：找到节点为NULL的时候就是要插入的节点了，返回插入后的节点即可
if(root==NULL){
    TreeNoed*ptr=new TreeNode(val);
    return  ptr;
}
3.确定单层递归逻辑：根据要插入的元素的值确定搜索方向
if(node->val>val)node->left=CommonAncestorSearchTree_InsertRec(node->left,val);
if(node->val<val)node->right=CommonAncestorSearchTree_InsertRec(node->right,val);
return node;*/
TreeNode*CommonAncestorSearchTree::CommonAncestorSearchTree_InsertRec(TreeNode*node,int val){
    if(node==NULL){
        TreeNode*ptr=new TreeNode(val);
        return ptr;
    }
    if(node->val>val)node->left=CommonAncestorSearchTree_InsertRec(node->left,val);
    if(node->val<val)node->right=CommonAncestorSearchTree_InsertRec(node->right,val);
    return node;
}
/*在二叉搜索树中插入节点，无返回类型版*/
void CommonAncestorSearchTree::CommonAncestorSearchTree_InsertRecS(TreeNode*node,int val){
    if(node==NULL){
        node=new TreeNode(val);
        if(val>parent->val)parent->right=node;
        else parent->left=node;
        return ;
    }
    parent=node;//更新父节点
    if(node->val>val)CommonAncestorSearchTree_InsertRecS(node->left,val);
    if(node->val<val)CommonAncestorSearchTree_InsertRecS(node->right,val);
    return ;
}
/*在二叉搜索树中插入节点，迭代*/
TreeNode*CommonAncestorSearchTree::CommonAncestorSearchTree_InsertIter(TreeNode*node,int val){
    if(node==NULL){
        node=new TreeNode(val);
        return node;
    }
    TreeNode*ptr=node;
    TreeNode*parent=node;//记录父节点
    while(ptr!=NULL){
        parent=ptr;//更新父节点
        if(ptr->val>val)ptr=ptr->left;
        else ptr=ptr->right;
    }
    ptr=new TreeNode(val);
    if(val>parent->val)parent->right=ptr;
    else parent->left=ptr;
    return node;
}
/*删除搜索二叉树的一个节点
1.确定递归函数参数及返回值：传入根节点，要删除的节点的值，利用返回值来确定删除的节点
TreeNode*CommonAncestorSearchTree_DeleteRec(TreeNode*node,int key);
2.确定递归终止条件：没有找到要删除的节点就直接返回
if(node==NULL)return node;
3.确定单层递归逻辑：
    ~没有找到，返回就行
    ~找到了
        ~左右孩子都为空（叶子节点），直接删除节点，返回NULL，为根节点
        ~左为空，右不为空，删除节点，右孩子补位，返回右孩子为根节点
        ~右为空，左不为空，删除节点，左孩子不为，返回左孩子为根节点
        ~左右都不为空，删除节点，右孩子补位，将左孩子放到右孩子的左叶子节点的左边节点,返回所删除节点的有孩子为根节点*/
TreeNode*CommonAncestorSearchTree::CommonAncestorSearchTree_DeleteRec(TreeNode*node,int key){
    //第一种情况，没找到，直接返回;
    if(node==NULL)return node;
    if(node->val==key){
        //第二种情况，左右孩子都为空，直接删除节点，返回NULL
        if(node->left==NULL&&node->right==NULL)return NULL;
        //第三种情况，左为空，右不为空，删除节点，右孩子补位，返回右孩子为根节点
        if(node->left==nullptr)return node->right;
        //第四种情况，右为空，左不为空，删除节点，左孩子不为，返回左孩子为根节点
        else if(node->right==nullptr)return node->left;
        else{//第五种情况，左右都不为空，删除节点，右孩子补位，将左孩子放到右孩子的左叶子节点的左边节点,返回所删除节点的有孩子为根节点
            TreeNode*ptr=node->right;
            while(ptr->left!=NULL){
                ptr=ptr->left;
            }
            ptr->left=node->left;//把要删除的节点的左孩子放到右孩子的最左侧
            TreeNode* tmp=node;
            node=node->right;
            delete tmp;//释放内存

            return node;
        }

    }
    if(node->val>key)node->left=CommonAncestorSearchTree_DeleteRec(node->left,key);
    if(node->val<key)node->right=CommonAncestorSearchTree_DeleteRec(node->right,key);
    return node;
}
