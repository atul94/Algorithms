/*
@Description Given a string,
find the length of the longest substring without repeating characters.
*/

int Solution::lengthOfLongestSubstring(string A) {
    map<char,int> mp;
    int tempans = 0;
    int ans = 0;
    for(int i = 0; i < A.size(); i++){
        if(mp.find(A[i]) == mp.end()){
            mp[A[i]] = i;
            tempans++;
        }else{
            if(mp[A[i]] < (i-tempans)){
                mp[A[i]] = i;
                tempans++;
            }else{
                tempans = i - mp[A[i]];
                mp[A[i]] = i;
            }
        }
        ans = max(tempans, ans);
    }
    return ans;
}
