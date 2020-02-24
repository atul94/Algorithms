//https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
/*
There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:

    The items that belong to the same group are next to each other in the sorted list.
    There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).

Return any solution if there is more than one solution and return an empty list if there is no solution.

 

Example 1:

Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]

*/



vector<int> topologicalSortArr(vector<vector<int> > &adjacencyList, vector<int> &A) {
    vector<int> sol;
    unordered_set<int> valExist;
    int n = adjacencyList.size();
    vector<int> isVisited(n, 0); 
    vector<pair<int, int> > st;
    for(int i = 0; i < A.size(); i++) {
        valExist.insert(A[i]);
    }
    for(int i = 0; i < A.size(); i++) {
        if(isVisited[A[i]] == 1)
            continue;
        st.push_back(make_pair(A[i], 0));
        while(!st.empty()) {
            int x,y,f;
            x = st.back().first;
            y = st.back().second;
            isVisited[x] = -1;
            f = 0;
            for(int j = y; j < adjacencyList[x].size(); j++) {
                if(isVisited[adjacencyList[x][j]] == 1) {
                    continue;
                }
                else if(isVisited[adjacencyList[x][j]] == -1) {
                    sol.clear();
                    return sol;
                }else {
                    st.back().second = j+1;
                    st.push_back(make_pair(adjacencyList[x][j], 0));
                    f = 1;
                    break;
                }
            }
            if(f == 1)
                continue;
            isVisited[x] = 1;
            st.pop_back();
            if(valExist.find(x) != valExist.end()) {
                
                sol.push_back(x);
            }
        }
        
    }
    return sol;
}
void insertValInMap(map<int, vector<int> > &group2nodes, int m, int val) {
    if(group2nodes.find(m) == group2nodes.end()) {
        vector<int> t;
        group2nodes[m] = t;
    }
    group2nodes[m].push_back(val);
} 
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        map<int, int> node2group;
        map<int, vector<int> > group2nodes;
        for(int i = 0; i < group.size(); i++) {
            if(group[i] != -1) {
                node2group[i] = group[i];
                insertValInMap(group2nodes, group[i], i);
            }else {
                node2group[i] = m;
                insertValInMap(group2nodes, m, i);
                m++;
            } 
        }
        
        set<pair<int, int> > isPresent;
        vector<vector<int> > groupAdjacencyList(m);
        vector<vector<int> > nodeAdjacencyList(n);
        for(int i = 0; i < beforeItems.size(); i++) {
            if(beforeItems[i].empty())
                continue;
            for(int j = 0; j < beforeItems[i].size(); j++) {
                nodeAdjacencyList[i].push_back(beforeItems[i][j]);
                if(node2group[i] != node2group[beforeItems[i][j]] && isPresent.find(make_pair(node2group[i], node2group[beforeItems[i][j]])) == isPresent.end()) {
                    isPresent.insert(make_pair(node2group[i], node2group[beforeItems[i][j]]));
                    groupAdjacencyList[node2group[i]].push_back(node2group[beforeItems[i][j]]);
                }
            }
        }
        for(auto it = group2nodes.begin(); it != group2nodes.end(); it++) {
            if(it->second.size() < 2)
                continue;
            vector<int> t = topologicalSortArr(nodeAdjacencyList, it->second);
            if(t.empty()){
                return t;
            }
            
            group2nodes[it->first] = t;
        }
        
        vector<int> t;
        for(int i = 0; i < m; i++) {
            t.push_back(i);
        }
        vector<int> gr =  topologicalSortArr(groupAdjacencyList, t);
        if(gr.empty())
            return gr;
        vector<int> sol;
        for(int i = 0; i < m; i++) {
            if(group2nodes.find(gr[i]) == group2nodes.end()) {
                continue;
            }
            for(int j = 0; j < group2nodes[gr[i]].size(); j++) {
                sol.push_back(group2nodes[gr[i]][j]);
            }
        }
        return sol;
    }
};
