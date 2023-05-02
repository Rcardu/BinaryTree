/*
 * @Description: 使用模板创建树
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#endif

template<typename T>
class BiTreeNode{
public:
    T val;
    BiTreeNode<T>*left;
    BiTreeNode<T>*right;
    vector<T>children;
    BiTreeNode(T val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
template<typename T>
class BiTree{
private:
    int size;//树中结点的个数
public:
    BiTreeNode<T>*root;//根节点的指针

    BiTree(){size=0;root=NULL;};
    ~BiTree(){remove(root);};

    bool insert_left(BiTreeNode<T>*node,T val);//插入左孩子
    bool insert_right(BiTreeNode<T>*node,T val);//插入左孩子
    bool remove(BiTreeNode<T>*&node);//删除以node为结点的树
    bool insert_All(BiTreeNode<T>*&node,vector<T>data,int n,int m);//插入函数
};
/**************************************************************************
Function:insert_left
Description:将data插入到node的左孩子
Input:二叉树结点node,数据data
Output:插入是否成功
***************************************************************************/
template<typename T>
bool BiTree<T>::insert_left(BiTreeNode<T>*node,T val){
    if(node==NULL){//如果根节点为空
        if(size>0)return false;
        else root=new BiTreeNode<T>(val);//树的结点树为0，说明根节点没有被插入，先插入根结点
    }else{
        if(node->left!=NULL)return false;//左节点已经有了
        else if(val==-1)return false;
        else node->left=new BiTreeNode<T>(val);//创建一个结点，并将值插入
    }
    size++;
    return true;
}
/**************************************************************************
Function:insert_left
Description:将data插入到node的右孩子
Input:二叉树结点node,数据data
Output:插入是否成功
***************************************************************************/
template<typename T>
bool BiTree<T>::insert_right(BiTreeNode<T>*node,T val){
    if(node==NULL){
        if(size>0)return false;
        else root=new BiTreeNode<T>(val);
    }else{
        if(node->right!=NULL)return false;
        else if(val==-1)return false;
        else node->right=new BiTreeNode<T>(val);
    }
    size++;
    return true;
}
/****************************************************************************
Function:remove
Description:删除以node为根的子树
Input:二叉树结点node的引用
Output:删除是否成功
****************************************************************************/
template<typename T>
bool BiTree<T>::remove(BiTreeNode<T>*&node){
    if(node==NULL)return true;//已经被删除
    if(remove(node->left)&&remove(node->right)){
        delete node;//释放node指向的地址
        node=NULL;
        size--;
        return true;
    }else return false;
}
/*
插入函数
*/
template<typename T>
bool BiTree<T>::insert_All(BiTreeNode<T>*&node,vector<T>data,int n,int m){
    if(n*2+1>=m||n*2+2>m)return false;
    if(n==0){
        insert_left(node,data[n]);
        insert_left(node,data[n+1]);
        insert_right(node,data[n+2]);
    }
    insert_left(node,data[n*2+1]);
    insert_right(node,data[n*2+2]);
    insert_All(node->left,data,n*2+1,m);
    insert_All(node->right,data,n*2+2,m);

    return true;
}