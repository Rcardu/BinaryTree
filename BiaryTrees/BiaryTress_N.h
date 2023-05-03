#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#endif
using namespace std;
#include <iostream>
#include <vector>
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