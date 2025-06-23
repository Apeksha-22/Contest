class Solution {
public:
    long long calc(vector<int>& a, int st) {
        vector<int> ev, od;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] % 2 == 0) ev.push_back(i);
            else od.push_back(i);
        }

        long long sw = 0;
        int ep = (st == 0) ? 0 : 1;
        int op = (st == 1) ? 0 : 1;

        for (int i = 0; i < ev.size(); ++i) {
            sw += abs(ev[i] - ep);
            ep += 2;
        }

        for (int i = 0; i < od.size(); ++i) {
            sw += abs(od[i] - op);
            op += 2;
        }

        return sw;
    }

    int minSwaps(vector<int>& a) {
        int e = 0, o = 0;
        for (int x : a) {
            if (x % 2 == 0) e++;
            else o++;
        }

        if (abs(e - o) > 1) return -1;

        long long ans = LLONG_MAX;
        if (e >= o) ans = min(ans, calc(a, 0));
        if (o >= e) ans = min(ans, calc(a, 1));

        return (int)(ans / 2);
    }
};
