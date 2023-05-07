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
#include<algorithm>
#include<unordered_map>
/*二叉搜索树中的众数*/
using namespace std;
class MapSearchTree
{
private:
    /* data */
    /*遍历整棵树，使用map记录频率*/
    void searchBTS(TreeNode*node,unordered_map<int,int>&map){
        if(node==NULL)return ;
        map[node->val]++;
        searchBTS(node->left,map);
        searchBTS(node->right,map);
        return ;
    }
    //排序规则
    bool static cmp(const pair<int,int>&a,const pair<int ,int>&b){
        return a.second>b.second;
    }
public:
    /*搜索二叉树中的众数*/
    vector<int>findMode(TreeNode*node){
        unordered_map<int,int>map;//key:元素，value：出现的频率
        vector<int>result;
        if(node==NULL)return result;
        searchBTS(node,map);
        vector<pair<int,int>>vec(map.begin(),map.end());
        sort(vec.begin(),vec.end(),cmp);//排序
        result.push_back(vec[0].first);
        for(int i=1;i<vec.size();i++){
            //取最高的放到result中
            if(vec[i].second==vec[0].second)result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};


