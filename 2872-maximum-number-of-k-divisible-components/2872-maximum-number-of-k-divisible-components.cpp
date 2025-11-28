class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        // Make an adjacency list of given tree
        for (auto& ed: edges) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }   

        int ans = 0;

        std::function<int(int, int)> dfs = [&](int u, int parent) -> int {
            // initial value
            int overall_sum = values[u] % k;

            for (auto &v: adj[u]) {
                // visite each unvisited children
                if (v != parent) {
                    // since dfs(v, u) will return the sum % k of that child subtree
                    // so we just have to add and do modulo
                    overall_sum = (overall_sum + dfs(v, u)) % k;
                    overall_sum %= k;
                }
            }
            // add if this subtree has sum % k == 0
            ans += (overall_sum == 0);
            // return the sum of this subtree
            return overall_sum;
        };

        // Start with node 0
        dfs(0, -1);

        return ans;
    }
};