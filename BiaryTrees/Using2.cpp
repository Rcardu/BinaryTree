#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHA_H_
#include<iostream>
#include<vector>
#include"BiaryTrees.h"
#include"BiTreeNode.h"
#include"LayerOrderTraversal.h"
#endif
#include"SymmetricalBinaryTree.h"
#include"TheMaximumDepthOfTheBinaryTree.h"
#include"BiaryTress_N.h"
#include"TheMinmumBiaryTrees.h"


using namespace std;
void SymmetricalBinaryTree_AtraverFormat();//镜像树的判断
void TheMaximumDepthOfTheBinaryTree_Format();//最大深度
void Format();//多叉树，深度
void TheMinmumFormat();//最小深度


//镜像树的判断
void SymmetricalBinaryTree_AtraverFormat(){
    int N;
    cin>>N;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    TreeNode*root;
    BiaryTree obj;
    obj.CreatTree(trees,0,N,root);//使用结构创建树
    SymmetricalBinaryTree cat;//判断是否为镜像树
    bool val=cat.SymmetricalBinaryTree_Atsta(root);
    if(val)cout<<"true";
    else cout<<"false";
}
//最大深度,二叉树
void TheMaximumDepthOfTheBinaryTree_Format(){
    int N;
    cin>>N;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    BiTree<int>* bitree=new BiTree<int>();
    bitree->insert_All(bitree->root,trees,0,N);
    TheMaximumDepthOfTheBinaryTree cat;
    int val=cat.TheMaximumDepthOfTheBinaryTree_Asta(bitree->root);
    cout<<val;
}
//多叉树，深度
void Format(){
    MNode node;
    MTree tree;
    node.Parent=nullptr;
    node.element=1;
    tree.init(&node);
    MNode node2,node3,node4,node5,node6,node7,node8,node9,node10;
    node2.element=2,node3.element=3,node4.element=5,node5.element=5,node6.element=6;
    node7.element=7,node8.element=8,node9.element=9,node10.element=10;

    tree.putChild(&node2,&node),tree.putChild(&node3,&node),tree.putChild(&node4,&node);
    tree.putChild(&node5,&node3);
    tree.putChild(&node6,&node4),tree.putChild(&node7,&node4);
    tree.putChild(&node8,&node5),tree.putChild(&node9,&node5);
    tree.putChild(&node6,&node10);
    /*vector<vector<int>>vec=tree.SequentialTraversalOfMultiProngedTrees(&node);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int val=tree.maxDepthTrevers(&node);
    cout<<val;
}
//最小深度
void TheMinmumFormat(){
    int N;
    cin>>N;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    TreeNode*root;
    BiaryTree obj;
    obj.CreatTree(trees,0,N,root);
    //BiTree<int>*obj=new BiTree<int>();
    //obj->insert_All(obj->root,trees,0,N);
    TheMinmumBiaryTrees cat;
    int val=cat.TheMinmumBiaryTrees_ATra(root);
    cout<<val;
}

