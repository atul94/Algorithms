/**
@Description Given a binary tree, return the preorder traversal of its nodes’ values.
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector <int> sol;
    if(A == NULL){
        return sol;
    }
    vector <TreeNode *> st;
    while(A || !st.empty()){
        if(A){
            sol.push_back(A->val);
            st.push_back(A);
            A = A->left;
        }else{
            TreeNode * temp;
            temp = st.back();
            A = temp->right;
            st.pop_back();
        }
    }
    return sol;
}
