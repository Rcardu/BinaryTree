#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiTreeNode.h"
#include"BiaryTrees.h"
#include"ConstructBinaryTree.h"
#include<queue>
#include<stack>
#endif
using namespace std;
class SearchTree
{
private:
    /* data */
    int maxCount;//统计最大频率
    int count;//统计频率
    TreeNode*pre;
    vector<int>result;
    void searchBTS(TreeNode*cur){
        if(cur==NULL)return ;
        searchBTS(cur->left);//左
                                //中
        if(pre==NULL){  //第一个节点
            count=1;
        }else if(pre->val==cur->val){//与前一个节点数值相同
            count++;
            
        }else{//遇到一个不同的节点
            count=1;
        }
        pre=cur;//更新上一个节点
        if(count==maxCount){//如果和最大值相同,放进result中
            result.push_back(cur->val);
        }
        if(count>maxCount){//如果比最大的大，就更新最大值
            maxCount=count;
            result.clear();
            result.push_back(cur->val);
        }
        searchBTS(cur->right);//右
        return;
    }
public:
    /*二叉搜索树中出现频率最高的*/
    vector<int>findMode(TreeNode*node){
        count=0;
        maxCount=0;
        TreeNode*pre=NULL;
        result.clear();

        searchBTS(node);
        return result;
    }
    /*二叉搜索树中出现频率最高的,迭代法，将中间处理逻辑放入即可*/
    vector<int>SearchTree_AIter(TreeNode*node);

};
/*二叉搜索树中出现频率最高的*/
vector<int>SearchTree::SearchTree_AIter(TreeNode*node){
    stack<TreeNode*>st;
    TreeNode*cur=node;
    TreeNode*pre=NULL;
    int count=0;
    int maxCount=0;
    while(cur!=NULL||!st.empty()){
        if(cur!=NULL){
            st.push(cur);
            cur=cur->left;//左
        }else{
            cur=st.top();//中
            st.pop();
            if(pre==NULL){//第一个节点
                count=1;
            }else if(pre->val==cur->val){//相等时
                count++;
            }else{//新节点
                count=1;
            }
            if(count==maxCount){//频率相等，也进入result
                result.push_back(cur->val);
            }
            if(count>maxCount){//频率比最大的还大，更新最大的
                maxCount=count;
                result.clear();
                result.push_back(cur->val);
            }
            pre=cur;
            cur=cur->right;
        }
    }
    return result;
}
