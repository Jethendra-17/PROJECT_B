// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
       vector<vector<int>> adj(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 && i != j) {
                    adj[i][j] = 1;
                }
            }
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dfs(i, i, adj, ans);
        }
        return ans;
    }
     static void dfs(int i, int j, const vector<vector<int>>& adj, vector<vector<int>>& ans) {
        ans[i][j] = 1;
        for (int it = 0; it < adj[j].size(); it++) {
            if (adj[j][it] == 1 && ans[i][it] == 0) {
                dfs(i, it, adj, ans);
            }
        }
    }
};
