/*
@Description : There are A cities numbered from 1 to A. You have already visited M cities,
the indices of which are given in an array B of M integers.

If a city with index i is visited, you can visit either the city with index i-1 (i >= 2) or the city with index i+1 (i < A)
if they are not already visited.

Eg: if N = 5 and array M consists of [3, 4], then in the first level of moves, you can either visit 2 or 5.

You keep visiting cities in this fashion until all the cities are not visited.
Find the number of ways in which you can visit all the cities modulo 10^9+7.
*/

long long mod = 1000000007;
long long power(long long a, long long n){
    long long ans = 1;
    long long x = a;
    while(n){
        if(n%2 == 0){
            x = (x * x)%mod;
            n = n/2;
        }else{
            ans = (ans * x)%mod;
            n = n - 1;
        }
    }
    return ans;
}
long long modInverse(long long n) 
{ 
    return power(n, mod-2); 
} 
int Solution::solve(int A, vector<int> &B) {
    vector <long long> dp(A - B.size() + 1);
    dp[0] = 1;
    for(int i = 1; i < dp.size(); i++){
        dp[i] = (i%mod * dp[i-1]%mod)%mod;
    }
    sort(B.begin(),B.end());
    long long ans = 1;
    ans = dp[A - B.size()];
    if(B.size() == 0){
        return ans;
    }
    //cout << "here\n";
    ans = ((ans%mod) * (modInverse(dp[B[0] - 1]))%mod)%mod;
    ans = ((ans%mod) * (modInverse(dp[A- B.back()]))%mod)%mod;
    for(int i = 1; i < B.size(); i++){
        long long t = B[i] - B[i-1];
        if(t > 1){
            ans = ((((ans%mod) * (modInverse(dp[t-1])%mod))%mod) * (power(2,t-2)%mod))%mod;
        }
    }
    return (int)ans;
}
