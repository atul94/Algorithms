/**
@Description You are given the following :

    A positive number N
    Heights : A list of heights of N persons standing in a queue
    Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P

You need to return list of actual order of persons’s height
Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2

Output : 
actual order is: 5 3 2 1 6 4 
*/
class Node{

  public:
    int val;
    int start;
    int end;
    Node * left;
    Node * right;
  Node(int x, int y){
      this->start = x;
      this->end = y;
      this->val = y - x + 1;
      this->left = NULL;
      this->right = NULL;
  }
};
Node * constructTree(int start, int end){
    Node * head = new Node(start,end);
    if(start == end){
        return head;
    }else{
        int mid = start + (end-start)/2;
        head->left = constructTree(start, mid);
        head->right = constructTree(mid+1, end);
        return head;
    }
}
int findIndex(Node * head, int val){
    head->val--;
    if(head->start == head->end){
        return head->start;
    }else{
        if(head->left->val >= val){
            return findIndex(head->left, val);
        }else{
             return findIndex(head->right, val - head->left->val);
        }
    }
}
int compare(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
vector<int> Solution::order(vector<int> &A, vector<int> &B){
    vector <pair<int,int>> combinedInfo;
    for(int i = 0; i < A.size(); i++){
        combinedInfo.push_back(make_pair(A[i], B[i]));
    }
    sort(combinedInfo.begin(), combinedInfo.end(), compare);
    vector <int> sol(A.size(),-1);
    Node * head = constructTree(0, A.size()-1);
    for(int i = 0; i < combinedInfo.size(); i++){
        int j = findIndex(head, combinedInfo[i].second+1);
        sol[j] = combinedInfo[i].first;
    }
    return sol;
    
}
