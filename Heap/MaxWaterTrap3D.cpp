/**
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

 

Note:

Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

 

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.

*/

class QueueNode{
    public:
    int x;
    int y;
    int val;
    QueueNode(int x, int y, int val) {
        this->x = x;
        this->y = y;
        this->val = val;
    }
};
class QueueNodeComparator{
  public:
    bool operator()(QueueNode a, QueueNode b) {
        return a.val > b.val;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& A) {
        if(A.size() == 0)
            return 0;
        int n = A.size();
        int m = A[0].size();
        priority_queue<QueueNode, vector<QueueNode>, QueueNodeComparator> pq;
        vector<vector<int> > isVisited(n, vector<int>(m,-1));
        for(int i = 0; i < n; i++) {
            pq.push(QueueNode(i,0,A[i][0]));
            pq.push(QueueNode(i,m-1,A[i][m-1]));
            isVisited[i][0] = 0;
            isVisited[i][m-1] = 0;
        }
        for(int i = 0; i < m; i++) {
            pq.push(QueueNode(0,i,A[0][i]));
            pq.push(QueueNode(n-1,i,A[n-1][i]));
            isVisited[0][i] = 0;
            isVisited[n-1][i] = 0;
        }
        int maxVal = 0;
        int ans = 0;
        while(!pq.empty()){
            QueueNode a = pq.top();
            pq.pop();
            isVisited[a.x][a.y] = 1;
            if(maxVal > a.val) {
                ans += maxVal - a.val;
            }else{
                maxVal = a.val;
            }
            if(a.x-1 >= 0 && -1==isVisited[a.x-1][a.y]) {
                pq.push(QueueNode(a.x-1,a.y,A[a.x-1][a.y]));
                isVisited[a.x-1][a.y] = 0;
            }
            if(a.x+1 < n && -1==isVisited[a.x+1][a.y]) {
                pq.push(QueueNode(a.x+1,a.y, A[a.x+1][a.y]));
                isVisited[a.x+1][a.y] = 0;
            }
            if(a.y-1 >= 0 && -1==isVisited[a.x][a.y-1]) {
                pq.push(QueueNode(a.x, a.y-1, A[a.x][a.y-1]));
                isVisited[a.x][a.y-1] = 0;
            }
            if(a.y+1 < m && -1==isVisited[a.x][a.y+1]) {
                pq.push(QueueNode(a.x,a.y+1, A[a.x][a.y+1]));
                isVisited[a.x][a.y+1] = 0;
            }
        }
        return ans;
    }
};
