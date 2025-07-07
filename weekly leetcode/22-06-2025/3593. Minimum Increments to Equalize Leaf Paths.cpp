typedef long long ll;

class Solution {
public:
    void dfs1(int u, int p, vector<vector<int>>& g, vector<int>& c, vector<ll>& s) {
        for (int v : g[u]) {
            if (v == p) continue;
            s[v] = s[u] + c[v];
            dfs1(v, u, g, c, s);
        }
    }

    ll dfs2(int u, int p, vector<vector<int>>& g, vector<ll>& s, ll tgt, vector<int>& a) {
        bool leaf = true;
        ll mn = LLONG_MAX;
        for (int v : g[u]) {
            if (v == p) continue;
            leaf = false;
            mn = min(mn, dfs2(v, u, g, s, tgt, a));
        }
        if (leaf) mn = tgt - s[u];
        return a[u] = mn;
    }

    void dfs3(int u, int p, vector<vector<int>>& g, vector<int>& a, int& res) {
        ll par = (p == -1) ? 0LL : a[p];
        if (a[u] > par) res++;
        for (int v : g[u]) {
            if (v == p) continue;
            dfs3(v, u, g, a, res);
        }
    }

    int minIncrease(int n, vector<vector<int>>& e, vector<int>& c) {
        vector<vector<int>> g(n);
        for (auto& x : e) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        vector<ll> s(n);
        s[0] = c[0];
        dfs1(0, -1, g, c, s);

        ll tgt = LLONG_MIN;
        for (int u = 0; u < n; u++) {
            bool leaf = (u == 0 ? g[u].empty() : g[u].size() == 1);
            if (leaf) tgt = max(tgt, s[u]);
        }

        vector<int> a(n);
        int res = 0;
        dfs2(0, -1, g, s, tgt, a);
        dfs3(0, -1, g, a, res);

        return res;
    }
};
