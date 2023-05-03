#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#endif
using namespace std;
typedef int T;
typedef struct MNode {
    T element;
    vector<MNode*> children;
    MNode *Parent;
} MNode;
 
class MTree {
private:
    MNode *root;
public:
    void init(MNode *root);
    void putChild(MNode* node,MNode* parent);
    void putChildren(vector<MNode*> nodes, MNode *parent);
    void tranversal(MNode *root);
    void tranversal();
    int getMaxDepth(MNode *root,vector<MNode*> nodes);
    /*N叉树层序遍历*/
    vector<vector<int>>SequentialTraversalOfMultiProngedTrees(MNode*node);
    /*多叉树最大深度*/
    int maxDepth(MNode* root);
    /*层序遍历求深度，迭代队列*/
    int maxDepthTrevers(MNode* root);
};
void MTree::init(MNode *root) { this->root = root; }
 
void MTree::putChild(MNode *node, MNode *parent) {
    parent->children.push_back(node);
    node->Parent = parent;
}
 
void MTree::putChildren(vector<MNode *> nodes, MNode *parent) {
    for (int i = 0; i < nodes.size(); ++i) {
        putChild(nodes[i], parent);
    }
}
 
void MTree::tranversal() {
    this->tranversal(this->root);
}
 
void MTree::tranversal(MNode *root) {
    vector<MNode *> nodes = root->children;
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i]->children.size() > 0)
            tranversal(nodes[i]);
        else
            cout << nodes[i]->element << ",";
    }
    cout << root->element << ",";
}
 
int MTree::getMaxDepth(MNode *root,vector<MNode*> nodes) {
    auto iResult = 0;
 
    return iResult;
}
int MTree::maxDepth(MNode* root) {
    if (root == 0) return 0;
    int depth = 0;
    for (int i = 0; i < root->children.size(); i++) {
    depth = max (depth, maxDepth(root->children[i]));
    }
    return depth + 1;
}
//层序遍历
vector<vector<int>>MTree::SequentialTraversalOfMultiProngedTrees(MNode*node){
    queue<MNode*>que;
    if(node!=NULL)que.push(node);
    vector<vector<int>>result;
    while(!que.empty()){
        int size=que.size();
        vector<int>vec;
        for(int i=0;i<size;i++){
            MNode*ptr=que.front();
            que.pop();
            vec.push_back(ptr->element);
            for(int j=0;j<ptr->children.size();j++){
                if(ptr->children[j]!=NULL)que.push(ptr->children[j]);
            }
        }
        result.push_back(vec);
    }
return result;
}
//层序遍历，求深度
int MTree::maxDepthTrevers(MNode* node){
    queue<MNode*>que;
    int len=0;
    if(node!=NULL)que.push(node);
    while(!que.empty()){
        int size=que.size();
        len++;
        for(int i=0;i<size;i++){
            MNode*ptr=que.front();
            que.pop();
            for(int j=0;j<ptr->children.size();j++){
                if(ptr->children[j])que.push(ptr->children[j]);
            }
        }
    }
    return len;
}
