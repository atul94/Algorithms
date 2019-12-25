/*
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5
Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)
*/

struct CustomClass {
  public:
    int val;
    int x;
    int y;
    CustomClass(int a, int b, int c) {
        this->val = a;
        this->x = b;
        this->y = c;
    }
};
struct CompareCustomClass {
    public:
    bool operator() (CustomClass a, CustomClass b) {
        return a.val < b.val;
    }
};
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    set<pair<int,int>> st;
    int n = A.size();
    int i,j,x,y;
    i = j = n-1;
    vector<int> sol;
    priority_queue<CustomClass, vector<CustomClass>, CompareCustomClass> pq;
    pq.push(CustomClass(A[i]+B[j],i,j));
    st.insert(make_pair(i,j));
    while(sol.size() < n) {
        CustomClass a = pq.top();
        pq.pop();
        sol.push_back(a.val);
        x = a.x;
        y = a.y;
        if(st.find(make_pair(x,y-1)) == st.end()) {
            pq.push(CustomClass(A[x]+B[y-1],x,y-1));
            st.insert(make_pair(x,y-1));
        }
        if(st.find(make_pair(x-1,y)) == st.end()) {
            pq.push(CustomClass(A[x-1]+B[y],1,y));
            st.insert(make_pair(x-1,y));
        }
    }
    
    return sol;
}
