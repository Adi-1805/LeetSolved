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
    // ***********WE WILL DO A ROOT->RIGHT->LEFT traversal**********
    // void traversal(TreeNode* root, int& lvl, vector<int>& res){
    //     if(root == NULL) return ;
    //     if(res.size() == lvl) res.push_back(root->val);
    //     traversal(root->right, lvl+1, res);
    //     traversal(root->left, lvl+1, res);
    // }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        
        queue <pair<TreeNode*, int>> q; q.push({root, 0});
        int lvl = 0;
        vector<int> result;

        result.push_back(root->val);
       
        while(!q.empty()){
            auto [curNode, lvl] = q.front();
            q.pop();

            if(result.size() == lvl){
                result.push_back(curNode->val);
            }
            else{
                result[lvl] = curNode->val;
            }
            
            if(curNode -> left != NULL){
                q.push({curNode->left, lvl+1});
            }
            if(curNode -> right != NULL){
                q.push({curNode->right, lvl+1});
            }   
        }
        return result;
    }
};