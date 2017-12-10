/*************************************************************************
    > File Name: basic_tree.cpp
    > Author: jingchunzhen
    > Mail: jcz@bupt.edu.cn 
    > Created Time: 2017年12月09日 星期六 22时28分12秒
 ************************************************************************/
#pragma GCC diagnostic error "-std=c++11"
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:        
    

    TreeNode* build_BST(vector<int>& nums)
    {
        TreeNode* pRoot = new TreeNode(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            add_node(pRoot, nums[i]);
        }   
        return pRoot;
    }

    void add_node(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL)
        {
            pRoot = new TreeNode(k);
        }
        else
        {
            TreeNode* pCurrentNode = pRoot;         
            while(true)        
            {            
                if (pCurrentNode->val < k)
                {
                    if(pCurrentNode->right == NULL)
                    {
                        TreeNode* pNewNode = new TreeNode(k);
                        pCurrentNode->right = pNewNode;
                        break;
                    }
                    else
                        pCurrentNode = pCurrentNode->right;
                }
                else if(pCurrentNode->val > k)
                {
                    if(pCurrentNode->left == NULL)
                    {
                        TreeNode* pNewNode = new TreeNode(k);
                        pCurrentNode->left = pNewNode;
                        break;
                    }
                    else
                        pCurrentNode = pCurrentNode->left;
                }
                else if (pCurrentNode->val == k)
                {
                    // do nothing 
                    break;
                }                            
            }//end of while    
        }            
    }// end of add_node

    void inorder_trace(TreeNode* pCurrentNode)
    {
        //trace the tree 
        if (pCurrentNode != NULL)
        {
            cout << pCurrentNode->val << endl;
            inorder_trace(pCurrentNode->left);
            inorder_trace(pCurrentNode->right);
        }
        
    }// end of trace 

    void preorder_trace(TreeNode* pCurrentNode)
    {
        //preorder trace 
        if (pCurrentNode != NULL)
        {
            preorder_trace(pCurrentNode->left);
            cout << pCurrentNode->val << endl;
            preorder_trace(pCurrentNode->right);
        }

    }// end of trace 

    void postorder_trace(TreeNode* pCurrentNode)
    {
        // post order trace 
        if (pCurrentNode != NULL)
        {
            postorder_trace(pCurrentNode->left);
            postorder_trace(pCurrentNode->right);
            cout << pCurrentNode->val << endl;
        }
    } // end of trace 


    void BFS(TreeNode* pRoot)
    {
        queue<TreeNode*>q;
        q.push(pRoot);
        while(!q.empty())
        {
            TreeNode* pCurrentNode = q.front();
            //q.front()
            cout << pCurrentNode->val << endl;
            if (pCurrentNode->left != NULL)
                q.push(pCurrentNode->left);
            if (pCurrentNode->right != NULL)
                q.push(pCurrentNode->right);     
            q.pop();                   
        }//end of while                
    }// end of BFS 

    
    //TreeNode* sortedArrayToBST(vector<int>& nums) 
    //{}
    void TreeIndex(vector<int>& nums, int start, int end)
    {
        // change something in case there is sth wrong 
        if(start <= end)
        {
            int mid = (start + end) / 2;        
            cout << mid << endl;
            TreeIndex(nums, start, mid - 1);
            TreeIndex(nums, mid + 1, end);
        }                
    }

    //带有返回值的递归函数 
    //反映了对vector的end掌握不清楚
    //本题说明了对STL中的vector的掌握还不是特别的清楚，尤其是对于其边界情况的掌握
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {       
        if (nums.size() == 0)
        {
            return NULL;
        }
        int mid = (0 + nums.size() - 1) / 2;       
        TreeNode* pRoot = new TreeNode(nums[mid]);
        if(nums.size() > 1)
        {
            vector<int> left_array = {nums.begin(), nums.begin() + mid}; 
            // 这是有可能是一个数字的
            // 如果vector的end和begin是一样的，此时说明vector是空的            
            pRoot->left = sortedArrayToBST(left_array);
            vector<int> right_array = {nums.begin() + mid + 1, nums.end()};            
            pRoot->right = sortedArrayToBST(right_array);
        }
        
        return pRoot;
    }    
};

int main()
{    
    Solution* s = new Solution();    
    return 0;
}