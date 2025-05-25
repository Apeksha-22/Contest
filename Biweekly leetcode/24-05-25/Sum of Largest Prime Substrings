class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        unordered_set<string> u;
        int n = s.size();
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                u.insert(s.substr(i, j - i + 1));
        
        set<long long> p;
        for (auto x : u) {
            while (x.size() > 1 && x[0] == '0') x.erase(x.begin());
            if (x.empty()) continue;
            long long v = stoll(x);
            if (isPrime(v)) p.insert(v);
        }

        vector<long long> v(p.rbegin(), p.rend());
        long long r = 0;
        for (int i = 0; i < min(3, (int)v.size()); ++i) r += v[i];
        return r;
    }
    
    bool isPrime(long long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (long long i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }
};
