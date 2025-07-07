class Solution {
public:
    long long power(long long b, long long e) {
        long long r = 1, M = 1000000007;
        b %= M;
        while (e > 0) {
            if (e % 2 == 1) r = (r * b) % M;
            b = (b * b) % M;
            e /= 2;
        }
        return r;
    }

    int assignEdgeWeights(std::vector<std::vector<int>>& e) {
        int n = e.size() + 1;
        std::vector<std::vector<int>> adj(n + 1);
        for (auto& ed : e) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        std::queue<std::pair<int, int>> q;
        std::vector<int> d(n + 1, -1);
        q.push({1, 0});
        d[1] = 0;

        int max_d = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int u = p.first, dist = p.second;
            max_d = std::max(max_d, dist);

            for (int v : adj[u]) {
                if (d[v] == -1) {
                    d[v] = dist + 1;
                    q.push({v, dist + 1});
                }
            }
        }

        int k = max_d;
        if (k == 0) return 0;

        long long ways = power(2, k - 1);
        return static_cast<int>(ways);
    }
};
