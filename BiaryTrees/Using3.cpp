#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHA_H_
#include<iostream>
#include<vector>
#include"BiaryTrees.h"
#include"BiTreeNode.h"
#include"LayerOrderTraversal.h"
#include<string>
#endif
#include"SumOfTheLeftLeaves.h"
#include"SumOfThePaths.h"
#include"ConstructBinaryTree.h"

using namespace std;
void SumOfTheLeftLeavesFormat();//左叶子之和，最左边叶子的值
void SumOfThePathsFormat();//路径总和
void COnstructBinaryFormat();//构造二叉树,中后序，前中序，最大值构造

void SumOfTheLeftLeavesFormat(){
    int N;
    cin>>N;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    BiaryTree obj;
    TreeNode*root;
    obj.CreatTree(trees,0,N,root);
    SumOfTheLeftLeaves cat;
    //int val=cat.SumOfTheLeftLeaves_Btra(root);
    //cat.MaxLeft_Arec(root,0);
    //int val=cat.maxleftValue;
    int val=cat.MaxLeft_Alay(root);
    cout<<val;
}
//路径总和
void SumOfThePathsFormat(){
    int N;
    cin>>N;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    BiaryTree obj;
    TreeNode*root;
    obj.CreatTree(trees,0,N,root);
    SumOfThePaths cat;
    bool val=cat.SumOfThePaths_Apro(root,22);
    cout<<val;
}
//构造二叉树
void COnstructBinaryFormat(){
    int N;
    cin>>N;
    vector<int>ionder(N),posterder(N);
    for(int i=0;i<N;i++)cin>>ionder[i];
    for(int i=0;i<N;i++)cin>>posterder[i];
    ConstructBinaryTree obj;
    //LayerOrderTraversal cat;
    //vector<vector<int>>vec=cat.LayerOrderTraversal_acl(obj.Construct_A(ionder,posterder));
    //vector<vector<int>>vec=cat.LayerOrderTraversal_acl(obj.Construct_Apro(ionder,0,N,posterder,0,N));
    /*for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
      */
     vector<int>proder;
     obj.Construct_CreatproB(ionder,0,N,posterder,0,N,proder);
     for(int i=0;i<proder.size();i++)cout<<proder[i]<<" ";
}
    