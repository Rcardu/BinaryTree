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
#include"CommonAncestorSearchTree.h"


using namespace std;

void CommonAncestorSearchTreeFormat();//二叉搜索树的最近公共祖先
void CommonAncestorSearchTree_InsertFormat();//二叉搜索树的插入
void CommonAncestorSearchTree_DelteFormat();//二叉搜索树的删除


//二叉搜索树的最近公共祖先
void CommonAncestorSearchTreeFormat(){
    int N;
    cin>>N;
    vector<int>insert(N);
    for(int i=0;i<N;i++)cin>>insert[i];
    BiaryTree cat;
    CommonAncestorSearchTree obj;
    TreeNode*root;
    cat.CreatTree(insert,0,N,root);
    cout<<obj.CommonAncestorSearchTree_AIter(root,3,5)->val;
}
//二叉搜索树的插入
void CommonAncestorSearchTree_InsertFormat(){
    int N;
    cin>>N;
    vector<int>insert(N);
    for(int i=0;i<N;i++)cin>>insert[i];
    BiaryTree cat;
    CommonAncestorSearchTree obj;
    TreeNode*root;
    cat.CreatTree(insert,0,N,root);
    obj.CommonAncestorSearchTree_InsertIter(root,5);
    cout<<endl;
}
//二叉搜索树的删除
void CommonAncestorSearchTree_DelteFormat(){
    int N;
    cin>>N;
    vector<int>ionter(N);
    vector<int>postrder(N);
    for(int i=0;i<N;i++)cin>>ionter[i];
    for(int i=0;i<N;i++)cin>>postrder[i];
    ConstructBinaryTree cat;
    CommonAncestorSearchTree obj;
    LayerOrderTraversal edu;
    vector<vector<int>>vec=edu.LayerOrderTraversal_acl(obj.CommonAncestorSearchTree_DeleteRec(cat.Construct_B(ionter,0,N,postrder,0,N),1));
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}