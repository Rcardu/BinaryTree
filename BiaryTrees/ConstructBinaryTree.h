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
    TreeNode* Construct_ACreat(vector<int>&ionder,vector<int>&postorder);
    /*优化版，使用表索引，中序遍历，中序分割起点，中序分割终点，后序遍历，后序分割起点，后序分割终点*/
    TreeNode* Construct_B(vector<int>&ionder,int ionderbegin,int ionderend,vector<int>&postorder,int postorderbegin,int postorderend);
    /*先序与中序构造二叉树*/
    TreeNode* Construct_Apro(vector<int>&porder,int porderbegin,int porderderend,vector<int>&ionder,int ionderbegin,int ionderend);
    /*构造一棵最大的二叉树*/
    TreeNode*Construct_GreadPro(vector<int>&nums);
    /*使用表索引*/
    TreeNode*Construct_GreadProB(vector<int>&nums,int left,int right);
    /*通过中序遍历和后序遍历得到先序遍历*/
    void Construct_Creatpro(vector<int>&ionder,vector<int>&postorder, vector<int>&proder);
    /*使用表索引*/
    void Construct_CreatproB(vector<int>&ionder,int ionderBegin,int ionderEnd,vector<int>&postorder,int postorderBegin,int postorderEnd, vector<int>&proder);

};  
/*第一步：如果数组大小为0，说明是空数组
第二步：如果不为0，那么取后序遍历的最后一个元素作为节点元素
第三步：找到后序数组的最后一个元素在中序数组中的位置，作为切割点
第四步：切割中序数组，切成中序左数组和中序右数组（一定是先切中序）
第五步：切割后序数组，切成后序左数组和后序右数组
第六步：递归处理左区间和右区间
*/
TreeNode* ConstructBinaryTree::Construct_ACreat(vector<int>&ionder,vector<int>&postorder){
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
    root->left=Construct_ACreat(leftIonder,leftPostorder);
    root->right=Construct_ACreat(rightIonder,rightPostorder);
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
/*先序与中序构造二叉树*/
TreeNode*ConstructBinaryTree::Construct_Apro(vector<int>&porder,int porderbegin,int porderderend,vector<int>&ionder,int ionderbegin,int ionderend){
    //第一步：如果数组大小为0，说明是空数组
    if(porderbegin==porderderend)return NULL;
    //第二步：如果不为0，那么取先序遍历的第一个元素作为节点元素
    int rootValue=porder[porderbegin];
    TreeNode*root=new TreeNode(rootValue);
    //第三步：找到先序数组的第一个元素在中序数组中的位置，作为切割点
        //如果区间相差为1，则到了本节点的最后一个元素，不需要再分割，直接返回
    if(porderderend-porderbegin==1)return root;
    int delimiterIndex;
    for(delimiterIndex=ionderbegin;delimiterIndex<porderderend;delimiterIndex++){
        if(ionder[delimiterIndex]==rootValue)break;
    }
    //第四步：切割中序数组，切成中序左数组和中序右数组（一定是先切中序）
    int leftionderBegin=ionderbegin;
    int leftionderEnd=delimiterIndex;
    int rightionderBegin=delimiterIndex+1;
    int rightionderEnd=ionderend;
    //第五步：切割后序数组，切成后先序左数组和先序右数组
    int leftporderBegin=porderbegin+1;
    int leftporderEnd=porderbegin+1+delimiterIndex-ionderbegin;//起始位置porderbegin+1,中序区间大小delimiterIndex-ionderbegin
    int rightporderBegin=porderbegin+1+delimiterIndex-ionderbegin;
    int rightporderEnd=porderderend;
    //第六步：递归处理左区间和右区间
    root->left=Construct_Apro(porder,leftporderBegin,leftporderEnd,ionder,leftionderBegin,leftionderEnd);
    root->right=Construct_Apro(porder,rightporderBegin,rightporderEnd,ionder,rightionderBegin,rightionderEnd);
    return root;
}
/*给定⼀个不含重复元素的整数数组。⼀个以此数组构建的最⼤⼆叉树定义如下：
通过给定的数组构建最⼤⼆叉树，并且输出这个树的根节点。
最⼤⼆叉树的构建过程如下：
⼆叉树的根是数组中的最⼤元素。
左⼦树是通过数组中最⼤值左边部分构造出的最⼤⼆叉树。
右⼦树是通过数组中最⼤值右边部分构造出的最⼤⼆叉树。
一般采用先序遍历因为要先创建中间节点
1.确定地推函数参数及返回值：传入存放元素的数组，返回该构造二叉树的头结点
TreeNode*Construct_GreadPro(vector<int>&nums);
2.确定递归终止条件：当递归遍历的时候传入的数组大小为1是说明遇到了叶子节点，构造一个节点，判断是否为1,输入数组值，返回该结点
TreeNode*node=new TreeNode(0);
if(nums.size()==1){
    node->val=nums[0];
    return node;
}
确定单层递归逻辑：找到数组中最大的值和对应下标，最大值用来构造结点，下标用来分割数组
int MaxValue=0;
int MaxValueIndex=0;
for(int i=0;i<nums.size();i++){
    if(nums[i]>MaxValue){
        MaxValue=nums[i];
        MaxValueIndex=i;
    }
}
TreeNode*node=new TreeNode(0);
node->val=MaxValue;
最大值下标的左区间构造左子树,需要判断MaxValueIndex>0,也就是左区间至少要有一个数
if(MaxValue>0){
    vector<int>newVec(nums.begin(),nums.begin()+MaxValueIndex);
    node->left=Construct_GroadPro(newVec);
}
最大值下标右区间构造右子树，需要判断MaxValueIndex<(nums.size()-1)，右区间至少要有一个值
if(MaxValue<nums.size()-1){
    vector<int>newVec(nums.begin()+MaxValueIndex+1,nums.end());
    node->right=Construct_GreadPro(newVec);
}
*/
TreeNode* ConstructBinaryTree::Construct_GreadPro(vector<int>&nums){
    TreeNode*node=new TreeNode(0);
    if(nums.size()==1){
        node->val=nums[0];
        return node;
    }
    int MaxValue=0;
    int MaxValueIndex=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>MaxValue){
            MaxValue=nums[i];
            MaxValueIndex=i;        }
    }
    node->val=MaxValue;
    if(MaxValueIndex>0){
        vector<int>newVec(nums.begin(),nums.begin()+MaxValueIndex);
        node->left=Construct_GreadPro(newVec);
    }
    if(MaxValueIndex<nums.size()-1){
        vector<int>newVec(nums.begin()+MaxValueIndex+1,nums.end());
        node->right=Construct_GreadPro(newVec);
    }
    return node;
}
/*表索引*/
TreeNode* ConstructBinaryTree::Construct_GreadProB(vector<int>&nums,int left,int right){
    if(left>=right)return nullptr;
    int MaxValueIndex=left;
    for(int i=left;i<right;i++){
        if(nums[i]>nums[MaxValueIndex])MaxValueIndex=i;
    }
    TreeNode*node=new TreeNode(nums[MaxValueIndex]);
    node->left=Construct_GreadProB(nums,left,MaxValueIndex);
    node->right=Construct_GreadProB(nums,MaxValueIndex+1,right);
    return node;

}
/*通过中序遍历和后序遍历得到先序遍历
确定递归函数参数及返回值，传入中序后序数组，以及先序数组，返回空
void Construct_Creatpro(vector<int>&ionder,vector<int>&postorder,int vector<int>&proder)
确定递归终止条件：当后序数组大小为0时返回
if(posteorder.size()==NULL)return nums;
确定单层递归逻辑：使用后序数组分割中序数组，将分割出来的值放入先序数组中
再分割后序数组，将分割的中序与后序数组进行递归将返回值给left数组，与right数组，最后合并两个数组
int proValue=postorder[postorder.size()-1];
proder.push_back(proValue);
int delimiterIndex;
for(delimiterIndex=0;delimiterIndex<ionder.size();delimiterIndex++){
    if(ionder[delimiterIndex]==proValue)break;
}
vector<int>leftionder(ionder.begin(),ionder.begin()+delimiterIndex);
vector<int>rightionder(ioner.begin()+delimiterIndex+1,ionder.end());
postorder.resize(posterorder.size()-1);
vector<int>leftposterder(posterder.begin(),postorder.begin()+leftionder.size());
vector<int>rightpostorder(posterder.begin()+rightionder.size(),postorder.end());

Construct_Creatpro(leftionder,leftpostorder);
Cinstruct_Creatpro(rightionder,rightpostorder);
*/
void ConstructBinaryTree::Construct_Creatpro(vector<int>&ionder,vector<int>&postorder,vector<int>&proder){
    if(postorder.size()==0)return;
    int proValue=postorder[postorder.size()-1];
    proder.push_back(proValue);
    
    int delimiterIndex;
    for(delimiterIndex=0;delimiterIndex<ionder.size();delimiterIndex++){
        if(ionder[delimiterIndex]==proValue)break;
    }
    vector<int>leftionder(ionder.begin(),ionder.begin()+delimiterIndex);
    vector<int>rightionder(ionder.begin()+delimiterIndex+1,ionder.end());
    postorder.resize(postorder.size()-1);
    vector<int>leftpostorder(postorder.begin(),postorder.begin()+leftionder.size());
    vector<int>rightpostorder(postorder.begin()+rightionder.size(),postorder.end());
    cout<<"---------->";
    for(int i=0;i<proder.size();i++){
        cout<<proder[i]<<" ";
    }
    cout<<endl;
    Construct_Creatpro(leftionder,leftpostorder,proder);
    Construct_Creatpro(rightionder,rightpostorder,proder);
}
/*使用表索引*/
void ConstructBinaryTree::Construct_CreatproB(vector<int>&ionder,int ionderBegin,int ionderEnd,vector<int>&postorder,int postorderBegin,int postorderEnd, vector<int>&proder){
    if(postorderBegin==postorderEnd)return ;
    int proValue=postorder[postorderEnd-1];
    proder.push_back(proValue);
    if(postorderEnd-postorderBegin==1)return ;
    int delimiterIndex;
    for(delimiterIndex=postorderBegin;delimiterIndex<ionderEnd;delimiterIndex++){
        if(ionder[delimiterIndex]==proValue)break;
    }
    //中序数组
    int leftionderBegin=ionderBegin;
    int leftionderEnd=ionderBegin+delimiterIndex;
    int rightionderbegin=ionderBegin+delimiterIndex+1;
    int rightionderEnd=ionderEnd;
    //后序数组
    int leftpostorderBegin=postorderBegin;
    int leftpostorderEnd=postorderBegin+delimiterIndex-ionderBegin;
    int rightpostorderBegin=postorderBegin+delimiterIndex-ionderBegin;
    int rightpostorderEnd=postorderEnd-1;

    cout<<"------>";
    for(int i=0;i<proder.size();i++){
        cout<<proder[i]<<" ";
    }
    cout<<endl;
    Construct_CreatproB(ionder,leftionderBegin,leftionderEnd,postorder,leftpostorderBegin,leftpostorderEnd,proder);
    Construct_CreatproB(ionder,rightionderbegin,rightionderEnd,postorder,rightpostorderBegin,rightpostorderEnd,proder);
}
