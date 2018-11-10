/**
@Description Find out the number of N digit numbers, whose digits on being added equals to a given number S.
Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007
*/
int mod = 1000000007;
vector <vector <int> > dp;

int Solution::solve(int A, int B) {
    dp.clear();
    dp.resize(A+1, vector<int>(B+1, 0));
    for(int i = 1; i <= B; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= min(B,9); i++){
        dp[1][i] = 1;
    }
    for(int j = 10; j <= max(9, B); j++){
        dp[1][j] = 0;
    }
    if(A == 1){
        return dp[A][B];
    }
    for(int i = 2; i <= A; i++){
        for(int j = 1; j <= B; j++){
            dp[i][j] = 0;
            for(int l = 0; l <= 9; l++){
                if(j-l < 0){
                    break;
                }
                dp[i][j] = (dp[i][j]%mod + dp[i-1][j-l]%mod)%mod;
            }
        }
        
    }
    return dp[A][B];
}
