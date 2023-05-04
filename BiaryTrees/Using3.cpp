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

using namespace std;
void SumOfTheLeftLeavesFormat();//左叶子之和，最左边叶子的值
void SumOfThePathsFormat();//路径总和

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
    bool val=cat.SumOfThePaths_Arec(root,22);
    cout<<val;
}