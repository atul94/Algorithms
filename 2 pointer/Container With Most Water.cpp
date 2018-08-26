/*
@Description Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained
 ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).
*/

int Solution::maxArea(vector<int> &A) {
    int sol = INT_MIN;
    int n,i,j, temp;
    n = A.size();
    if(n == 1){
        return 0;
    }
    i = 0;
    j = n - 1;
    while(i < j){
        temp = min(A[i],A[j]) * (j - i);
        if(temp > sol){
            sol = temp;
        }
        if(A[i] >= A[j]){
            j--;
        }else{
            i++;
        }
    }
    return sol;
}