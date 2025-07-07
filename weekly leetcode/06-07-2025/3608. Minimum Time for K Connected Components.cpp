class Solution {
private:
    vector<int> par;
    int find(int i) {
        if (par[i] == i) {
            return i;
        }
        return par[i] = find(par[i]);
    }
    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            par[i] = j;
            return true;
        }
        return false;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if (edges.empty()) {
            return 0;
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        par.resize(n);
        iota(par.begin(), par.end(), 0);

        int count = n;
        for (const auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            if (unite(u, v)) {
                count--;
            }
            if (count < k) {
                return t;
            }
        }
        return 0;
    }
};
