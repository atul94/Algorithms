/*
@Description Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.
*/
int Solution::removeElement(vector<int> &A, int B) {
    int i,n,j;

    i = -1;j = 0;
    
    while(j < A.size()){
        if(A[j] != B){
            i++;
            A[i] = A[j];
            j++;
        }
        else{
            j++;
        }
    }
    return i + 1;
}
