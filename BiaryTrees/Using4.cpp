#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHA_H_
#include<iostream>
#include<vector>
#include"BiaryTrees.h"
#include"BiTreeNode.h"
#include"LayerOrderTraversal.h"
#include"ConstructBinaryTree.h"
#include<string>
#endif
#include"MergeTwoBinaryTrees.h"

void MergeTowBinaryTreesformat();//合并两个树


//合并两个树
void MergeTowBinaryTreesformat(){
    int N,M;
    cin>>N>>M;
    vector<int>ionderN(N),postorderN(N);
    vector<int>ionderM(M),postorderM(M);
    for(int i=0;i<N;i++)cin>>ionderN[i];
    for(int i=0;i<N;i++)cin>>postorderN[i];
    for(int i=0;i<M;i++)cin>>ionderM[i];
    for(int i=0;i<M;i++)cin>>postorderM[i];
    ConstructBinaryTree cat;
    MergeTwoBinaryTrees obj;
    LayerOrderTraversal edu;
    vector<vector<int>>vec=edu.LayerOrderTraversal_acl(obj.MergeTwoBinaryTrees_Cpre(cat.Construct_B(ionderN,0,N,postorderN,0,N),cat.Construct_B(ionderM,0,M,postorderM,0,M)));
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
        
        
}