class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        
        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                set<int> s;
                for (int x = 0; x < k; ++x) {
                    for (int y = 0; y < k; ++y) {
                        s.insert(g[i + x][j + y]);
                    }
                }
                if (s.size() == 1) {
                    ans[i][j] = 0;
                } else {
                    int prev = *s.begin(), res = INT_MAX;
                    for (auto it = next(s.begin()); it != s.end(); ++it) {
                        res = min(res, *it - prev);
                        prev = *it;
                    }
                    ans[i][j] = res;
                }
            }
        }
        return ans;
    }
};
