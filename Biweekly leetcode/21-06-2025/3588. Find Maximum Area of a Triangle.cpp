class Solution {
public:
    long long maxArea(vector<vector<int>>& a) {
        int n = a.size();
        long long res = 0;

        vector<vector<int>> xa = a;
        sort(xa.begin(), xa.end());

        for (int i = 0; i < n;) {
            int x = xa[i][0], y0 = xa[i][1], y1 = xa[i][1], j = i;
            while (j < n && xa[j][0] == x) {
                y0 = min(y0, xa[j][1]);
                y1 = max(y1, xa[j][1]);
                j++;
            }
            if (y1 != y0) {
                int w = max(abs(x - xa[0][0]), abs(x - xa[n - 1][0]));
                res = max(res, 1LL * (y1 - y0) * w);
            }
            i = j;
        }

        vector<vector<int>> ya = a;
        sort(ya.begin(), ya.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] == v[1] ? u[0] < v[0] : u[1] < v[1];
        });

        for (int i = 0; i < n;) {
            int y = ya[i][1], x0 = ya[i][0], x1 = ya[i][0], j = i;
            while (j < n && ya[j][1] == y) {
                x0 = min(x0, ya[j][0]);
                x1 = max(x1, ya[j][0]);
                j++;
            }
            if (x1 != x0) {
                int h = max(abs(y - ya[0][1]), abs(y - ya[n - 1][1]));
                res = max(res, 1LL * (x1 - x0) * h);
            }
            i = j;
        }

        return res == 0 ? -1 : res;
    }
};
