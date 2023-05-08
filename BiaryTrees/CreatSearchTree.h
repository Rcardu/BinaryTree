#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiTreeNode.h"
#include<queue>
#include<stack>
#include"BiaryTrees.h"
#endif

using namespace std;
class CreatSearchTree
{
private:
    /* data */
public:
    /*将有序数组转为二叉树*/
    TreeNode*CreatSearchTree_Rec(vector<int>&nums,int left,int right);
    /*将有序数组转为二叉树*/
    TreeNode*CreatSearchTree_Iter(vector<int>&nums);
    /*将二叉树转化为累加树*/
    int pre=0;
    void AccumulationTree_Rec(TreeNode*cur);
    /*迭代版*/
    void AccumulationTree_Iter(TreeNode* root);

};
/*将有序数组转为二叉树,就是寻找数组中间的值，以这个值为分割点开始，
如果数组中数的数量为偶数，那么取中间两个数，左边的数还是右边的数都可以，只不过构造了两颗不同的平衡二叉搜索树
1.确定递归函数及返回值：使用返回值来构造中间节点的左右孩子，
首先是传入数组，然后再传入左下表索引left，与右下表索引right
[left,right]，左闭右闭区间，循环不变量
TreeNode*CreatSearchTree_Rec(vector<int>&nums,int left,int right);
2.确定递归终止条件：因为是左闭右闭区间，所以当left>right时就是空节点了
if(left>right)return NULL;
3.确定单层递归逻辑：
首先取数组中间位置的元素，int mid=(left+right)/2,注意数组越界，如果left与right都是最大int那么会发生越界
int mid=(left+((right-left)/2)，取了中间位置左边的;
使用中间位置的元素来构造节点TreeNode*node=new TreeNode(mid);
接着划分区间，左孩子去左边，右孩子去右边
node->left=CreatSearchTree_Rec(nums,left,mid-1);
node->right=CreatSearchTree_Rec(nums,mid+1,right);
return node;*/
TreeNode*CreatSearchTree::CreatSearchTree_Rec(vector<int>&nums,int left,int right){
    if(left>right)return nullptr;
    int mid=left+((right-left)/2);
    TreeNode*node=new TreeNode(nums[mid]);

    node->left=CreatSearchTree_Rec(nums,left,mid-1);
    node->right=CreatSearchTree_Rec(nums,mid+1,right);
    return node;
}
/*将有序数组转为二叉树*/
TreeNode*CreatSearchTree::CreatSearchTree_Iter(vector<int>&nums){
    if(nums.size()==0)return nullptr;

    TreeNode*root=new TreeNode(0);//初始根节点
    queue<TreeNode*>nodeQue;//放遍历的节点
    queue<int>leftQue;//保存左区间下标
    queue<int>rightQue;//保存右区间下标
    nodeQue.push(root);//根节点入列
    leftQue.push(0);//0为左区间下标
    rightQue.push(nums.size()-1);//nums.size()-1为右区间下标

    while(!nodeQue.empty()){
        TreeNode*curNode=nodeQue.front();
        nodeQue.pop();
        int left=leftQue.front();leftQue.pop();
        int right=rightQue.front();rightQue.pop();
        int mid=left+((right-left)/2);

        curNode->val=nums[mid];//将mid给对应的中间节点
        if(left<=mid-1){
            curNode->left=new TreeNode(0);
            nodeQue.push(curNode->left);
            leftQue.push(left);
            rightQue.push(mid-1);
        }
        if(right>=mid+1){
            curNode->right=new TreeNode(0);
            nodeQue.push(curNode->right);
            leftQue.push(mid+1);
            rightQue.push(right);
        }
    }
    return root;
}
/*将二叉树转化为累加树
使用pre记录cur的前一个结点，累加顺序为右中左
1.递归函数参数及返回值：
int pre;//记录前一个结点的值
void TreeNode*AccumulationTree_Rec(TreeNode*cur);
2.确定递归终止条件：遇空终止
if(cur==NULL)return;
3.确定单层递归逻辑：中间结点的处理逻辑就是让cur加上上一个结点的数值
AccumulationTree_Rec(cur->right);
cur->val+=pre;
pre=cur->val;
AccumulationTree_Rec(cur->left);*/
void CreatSearchTree::AccumulationTree_Rec(TreeNode*cur){
    if(cur==NULL)return ;
    AccumulationTree_Rec(cur->right);
    cur->val+=pre;
    pre=cur->val;
    AccumulationTree_Rec(cur->left);
}
void CreatSearchTree::AccumulationTree_Iter(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) {
        st.push(cur);
        cur = cur->right; // 右
        } else {
        cur = st.top(); // 中
        st.pop();
        cur->val += pre;
        pre = cur->val;
        cur = cur->left; // 左
        }
    }
 }