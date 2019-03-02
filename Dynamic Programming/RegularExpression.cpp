/**
@Description: Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).
**/

int Solution::isMatch(const string A, const string B) {
        int n = A.size();
    int m = B.size();
    vector <vector <bool> > dp(n+1, vector<bool>(m+1,false));
    
    dp[0][0] = true;
    for(int i = 2; i <= m; i++){
        if(B[i-1] == '*'){
            dp[0][i] = dp[0][i-2];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(B[j-1] == '*'){
                if(B[j-2] == '.' || B[j-2] == A[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                if(dp[i][j-2]){
                    dp[i][j] = dp[i][j-2];
                }
            }else{
                if(B[j-1] == A[i-1] || B[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
    }
    return dp[n][m];
}
