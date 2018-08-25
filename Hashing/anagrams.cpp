/*
@Description Given an array of strings, return all groups of strings that are anagrams. 
Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.
*/

vector <int> doWork(string s){
    vector <int> sol(26,0);
    for(int i = 0; i < s.size(); i++){
        sol[s[i] - 'a']++;
    }
    return sol;
}
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<vector<int>, vector<int> > mp;
    for(int i = 0; i < A.size(); i++){
        vector <int> temp = doWork(A[i]);
        mp[temp].push_back(i+1);
    }
    vector <vector <int> > sol;
    for(map<vector<int>, vector<int> >::iterator it = mp.begin(); it != mp.end(); it++){
        sol.push_back(it->second);
    }
    return sol;
}