/*
@Description The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
bool isSafe(vector<pair<int,int> > &queenPos, int x, int y){
    //cout << "size of queenPos = " << queenPos.size() << endl;
    for(int i = 0; i < queenPos.size(); i++){
        int diffY = abs(queenPos[i].second - y);
        int diffX = abs(queenPos[i].first - x);
        if(diffY == 0 || (diffY%diffX == 0 && diffY/diffX == 1)){
            return false;
        }
    }
    return true;
}

void pushAllPossibleCombination(vector<string> &combination, int numQueens, int maxQueens, vector<pair<int,int> > &queenPos,  vector< vector <string> > &sol){
    if(numQueens == maxQueens){
        sol.push_back(combination);
        return;
    }
    for(int i = 0; i < maxQueens; i++){
        if(isSafe(queenPos,numQueens,i)){
           
            combination[numQueens][i] = 'Q';
            queenPos.push_back(make_pair(numQueens, i));
            pushAllPossibleCombination(combination,numQueens+1, maxQueens, queenPos, sol);
            queenPos.pop_back();
            combination[numQueens][i] = '.';
        }
    }
    return;
}
vector<vector<string> > Solution::solveNQueens(int A) {
    vector <vector <string> > sol;
    string s = "";
    for(int i = 0; i < A; i++){
        s += '.';
    }
    vector<string> combination(A,s);
    vector <pair<int,int> > pos;
    pushAllPossibleCombination(combination, 0, A, pos, sol);
    return sol;
}
