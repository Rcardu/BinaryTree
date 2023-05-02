/*
将要访问的结点入栈，把要处理的结点也入栈，但是要做标记
将要处理的结点入栈后，紧接着放入一个空指针做标记
*/



//输入输出
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"BiTreeNode.cpp"
#endif
#include<stack>
#include<algorithm>

using namespace std;

class UnifiedIterativeApproach{
/*
先序遍历
*/
public:
    vector<int>UnifiedIterativeApproach_pro(BiTreeNode<int>*node){
        vector<int>result;
        stack<BiTreeNode<int>*>st;
        if(node!=NULL)st.push(node);
        while(!st.empty()){
            BiTreeNode<int>*ptr=st.top();
            if(ptr!=NULL){
                st.pop();
                if(ptr->right)st.push(ptr->right);
                if(ptr->left)st.push(ptr->left);
                st.push(ptr);
                st.push(NULL);
            }else{
                st.pop();
                ptr=st.top();
                st.pop();
                result.push_back(ptr->val);
            }
        }
        return result;
    }
/*
中序遍历
*/
    vector<int>UnifiedIterativeApproach_ins(BiTreeNode<int>*node){
        vector<int>result;
        stack<BiTreeNode<int>*>st;
        if(node!=NULL)st.push(node);
        while(!st.empty()){
            BiTreeNode<int>*ptr=st.top();
            if(ptr!=NULL){
                st.pop();//将此结点弹出，避免重复操作，再将右左中结点添加到栈中
                if(ptr->right)st.push(ptr->right);
                st.push(ptr);
                st.push(NULL);//中间结点加入过但是还没处理，加入空指针作为标记
                if(ptr->left)st.push(ptr->left);
            }else{//只有遇见空结点的时候才将下一个结点放入结果集
                st.pop();   //将空结点弹出
                ptr=st.top();//重新取出栈中元素
                st.pop();
                result.push_back(ptr->val);//加入结果集
            }
        }
        return result;
    }
//后序遍历
    vector<int>UnifiedIterativeApproach_post(BiTreeNode<int>*node){
        vector<int>result;
        stack<BiTreeNode<int>*>st;
        if(node!=NULL)st.push(node);
        while(!st.empty()){
            BiTreeNode<int>*ptr=st.top();
            if(ptr!=NULL){
                st.pop();
                st.push(ptr);
                st.push(NULL);
                if(ptr->right)st.push(ptr->right);
                if(ptr->left)st.push(ptr->left);
            }else{
                st.pop();
                ptr=st.top();
                st.pop();
                result.push_back(ptr->val);
            }
        }
        return result;
    }

};

//输入输出
void UnifiendIterativeApproach(){
    int N;
    cin>>N;
    vector<int>result(N);
    for(int i=0;i<N;i++)cin>>result[i];
    BiTree<int>*bitree=new BiTree<int>();
    bitree->insert_All(bitree->root,result,0,N);

    UnifiedIterativeApproach obj;
    //vector<int>val=obj.UnifiedIterativeApproach_pro(bitree->root);
    //vector<int>val=obj.UnifiedIterativeApproach_ins(bitree->root);
    vector<int>val=obj.UnifiedIterativeApproach_post(bitree->root);
    for(int i=0;i<val.size();i++)cout<<" "<<val[i];
}