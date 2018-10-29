/**
@Description There are n islands and there are many bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.
Example :
Input

         Number of islands ( n ) = 4
         1 2 1 
         2 3 4
         1 4 3
         4 3 2
         1 3 10
*/
class DSNode{
    public:
        int val;
        int rank;
        DSNode * parent;
        DSNode(int x){
            this->val = x;
            this->rank = 0;
            this->parent = this;
        }
};
class DisjointSet{
    private:
        unordered_map<int, DSNode *> mp;
        DSNode * findParent(DSNode * child){
            return child->parent;
        }
    public:
    DisjointSet(){
        mp.clear();
    }
    void makeSet(int x){
        DSNode * newNode = new DSNode(x);
        mp[x] = newNode;
        return;
    }
    void joinSet(int x, int y){
        DSNode * nodeA, * nodeB;
        nodeA = mp[x];
        nodeB = mp[y];
        while(nodeA != findParent(nodeA)){
            nodeA = findParent(nodeA);
        }
        while(nodeB != findParent(nodeB)){
            nodeB = findParent(nodeB);
        }
        if(nodeA->rank == nodeB->rank){
            nodeB->parent = nodeA;
            nodeA->rank++;
        }else if(nodeA->rank > nodeB->rank){
            nodeB->parent = nodeA;
        }else{
            nodeA->parent = nodeB;
        }
        return;
    }
    int findSet(int x){
        DSNode * node;
        node = mp[x];
        while(node != findParent(node)){
            node = findParent(node);
        }
        mp[x]->parent = node;
        return node->val;
    }
    
};
int compare(vector<int> A, vector<int> B){
    return A[2] < B[2];
}

bool isCycleFormed(DisjointSet &disjointSet, int a, int b){
    if(disjointSet.findSet(a) == disjointSet.findSet(b)){
        return true;
    }else{
        disjointSet.joinSet(a,b);
        return false;
    }    
}
int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(), compare);
    DisjointSet disJointSet;
    for(int i = 0; i < A; i++){
        disJointSet.makeSet(i+1);
    }
    int ans = 0;
    int count = 0;
    for(int i = 0; i < B.size(); i++){
        if(!isCycleFormed(disJointSet,B[i][0], B[i][1])){
            count++;
            ans += B[i][2];
            if(count == A-1){
                break;
            }
        }
    }
    return ans;
    
}
