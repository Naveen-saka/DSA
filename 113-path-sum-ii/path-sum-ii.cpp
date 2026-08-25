/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>ans;
    void go(auto r,int t,int sum,auto &cur)
    {
        if(!r) return;
        // if(sum > t) return;
        if(r->right == nullptr && r->left == nullptr)
        {
            if(sum + r->val == t)
            {
                cur.push_back(r->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        cur.push_back(r->val);
        go(r->left,t,sum+r->val,cur);
        go(r->right,t,sum+r->val,cur);
        cur.pop_back();
        // if(r->right!=nullptr) 
        // {
        //     int p = r->right->val;
        //     cur.push_back(p);
        //     go(r,t,sum+p,cur);
        //     cur.pop_back();
        // }
        // if(r->left!=nullptr) 
        // {
        //     int p = r->left->val;
        //     cur.push_back(p);
        //     go(r,t,sum+p,cur);
        //     cur.pop_back();
        // }
    }
    vector<vector<int>> pathSum(TreeNode* r, int t) {
        if(!r) return ans;
        vector<int>cur;
        // cur.push_back(r->val);
        go(r,t,0,cur);
        // go(r->right,t,r->val,cur);
        return ans;
    }
};