/**
@Description Given a binary tree, print a vertical order traversal of it.
* Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int, vector<int>> mp;
    queue <pair<int,TreeNode *>> st;
    vector <vector <int> > sol;
    int horHeight = 0;
    if(A == NULL){
        return sol;
    }
    st.push(make_pair(0,A));
    while(!st.empty()){
            A = st.front().second;
            horHeight = st.front().first;
            mp[horHeight].push_back(A->val);
            st.pop();
            if(A->left){
                st.push(make_pair(horHeight-1,A->left));
            }
            if(A->right){
                st.push(make_pair(horHeight+1,A->right));
            }
        }
    
    for(map<int, vector<int>>:: iterator it = mp.begin(); it != mp.end(); it++){
        sol.push_back(it->second);
    }
    return sol;
}
