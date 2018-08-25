@Description Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map <int,int > mp;
    for(int i = 0; i < A.size(); i++){
        if(mp.find(A[i]) == mp.end())
            mp[A[i]] = 0;
        mp[A[i]]++;
        
        if(B != 0 && (mp.find(A[i]-B) != mp.end() || mp.find(A[i]+B) != mp.end())){
                return 1;
            
        }else{
            if(B == 0 && mp[A[i]] > 1){
                return 1;
            }
        }
    }
    return 0;
}
