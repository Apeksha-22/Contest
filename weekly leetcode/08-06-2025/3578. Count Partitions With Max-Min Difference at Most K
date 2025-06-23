static const int MOD = 1000000007;

class Fenwick {
    int n;
    vector<int> t;
public:
    Fenwick(int x) : n(x), t(x + 1) {}
    void add(int i, int v) { for (++i; i <= n; i += i & -i) t[i] = (t[i] + v) % MOD; }
    int get(int i) { int r = 0; for (++i; i; i -= i & -i) r = (r + t[i]) % MOD; return r; }
    int sum(int l, int r) {
        if (l > r) return 0;
        int s = (get(r) - (l ? get(l - 1) : 0)) % MOD;
        return s < 0 ? s + MOD : s;
    }
};

class RangeTracker {
public:
    vector<int> calc(const vector<int>& a, int k) {
        int n = a.size(), s = 0;
        vector<int> l(n);
        deque<int> mx, mn;
        for (int i = 0; i < n; ++i) {
            while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
            mx.push_back(i);
            while (!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
            mn.push_back(i);
            while (s <= i && a[mx.front()] - a[mn.front()] > k) {
                if (mx.front() == s) mx.pop_front();
                if (mn.front() == s) mn.pop_front();
                ++s;
            }
            l[i] = s;
        }
        return l;
    }
};

class Solution {
public:
    int countPartitions(vector<int>& a, int k) {
        int n = a.size();
        auto l = RangeTracker().calc(a, k);
        Fenwick f(n + 1);
        f.add(0, 1);
        for (int i = 1; i <= n; ++i) f.add(i, f.sum(l[i - 1], i - 1));
        return f.sum(n, n);
    }
};
