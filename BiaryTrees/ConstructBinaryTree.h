#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include"BiaryTrees.h"
#endif
using namespace std;
class ConstructBinaryTree
{
private:
    /* data */
public:
    /*根据⼀棵树的中序遍历与后序遍历构造⼆叉树。*/
    TreeNode* Construct_A(vector<int>&ionder,vector<int>&postorder);
    /*优化版，使用表索引，中序遍历，中序分割起点，中序分割终点，后序遍历，后序分割起点，后序分割终点*/
    TreeNode* Construct_B(vector<int>&ionder,int ionderbegin,int ionderend,vector<int>&postorder,int postorderbegin,int postorderend);
};
/*第一步：如果数组大小为0，说明是空数组
第二步：如果不为0，那么取后序遍历的最后一个元素作为节点元素
第三步：找到后序数组的最后一个元素在中序数组中的位置，作为切割点
第四步：切割中序数组，切成中序左数组和中序右数组（一定是先切中序）
第五步：切割后序数组，切成后序左数组和后序右数组
第六步：递归处理左区间和右区间
*/
TreeNode* ConstructBinaryTree::Construct_A(vector<int>&ionder,vector<int>&postorder){
    //第一步：如果数组大小为0，说明是空数组
    if(postorder.size()==0)return NULL;
    //第二步：如果不为0，那么取后序遍历的最后一个元素作为节点元素
    int rootValue=postorder[postorder.size()-1];
    TreeNode*root=new TreeNode(rootValue);
    //第三步：找到后序数组的最后一个元素在中序数组中的位置，作为切割点
    int delimiterIndex;
    for(delimiterIndex=0;delimiterIndex<ionder.size();delimiterIndex++){
        if(ionder[delimiterIndex]==rootValue)break;
    }
    //第四步：切割中序数组，切成中序左数组和中序右数组（一定是先切中序）
    //左闭右开[0,delimiterIndex);
    vector<int>leftIonder(ionder.begin(),ionder.begin()+delimiterIndex);
    //左闭右开[delimiterIndex,end);
    vector<int>rightIonder(ionder.begin()+delimiterIndex+1,ionder.end());
    //第五步：切割后序数组，切成后序左数组和后序右数组
    /*用已经分割的中序数组的大小来分割后序数组:*/
    //先抛弃后序数组的最后一个元素即，中间节点元素
    postorder.resize(postorder.size()-1);
    //使用中序数组大小作为切割点：[0,leftIonder.size)
    vector<int>leftPostorder(postorder.begin(),postorder.begin()+leftIonder.size());
    //[leftIonder.size,end());
    vector<int>rightPostorder(postorder.begin()+rightIonder.size(),postorder.end());
    //第六步：递归处理左区间和右区间
    root->left=Construct_A(leftIonder,leftPostorder);
    root->right=Construct_A(rightIonder,rightPostorder);
    return root;
}
TreeNode* ConstructBinaryTree::Construct_B(vector<int>&ionder,int ionderbegin,int ionderend,vector<int>&postorder,int postorderbegin,int postorderend){
    //第一步：如果数组大小为0，说明是空数组
    if(postorderbegin==postorderend)return NULL;
    //第二步：如果不为0，那么取后序遍历的最后一个元素作为节点元素
    int rootValue=postorder[postorderend-1];
    TreeNode*root=new TreeNode(rootValue);
    //第三步：找到后序数组的最后一个元素在中序数组中的位置，作为切割点
        //如果传入进来的后序索引相差为1，说明这是这一条路径的最后一个节点，直接返回就行
    if(postorderend-postorderbegin==1)return root;

    int delimiterIndex;//分割标记
    for(delimiterIndex=ionderbegin;delimiterIndex<ionderend;delimiterIndex++){
        if(ionder[delimiterIndex]==rootValue)break;
    }
    //第四步：切割中序数组，切成中序左数组和中序右数组（一定是先切中序）
        //区间左[ionderbegin,delimiterIndex)
    int leftIonderbegin=ionderbegin;
    int leftIonderend=delimiterIndex;
        //区间右[delimiterIndex+1,ionderend)
    int rightIonderbegin=delimiterIndex+1;
    int rightIonderend=ionderend;
    //第五步：切割后序数组，切成后序左数组和后序右数组
        //区间左[postorderbegin,postorderbegin+delimiterIndex-ionderbegin)
    int leftpostorderbegin=postorderbegin;
    int leftpostorderend=postorderbegin+(delimiterIndex-ionderbegin);
        //区间右[postorderbegin+delimiterIndex-ionderbegin,postorderend-1)//去掉后序的最后一个元素
    int rightpostorderbegin=postorderbegin+(delimiterIndex-ionderbegin);
    int rightpostorderend=postorderend-1;
    cout<<"------->"<<endl;
    cout<<"leftIonder:";
    for(int i=leftIonderbegin;i<leftIonderend;i++){
        cout<<ionder[i]<<" ";
    }
    cout<<endl;
    cout<<"rightIonder:";
    for(int i=rightIonderbegin;i<rightIonderend;i++){
        cout<<ionder[i]<<" ";
    }
    cout<<endl;
    cout<<"leftpostorder:";
    for(int i=leftpostorderbegin;i<leftpostorderend;i++){
        cout<<postorder[i]<<" ";
    }
    cout<<endl;
    cout<<"rightpostorder:";
    for(int i=rightpostorderbegin;i<rightpostorderend;i++){
        cout<<postorder[i]<<" ";
    }
    cout<<endl;
    //第六步：递归处理左区间和右区间
    root->left=Construct_B(ionder,leftIonderbegin,leftIonderend,postorder,leftpostorderbegin,leftpostorderend);
    root->right=Construct_B(ionder,rightIonderbegin,rightIonderend,postorder,rightpostorderbegin,rightpostorderend);
    return root;
}
