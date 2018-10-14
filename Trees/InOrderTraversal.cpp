/**
@Description Given a binary tree, return the inorder traversal of its nodes’ values.
* Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector <int> sol;
    if(A == NULL)
        return sol;
    vector<TreeNode *> st;
    st.push_back(A);
    A = A->left;
    while(A != NULL || st.size() > 0){
        if(A != NULL){
            cout << "A->val = " << A->val << " A->left = " << A->left->val << " A->right = " << A->right->val << endl;
        }
        if(A != NULL){
            st.push_back(A);
            A = A->left;
        }
        if(st.size() > 0){
            TreeNode * temp;
            temp = st.back();
            st.pop_back();
            sol.push_back(temp->val);
            A = temp->right;
        }
    }
    return sol;
}
