/*
关于递归：
1. 确定递归函数的参数和返回值：
确定哪些参数是递归的过程中需要处理的，那么就在递归函数⾥加上这个参数，
并且还要明确每次递归的返回值是什么进⽽确定递归函数的返回类型。
2. 确定终⽌条件：
写完了递归算法, 运⾏的时候，经常会遇到栈溢出的错误，就是没写终⽌条件或者
终⽌条件写的不对，操作系统也是⽤⼀个栈的结构来保存每⼀层递归的信息，如果
递归没有终⽌，操作系统的内存栈必然就会溢出。
3. 确定单层递归的逻辑：
确定每⼀层递归需要处理的信息。在这⾥也就会重复调⽤⾃⼰来实现递归的过程。
*/
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiaryTrees.h"
#include"BiTreeNode.h"
#endif

using namespace std;

class RecursiveTraversalOfBinaryTrees
{
public:
//先序遍历
void traversal_A(BiTreeNode<int>*tree,vector<int>&vec);
//先序遍历递归体
vector<int>RecursiveTraversalOfBinaryTrees_pro(BiTreeNode<int>*tree);
//中序遍历
void traversal_B(BiTreeNode<int>*tree,vector<int>&vec);
//中序遍历递归体
vector<int>RecursiveTraversalOfBinaryTrees_ins(BiTreeNode<int>*tree);
//后序遍历
void traversal_C(BiTreeNode<int>*tree,vector<int>&vec);
//后序遍历递归体
vector<int>RecursiveTraversalOfBinaryTrees_post(BiTreeNode<int>*tree);
};
/*先序遍历
***确定递归函数的参数及返回值
因为要打印出先序遍历的数值，所以需要引用类型的数组来记录先序遍历的结果
除此之外不需要其他
void RecursiveTraversalOfBinaryTrees_pro(BiTreeNode*tree,vector<T>&vec);
***确定终止条件
在递归的过程中，结束递归的条件就是当目前遍历的结点是空即，if(tree==NULL)return
***确定单层递归的逻辑
在先序遍历中，先取中间结点，再左右
vec.push_back(tree->val);
RecursiveTraversalOfBinaryTrees_pro(tree->left,vec);
RecursiveTraversalOfBinaryTrees_pro(tree->right,vec);
*/
void RecursiveTraversalOfBinaryTrees::traversal_A(BiTreeNode<int>*tree,vector<int>&vec){
    if(tree==NULL)return;
    vec.push_back(tree->val);
    traversal_A(tree->left,vec);
    traversal_A(tree->right,vec);
}
vector<int> RecursiveTraversalOfBinaryTrees::RecursiveTraversalOfBinaryTrees_pro(BiTreeNode<int>*tree){
    vector<int>vec;
    traversal_A(tree,vec);
    return vec;
}
/*中序遍历*/
void RecursiveTraversalOfBinaryTrees::traversal_B(BiTreeNode<int>*tree,vector<int>&vec){
    if(tree==NULL)return;
    traversal_B(tree->left,vec);
    vec.push_back(tree->val);
    traversal_B(tree->right,vec);
}
vector<int> RecursiveTraversalOfBinaryTrees::RecursiveTraversalOfBinaryTrees_ins(BiTreeNode<int>*tree){
    vector<int>vec;
    traversal_B(tree,vec);
    return vec;
}
//后序遍历
void RecursiveTraversalOfBinaryTrees::traversal_C(BiTreeNode<int>*tree,vector<int>&vec){
    if(tree==NULL)return;
    traversal_C(tree->left,vec);
    traversal_C(tree->right,vec);
    vec.push_back(tree->val);
}
vector<int> RecursiveTraversalOfBinaryTrees::RecursiveTraversalOfBinaryTrees_post(BiTreeNode<int>*tree){
    vector<int>vec;
    traversal_C(tree,vec);
    return vec;
}

