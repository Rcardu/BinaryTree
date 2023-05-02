/*
深度优先遍历，迭代法
*/
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiTreeNode.cpp"
#endif
#include<stack>
#include<algorithm>

using namespace std;

class IterateTraversalOfBinaryTrees{
public:
//先序遍历（迭代法）
/*
前序遍历是中左右，每次先处理的是中间节点，那么先将跟节点放⼊栈中，然后将右孩⼦加
⼊栈，再加⼊左孩⼦。
为什么要先加⼊ 右孩⼦，再加⼊左孩⼦呢？ 因为这样出栈的时候才是中左右的顺序。

*/
    vector<int>IterateTraversalOfBinaryTrees_pro(BiTreeNode<int>*node){
        stack<BiTreeNode<int>*>st;
        vector<int> result;
        if(node==NULL)return result;
        st.push(node);
        while(!st.empty()){
            BiTreeNode<int>*node=st.top();
            st.pop();
            result.push_back(node->val);
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
        }
        return result;

    }
/*
中序遍历，（迭代版）
先使用辅助指针入栈，直到最后一个左叶子结点入栈，再出栈访问
*/
    vector<int>IterateTraversalOfBinaryTrees_ins(BiTreeNode<int>*node){
        stack<BiTreeNode<int>*>st;
        vector<int>result;
        BiTreeNode<int>* cur=node;//使用指针来辅助访问
        while(cur!=NULL||!st.empty()){//判断是否为空
            if(cur!=NULL){//当不是最后一个结点时
                st.push(cur);//入栈
                cur=cur->left;//先去左边
            }else{
                cur=st.top();//弹出
                st.pop();
                result.push_back(cur->val);
                cur=cur->right;//去当前结点的右结点
            }
        }
        return result;
    }
    
/*
后序遍历，（递归版）
先序遍历为中左右------>（调整代码顺序序）-------->中右左------->(反转数组)------>左右中
*/
    vector<int> IterateTraversalOfBinaryTrees_post(BiTreeNode<int>*node){
        stack<BiTreeNode<int>*>st;
        vector<int>result;
        if(node==NULL)return result;
        st.push(node);
        while(!st.empty()){
            BiTreeNode<int>*ptr=st.top();
            st.pop();
            result.push_back(ptr->val);
            if(ptr->left)st.push(ptr->left);//先入左，才能后出左
            if(ptr->right)st.push(ptr->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};


//输入输出
void IterateTrabersalFormat(){
    BiTree<int>*bitree=new BiTree<int>();
    int N;
    cin>>N;
    vector<int>trees(N);
    for(int i=0;i<N;i++)cin>>trees[i];
    
    bitree->insert_All(bitree->root,trees,0,N);
    IterateTraversalOfBinaryTrees obj;
    //vector<int>result=obj.IterateTraversalOfBinaryTrees_pro(bitree->root);
    //vector<int>result=obj.IterateTraversalOfBinaryTrees_ins(bitree->root);
    vector<int>result=obj.IterateTraversalOfBinaryTrees_post(bitree->root);
    for(int i=0;i<result.size();i++)cout<<" "<<result[i];
}