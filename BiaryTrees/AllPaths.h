#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include"BiTreeNode.h"
#include"BiaryTrees.h"
#endif
class AllPaths
{
private:
    /* data */
    /*二叉树的所有路径,先序遍历*/
    void AllPaths_Arec(TreeNode*node,vector<int>&path,vector<string>&result);
    /*以上函数的精简版*/
    void AllPaths_Brec(TreeNode*node,string path,vector<string>&result);
public:
    /*二叉树的所有路径，辅助函数*/
    vector<string>Arec_feel(TreeNode*node);
    /*二叉树的所有路径，栈，先序遍历*/
    vector<string>AllPaths_Astc(TreeNode*node);
    
};
/*二叉树的所有路径
给定⼀个⼆叉树，返回所有从根节点到叶⼦节点的路径。
需要用先序遍历，这样才能方便让父节点指向孩子节点，找到对应路径
需要使用回溯来回退一个个路径再进入另一个路径
1.确定递归函数参数及返回值：传入根节点，记录每一条路径的path，存放结果集result，不需要返回值
void AllPaths_Arec(TreeNode*node,vector<int>&path,vector<string>&result);
2.确定递归终止条件，因为要到叶子节点才停止，所以
if(node->left==NULL&&node->right==NULL){
    string sPath;
    for(int i=0;i<path.size()-1;i++){
        sPath+=to_string(path[i]);
        sPath+="->";
    }
    sPath+=to_string(path[path.size()-1]);//记录最后一个节点，叶子节点
    retult.push_back(sPath);//收集一个路径
    return ;
}
3.确定单层递归逻辑：因为时先序遍历，需要先处理中间节点，中间节点就是我们要记录路径上的节点，先放进path中
    path.push_back(node->val);
    因为没有判断node是否为空，所以要在进入下一层递归时进行判断，也就是要进去下一层递归的节点是否为空
    if(node->left){
        AllPaths_Arec(node->left,path,result);
    }
    if(node->right){
        AllPaths_Arec(node->left,path,result);
    }
    此时开始做回溯，因为path不能一直添加元素,每有一个递归就回溯一次
    if(node->left){
        AllPaths_Arec(node->left,path,result);
        path.pop_back();
    }
    if(node->right){
        AllPaths_Arec(node->left,path,result);
        path.pop_back();
    }
*/
void AllPaths::AllPaths_Arec(TreeNode*node,vector<int>&path,vector<string>&result){
    path.push_back(node->val);
    if(node->left==NULL&&node->right==NULL){//说明找的了叶子节点，开始对叶子节点进行处理
        string sPath;
        for(int i=0;i<path.size()-1;i++){
            sPath+=to_string(path[i]);
            sPath+="->";
        }
        sPath+=to_string(path[path.size()-1]);
        result.push_back(sPath);
        return ;
    }
    if(node->left){
        AllPaths_Arec(node->left,path,result);
        path.pop_back();
    }
    if(node->right){
        AllPaths_Arec(node->right,path,result);
        path.pop_back();
    }
}
/*因为找到叶子节点才是路径，所以可以在递归的过程中就回溯*/
void AllPaths::AllPaths_Brec(TreeNode*node,string path,vector<string>&result){
    path+=to_string(node->val);
    if(node->left==NULL&&node->right==NULL){
        result.push_back(path);
    }
    if(node->left)AllPaths_Brec(node->left,path+"->",result);
    if(node->right)AllPaths_Brec(node->right,path+"->",result);
}
/*二叉树的所有路径，辅助函数*/
vector<string>AllPaths::Arec_feel(TreeNode*node){
    //vector<int>path;
    string path;
    vector<string>result;
    //AllPaths_Arec(node,path,result);
    AllPaths_Brec(node,path,result);
    return result;
}
/*使用栈来在遍历的过程中记录并提取路径*/
vector<string>AllPaths::AllPaths_Astc(TreeNode*node){
    stack<TreeNode*>st;
    stack<string>stPath;
    vector<string>result;
    if(node==NULL)return result;
    st.push(node);
    stPath.push(to_string(node->val));
    while(!st.empty()){
        TreeNode*ptr=st.top();st.pop();
        string str=stPath.top();stPath.pop();
        if(ptr->left==NULL&&ptr->right==NULL){
            result.push_back(str);
        }
        if(ptr->right){
            st.push(ptr->right);
            stPath.push(str+"->"+to_string(ptr->right->val));
        }
        if(ptr->left){
            st.push(ptr->left);
            stPath.push(str+"->"+to_string(ptr->left->val));
        }
    }
    return result;
}

