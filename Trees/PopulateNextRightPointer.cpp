/**
Given a binary tree
struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
You may only use constant extra space.
Example :
Given the following binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
    
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
    
Note 1: that using recursion has memory overhead and does not qualify for constant space.
Note 2: The tree need not be a perfect binary tree.

*/

void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode * head, * parent, * prev;
    parent = A;
    prev = NULL;
    head = NULL;
    while(parent) {
        while(parent) {
            if(parent->left) {
                if(prev) {
                    prev->next = parent->left;
                }else {
                    head = parent->left;
                }
                prev = parent->left;
            }
            if(parent->right) {
                if(prev) {
                    prev->next = parent->right;
                }else{
                    head = parent->right;
                }
                 prev = parent->right;
            }
            parent = parent->next;
        }
        parent = head;
        head = NULL;
        prev = NULL;
    }
}
