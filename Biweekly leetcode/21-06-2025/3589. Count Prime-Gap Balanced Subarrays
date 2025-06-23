int MX = 50005;

class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        return isPrime;
    }

    int primeSubarray(vector<int> &a, int k) {
        int n = a.size();
        vector<bool> p = sieve(MX);
        vector<int> pre(n);
        
        pre[0] = p[a[0]];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + p[a[i]];
        
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1, idx = -1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                int cnt = pre[m] - (i > 0 ? pre[i - 1] : 0);
                if (cnt >= 2) {
                    idx = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            nxt[i] = idx;
        }

        multiset<int> ms;
        int j = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (nxt[i] == -1) break;

            while (j < n) {
                if (p[a[j]]) ms.insert(a[j]);

                if (ms.size() >= 2 && (*ms.rbegin() - *ms.begin() > k)) {
                    if (p[a[j]]) ms.erase(ms.find(a[j]));
                    break;
                }
                j++;
            }

            if (j > nxt[i]) res += (j - nxt[i]);

            if (p[a[i]]) ms.erase(ms.find(a[i]));
        }

        return res;
    }
};
