/**
@Description Given an inorder traversal of a cartesian tree, construct the tree.
Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree
Note: You may assume that duplicates do not exist in the tree.
Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/
int findLargestElementIndex(vector<int> &A, int start, int end){
    int maxEle = start;
    for(int i = start; i <= end; i++){
        if(A[i] > A[maxEle]){
            maxEle = i;
        }
    }
    return maxEle;
}
TreeNode * constructTree(int start, int end, vector<int> &A){
    if(start > end){
        return NULL;
    }
    int index = findLargestElementIndex(A,start,end);
    TreeNode* head = new TreeNode(A[index]);
    head->left = constructTree(start, index-1, A);
    head->right = constructTree(index+1, end, A);
    return head;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    
    return constructTree(0, A.size()-1, A);
    
}
