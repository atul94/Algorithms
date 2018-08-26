/*
@Description Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place
*/
int Solution::removeDuplicates(vector<int> &A) {
    int length = 0;
    int count = 1;
    int i,j,n;
    n = A.size();
    j = 1; i = 0;
    while(j < n){
        if(A[i] != A[j]){
            i++;
            A[i] = A[j];
            j++;
            count = 1;
        }
        else{
            if(count < 2){
               i++;
                A[i] = A[j];
                j++;
                count ++;
            }
            else
            {
                count++;
                j++;
            }
        }
    }
    return i +1;
}