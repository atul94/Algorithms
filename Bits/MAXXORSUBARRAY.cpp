/**
Problem Link: https://www.interviewbit.com/problems/subarrays-xor-less-than-b/
Given an array of integers A.Find and return the number of subarrays whose xor values is less than B.

Since the number of subarrays can be very large you are required to
return the number of subarrays whose xor values is less than B modulo (109+7).

*/

struct Node {
public:
    long long lc,rc;
    Node * left;
    Node * right;
    Node(){
        this->rc = this->lc = 0;
        this->left = this->right = NULL;
    }
};
long long mod = 1000000007;
Node * insert(Node * head, int val){
    Node * node;
    node = head;
    for(int i = 30; i >= 0; i--){
        if(val & (1 << i)){
            node->rc++;
            if(!node->right){
                node->right = new Node();
            }
            node = node->right;
        }else{
            node->lc++;
            if(!node->left){
                node->left = new Node();
            }
            node = node->left;
        }
    }
    return head;
}

long long query(Node * head, int sum, int target){
    Node * node;
    node = head;
    long long ans = 0;
    for(int i = 30; i >= 0; i--) {
        bool a = sum & (1 << i);
        bool b = target & (1 << i);
        if(b){
            if(a){
                ans += node->rc;
                ans %= mod;
                if(node->left){
                    node = node->left;
                }else{
                    return ans;
                }
            }else{
                ans += node->lc;
                ans %= mod;
                if(node->right){
                    node = node->right;
                }else{
                    return ans;
                }
            }
        }else{
            if(a){
                if(node->right){
                    node = node->right;
                }else{
                    return ans;
                }
            }else{
                if(node->left){
                    node = node->left;
                }else{
                    return ans;
                }
            }
        }
    }
    return ans;    
}
int Solution::solve(vector<int> &A, int B) {
    Node * head;
    head = new Node();
    head = insert(head, 0);
    long long ans = 0;
    int pre = 0;
    for(int i = 0; i < A.size(); i++){
        pre = pre ^ A[i];
        ans += query(head, pre, B);
        ans %= mod;
        head = insert(head, pre);
    }
    return (int)ans%mod;
}
