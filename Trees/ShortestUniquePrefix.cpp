/**
@Description Find shortest unique prefix to represent each word in the list.
Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
NOTE : Assume that no word is prefix of another. In other words, the representation is always possible.
Also each word consists of only lower case alphabets.
*/
class TrieNode{
    public:
        int count;
        vector<TrieNode *> ptr;
    TrieNode(){
      this->count = 1;
      this->ptr.resize(26, NULL);
    }
};
void fillTrie(TrieNode * head, string &S, int i){
    if(i >= S.size()){
        return;
    }else if(head->ptr[S[i]- 'a']){
        head->ptr[S[i] - 'a']->count++;
        head = head->ptr[S[i] - 'a'];
        fillTrie(head, S, i + 1);
    }else{
        head->ptr[S[i] - 'a'] = new TrieNode();
        head = head->ptr[S[i] - 'a'];
        fillTrie(head, S, i + 1);
    }
}
string findPrefix(TrieNode * head, string & targetString, int index){
    
    if(head->ptr[targetString[index] - 'a']->count == 1){
        return targetString.substr(0, index+1);
    }else{
        return findPrefix(head->ptr[targetString[index] - 'a'], targetString, index + 1);
    }
}
vector<string> Solution::prefix(vector<string> &A) {
    TrieNode * head = new TrieNode();
    for(int i = 0; i < A.size(); i++){
        fillTrie(head, A[i], 0);
    }
    vector <string> sol;
    for(int i = 0; i < A.size(); i++){
        
        sol.push_back(findPrefix(head, A[i], 0));
    }
    return sol;
}
