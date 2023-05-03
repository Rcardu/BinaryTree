#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHA_H_
#include<iostream>
#include<vector>
#include"BiaryTrees.h"
#include"BiTreeNode.h"
#endif
#include"LayerOrderTraversal.h"
#include"IterateTraversalOfBinaryTrees.h"
#include"RecursiveTraversalOfBinaryTrees.h"
#include"UnifiedIterativeApproach.h"
#include"FlipTheBinaryTree.h"

using namespace std;

void IputFormat();//链接每层的结点
void LayerOrderTraversalFormat();//广度优先遍历
void IterateTrabersalFormat();//深度优先遍历,迭代
void RecursiveTraversalOfBinaryTreesFormat();//深度优先遍历，递归法
void UnifiendIterativeApproach();//深度优先遍历，统一格式递归版
void FlipTheBinaryTreeFormat();//反转二叉树

/*给定⼀个完美⼆叉树，其所有叶⼦节点都在同⼀层，每个⽗节点都有两个⼦节点。⼆叉树定义如下：
填充它的每个 next 指针，让这个指针指向其下⼀个右侧节点。如果找不到下⼀个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。*/
void IputFormat(){
    int N;
    cin>>N;
    TreeNode*root;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    int sub=0;
    int len=trees.size();
    BiaryTree obj;
    obj.CreatTree(trees,sub,len,root);
    obj.LayerOrderTraversal_connect(root);
    obj.LayerOrderTraversal_connectFormat(root);
}
//广度优先遍历项
void LayerOrderTraversalFormat(){
    int N;
    cin>>N;
    vector<int>result(N);
    for(int i=0;i<N;i++)cin>>result[i];
    BiTree<int>*bitree=new BiTree<int>();
    bitree->insert_All(bitree->root,result,0,N);
    LayerOrderTraversal obj;
    //vector<vector<int>>val=obj.LayerOrderTraversal_acl2(bitree->root);
    /*for(int i=0;i<val.size();i++){
        for(int j=0;j<val[i].size();j++)
            cout<<" "<<val[i][j];
        cout<<endl;
    }*/
    //vector<int>vec=obj.LayerOrderTraversal_acl3(bitree->root);
    //vector<double>vec=obj.LayerOrderTraversal_avg(bitree->root);
    //for(int i=0;i<vec.size();i++)cout<<setiosflags(ios::fixed)<<setprecision(2)<<vec[i]<<endl;
    vector<int>vec=obj.LayerOrderTraversal_max(bitree->root);
    for(int i=0;i<vec.size();i++)cout<<vec[i];
}
//深度优先遍历，迭代法
void IterateTrabersalFormat(){
    BiTree<int>*bitree=new BiTree<int>();
    int N;
    cin>>N;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    
    bitree->insert_Alls(bitree->root,trees,0,N);
    IterateTraversalOfBinaryTrees obj;
    //vector<int>result=obj.IterateTraversalOfBinaryTrees_pro(bitree->root);
    //vector<int>result=obj.IterateTraversalOfBinaryTrees_ins(bitree->root);
    vector<int>result=obj.IterateTraversalOfBinaryTrees_post(bitree->root);
    for(int i=0;i<result.size();i++)cout<<" "<<result[i];
}
//深度优先遍历，递归法
void RecursiveTraversalOfBinaryTreesFormat(){
    BiTree<int>*Bitree=new BiTree<int>();
    int N;
    cin>>N;
    vector<int>data(N);
    for(int i=0;i<N;i++)cin>>data[i];
    Bitree->insert_All(Bitree->root,data,0,N);

    RecursiveTraversalOfBinaryTrees obj;
    vector<int>val=obj.RecursiveTraversalOfBinaryTrees_pro(Bitree->root);
    for(int i=0;i<val.size();i++)cout<<val[i]<<" ";
}
//深度优先遍历，统一格式递归版
//输入输出
void UnifiendIterativeApproach(){
    int N;
    cin>>N;
    vector<int>result(N);
    for(int i=0;i<N;i++)cin>>result[i];
    BiTree<int>*bitree=new BiTree<int>();
    bitree->insert_All(bitree->root,result,0,N);

    UnifiedIterativeApproach obj;
    //vector<int>val=obj.UnifiedIterativeApproach_pro(bitree->root);
    //vector<int>val=obj.UnifiedIterativeApproach_ins(bitree->root);
    vector<int>val=obj.UnifiedIterativeApproach_post(bitree->root);
    for(int i=0;i<val.size();i++)cout<<" "<<val[i];
}
//反转二叉树
void FlipTheBinaryTreeFormat(){
    int N;
    cin>>N;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    int sub=0;
    int len=N;
    TreeNode*root;
    BiaryTree obj;
    obj.CreatTree(trees,sub,len,root);
    FlipTheBinaryTree tcp;//用来反转树
    LayerOrderTraversal Fot;//用来使用层序遍历并输出
    vector<vector<int>>vec=Fot.LayerOrderTraversal_acl(tcp.FlipTheBinaryTree_Arec(root));
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}