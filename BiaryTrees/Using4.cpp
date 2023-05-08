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
#include"BinarySearchTree.h"
#include"MapSearchTree.h"
#include"SearchTree.h"
#include"RecentPublicAncestors.h"

void MergeTowBinaryTreesformat();//合并两个树
void searchBST_Foramt();//搜索二叉搜索树中的值
void searchBTS_ifFormat();//判读是否为二叉搜索树
void SearchTree_minValFormat();//二叉搜索树的最小差值
void MapSearchTree_Format();//二叉树中的众数
void SearchTree_format();//二叉搜索树中的众数
void RecentPublicAncestors_Format();//二叉树的最近公共祖先


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
}//搜索二叉搜索树中的值
void searchBST_Foramt(){
    int N;
    cin>>N;
    vector<int>ionder(N),postorder(N);
    for(int i=0;i<N;i++)cin>>ionder[i];
    for(int i=0;i<N;i++)cin>>postorder[i];
    ConstructBinaryTree cat;
    MergeTwoBinaryTrees obj;
    LayerOrderTraversal edu;
    vector<vector<int>>vec=edu.LayerOrderTraversal_acl(obj.searchBST_AIter(cat.Construct_B(ionder,0,N,postorder,0,N),2));
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }  
}
//判读是否为二叉搜索树
void searchBTS_ifFormat(){
    int N;
    cin>>N;
    vector<int>ionder(N),postorder(N);
    for(int i=0;i<N;i++)cin>>ionder[i];
    for(int i=0;i<N;i++)cin>>postorder[i];
    ConstructBinaryTree cat;
    MergeTwoBinaryTrees obj;
    //obj.searchBST_if(cat.Construct_B(ionder,0,N,postorder,0,N));
    //cout<<obj.if_feel();
    cout<<obj.isValildBTS_Iter(cat.Construct_B(ionder,0,N,postorder,0,N));
}
//二叉搜索树的最小差值
void SearchTree_minValFormat(){
    int N;
    cin>>N;
    vector<int>ionder(N),postorder(N);
    for(int i=0;i<N;i++)cin>>ionder[i];
    for(int i=0;i<N;i++)cin>>postorder[i];
    ConstructBinaryTree cat;
    BinarySearchTree obj;
    //obj.SearchTree_ionderRec(cat.Construct_B(ionder,0,N,postorder,0,N));
    //cout<<obj.reval;
    cout<<obj.SearchTree_ionderIter(cat.Construct_B(ionder,0,N,postorder,0,N));
}
/*二叉树中的众数*/
void MapSearchTree_Format(){
    int N;
    cin>>N;
    vector<int>ionder(N);
    for(int i=0;i<N;i++)cin>>ionder[i];
    TreeNode*root;
    BiaryTree car;
    MapSearchTree obj;
    car.CreatTree(ionder,0,N,root);
    vector<int>result=obj.findMode(root);
    for(int i=0;i<result.size();i++)cout<<result[i];
}
//二叉搜索树中的众数
void SearchTree_format(){
    int N;
    cin>>N;
    vector<int>ionder(N);
    for(int i=0;i<N;i++)cin>>ionder[i];
    TreeNode*root;
    BiaryTree car;
    SearchTree obj;
    car.CreatTree(ionder,0,N,root);
    vector<int>result=obj.SearchTree_AIter(root);
    for(int i=0;i<result.size();i++)cout<<result[i];
}
//二叉树的最近公共祖先
void RecentPublicAncestors_Format(){
    int N;
    cin>>N;
    vector<int>ionder(N),postorder(N);
    for(int i=0;i<N;i++)cin>>ionder[i];
    for(int i=0;i<N;i++)cin>>postorder[i];
    ConstructBinaryTree cat;
    RecentPublicAncestors obj;
    //TreeNode*root,*p,*q;
    /*root=cat.Construct_B(ionder,0,N,postorder,0,N);
    cout<<obj.lowsetCommonAncestor(root,obj.Search_RootA(root,6),obj.Search_RootA(root,7))->val;*/
    cout<<obj.lowsetCommonAncestorS(cat.Construct_B(ionder,0,N,postorder,0,N),5,6)->val;
}