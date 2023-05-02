/*层序遍历⼀个⼆叉树。就是从左到右⼀层⼀层的去遍历⼆叉树。这种遍历的⽅式和我们之前讲过的都不太⼀样。
需要借⽤⼀个辅助数据结构即队列来实现，队列先进先出，符合⼀层⼀层遍历的逻辑，⽽是
⽤栈先进后出适合模拟深度优先遍历也就是递归的逻辑。
⽽这种层序遍历⽅式就是图论中的⼴度优先遍历，只不过我们应⽤在⼆叉树上。*/
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include"BiTreeNode.h"
#include"BiaryTrees.h"
#include<vector>
#endif
#include<stack>
#include<queue>
#include<algorithm>
#include<iomanip>

using namespace std;

class LayerOrderTraversal{
public:
//层序遍历
vector<vector<int>>LayerOrderTraversal_acl(BiTreeNode<int>*node);

/*给定⼀个⼆叉树，返回其节点值⾃底向上的层次遍历。 （即按从叶⼦节点所在层到根节点
所在的层，逐层从左向右遍历）把外层数组反转即可*/
vector<vector<int>>LayerOrderTraversal_acl2(BiTreeNode<int>*node);

/*给定⼀棵⼆叉树，想象⾃⼰站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到
的节点值。若为这一层的最后一个值，就放入数组*/
vector<int>LayerOrderTraversal_acl3(BiTreeNode<int>*node);

/*给定⼀个⾮空⼆叉树, 返回⼀个由每层节点平均值组成的数组。对每一层求平均值*/
vector<double>LayerOrderTraversal_avg(BiTreeNode<int>*node);

/*N叉树 :
vector<vector<int>>SequentialTraversalOfMultiProngedTrees(BiTreeNode<int>*node);*/

/*在每个树⾏中找最⼤值需要在⼆叉树的每⼀⾏中找到最⼤的值*/
vector<int>LayerOrderTraversal_max(BiTreeNode<int>*node);

};
vector<vector<int>> LayerOrderTraversal::LayerOrderTraversal_acl(BiTreeNode<int>*node){
        queue<BiTreeNode<int>*>que;
        if(node!=NULL)que.push(node);
        vector<vector<int>>result;
        while(!que.empty()){
            int size=que.size();
            vector<int>vec;
            //使用size，que.size()是不断变化的
            for(int i=0;i<size;i++){
                BiTreeNode<int>* ptr=que.front();
                que.pop();
                vec.push_back(ptr->val);
                if(ptr->left)que.push(ptr->left);
                if(ptr->right)que.push(ptr->right);
            }
            result.push_back(vec);
        }
        return result;
    }
vector<vector<int>>LayerOrderTraversal::LayerOrderTraversal_acl2(BiTreeNode<int>*node){
        queue<BiTreeNode<int>*>que;
        if(node!=NULL)que.push(node);
        vector<vector<int>>result;
        while(!que.empty()){
            int size=que.size();
            vector<int>vec;
            //使用size，que.size()是不断变化的
            for(int i=0;i<size;i++){
                BiTreeNode<int>* ptr=que.front();
                que.pop();
                vec.push_back(ptr->val);
                if(ptr->left)que.push(ptr->left);
                if(ptr->right)que.push(ptr->right);
            }
            result.push_back(vec);
        }
        reverse(result.begin(),result.end());//反转外层数组
        return result;
    }
vector<int>LayerOrderTraversal::LayerOrderTraversal_acl3(BiTreeNode<int>*node){
        queue<BiTreeNode<int>*>que;
        if(node!=NULL)que.push(node);
        vector<int>vec;
        while(!que.empty()){
            int size=que.size();
            //使用size，que.size()是不断变化的
            for(int i=0;i<size;i++){
                BiTreeNode<int>* ptr=que.front();
                que.pop();
                if(i==(size-1))vec.push_back(ptr->val);
                if(ptr->left)que.push(ptr->left);
                if(ptr->right)que.push(ptr->right);
            }
        }
        return vec;
    }
vector<double>LayerOrderTraversal::LayerOrderTraversal_avg(BiTreeNode<int>*node){
        queue<BiTreeNode<int>*>que;
        if(node!=NULL)que.push(node);
        vector<double>result;
        while(!que.empty()){
            int size=que.size();
            double sum=0;
            for(int i=0;i<size;i++){
                BiTreeNode<int>*ptr=que.front();
                que.pop();
                sum+=ptr->val;
                if(ptr->left)que.push(ptr->left);
                if(ptr->right)que.push(ptr->right);
            }
            result.push_back(sum/size);
        }
        return result;
    }
/*
vector<vector<int>>SequentialTraversalOfMultiProngedTrees(BiTreeNode<int>*node){
    queue<BiTreeNode<int>*>que;
    if(node!=NULL)que.push(node);
    vector<vector<int>>result;
    while(!que.empty()){
        int size=que.size();
        vector<int>vec;
        for(int i=0;i<size;i++){
            BiTreeNode<int>*ptr=que.front();
            que.pop();
            vec.push_back(ptr->val);
            for(int i=0;i<node->children.size();i++){
                if(ptr->children[i]!=NULL)que.push(ptr->children[i]);
            }
        }
        result.push_back(vec);
    }
return result;
}
*/
vector<int>LayerOrderTraversal::LayerOrderTraversal_max(BiTreeNode<int>*node){
    queue<BiTreeNode<int>*>que;
    vector<int>result;
    if(node!=NULL)que.push(node);
    while(!que.empty()){
        int size=que.size();
        int MaxValue=INT_MIN;
        for(int i=0;i<size;i++){    
            BiTreeNode<int>*ptr=que.front();
            que.pop();
            MaxValue=ptr->val>MaxValue?ptr->val:MaxValue;
            if(ptr->left)que.push(ptr->left);
            if(ptr->right)que.push(ptr->right);
        }
        result.push_back(MaxValue);
    }
    return result;
}