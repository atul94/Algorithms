/*
@Description Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and 
minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.
*/


int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i,j,k;
    int ans = INT_MAX;
    i = j = k = 0;
    while(i < A.size() && j < B.size() && k < C.size()){
        ans = min(ans, max(A[i],max(B[j],C[k])) - min(A[i], min(B[j], C[k])));
        if(A[i] <= B[j] && A[i] <= C[k]){
            i++;
        }else if(B[j] <= A[i] && B[j] <= C[k]){
            j++;
        }else{
           k++; 
        }
        
    }
    return ans;
}
