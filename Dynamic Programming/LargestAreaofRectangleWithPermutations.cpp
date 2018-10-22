/**
@Description 

Given a binary grid i.e. a 2D grid only consisting of 0’s and 1’s,
find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.
You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid.
Please follow the below example for more clarity.

Lets say we are given a binary grid of 3 * 3 size.

1 0 1

0 1 0

1 0 0

At present we can see that max rectangle satisfying the criteria mentioned in the problem is of 1 * 1 = 1 area 
i.e either of the 4 cells which contain 1 in it. Now since we are allowed to permutate the columns of the given matrix,
we can take column 1 and column 3 and make them neighbours. One of the possible configuration of the grid can be:

1 1 0

0 0 1

1 0 0

Now In this grid, first column is column 1, second column is column 3 and third column is column 2 from the original given grid.
Now, we can see that if we calculate the max area rectangle, we get max area as 1 * 2 = 2 which is bigger than the earlier case. 
Hence 2 will be the answer in this case.

*/
vector <int> countSort(vector <int> &A, int m){
    vector<int> count(m+1,0);
    for(int i = 0; i < A.size(); i++){
        count[A[i]]++;
    }
    for(int i = 1; i <= m; i++){
        count[i] += count[i-1];
    }
    vector <int> output(A.size());
    for(int i = 0; i < A.size(); i++){
        output[count[A[i]]-1] = A[i];
        count[A[i]]--;
    }
    return output;
}
int maxAreaRectangle(vector <int> A, int m){
    int n = A.size();
    A = countSort(A,m);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == 0){
            continue;
        }else{
            ans = max(ans, A[i] * (n - i));
        }
    }
    return ans;
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector <vector <int> > count(n, vector <int>(m,0));
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || A[i][j] == 0){
                count[i][j] = A[i][j];
            }else{
                count[i][j] = count[i-1][j] + 1;
            }
        }
        ans = max(ans, maxAreaRectangle(count[i], n));
    }
    return ans;
}
