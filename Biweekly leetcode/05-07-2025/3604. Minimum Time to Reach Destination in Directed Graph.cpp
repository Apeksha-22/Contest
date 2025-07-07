class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if (n == 1) return 0;

        unordered_map<int, vector<tuple<int, int, int>>> gr;
        for (auto& e : edges) {
            gr[e[0]].emplace_back(e[1], e[2], e[3]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> tm(n, INT_MAX);
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [t, u] = pq.top(); pq.pop();
            if (t >= tm[u]) continue;
            tm[u] = t;

            for (auto& [v, s, e] : gr[u]) {
                int nt = max(t, s);
                if (nt > e) continue;
                if (++nt < tm[v]) pq.push({nt, v});
            }
        }

        return tm[n - 1] == INT_MAX ? -1 : tm[n - 1];
    }
};
