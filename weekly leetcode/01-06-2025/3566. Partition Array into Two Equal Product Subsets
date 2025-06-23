class Solution {
public:
    bool checkEqualPartitions(vector<int>& a, long long t) {
        int n = a.size(), m = 1 << n;
        for (int x = 1; x < m - 1; ++x) {
            long long p1 = 1, p2 = 1;
            vector<int> v1, v2;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if (x & (1 << i)) {
                    p1 *= a[i];
                    if (p1 > t) {
                        ok = false;
                        break;
                    }
                    v1.push_back(a[i]);
                } else {
                    v2.push_back(a[i]);
                }
            }
            if (!ok || v2.empty()) continue;
            for (int y : v2) {
                p2 *= y;
                if (p2 > t) {
                    ok = false;
                    break;
                }
            }
            if (ok && p1 == t && p2 == t) return true;
        }
        return false;
    }
};
