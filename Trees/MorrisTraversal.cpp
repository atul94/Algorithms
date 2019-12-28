/**
Inorder traversal without stacks and recurssion.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void Solution::traverseTree(TreeNode* A) {
    TreeNode * curr, * prev;
    curr = A;
    while(curr) {
        if(!curr->left) {
            cout << curr->val << endl;
            curr = curr->right;
        }else {
            prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if(prev->right == curr) {
                cout << curr->val << endl;
                curr = curr->right;
                prev->right = NULL;
            }else {
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
}
