class Solution {
public:
    int minMoves(vector<string>& g, int maxe) {
        int m = g.size(), n = g[0].size();
        vector<pair<int, int>> L;
        int si, sj;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j] == 'S')
                    si = i, sj = j;
                else if (g[i][j] == 'L')
                    L.emplace_back(i, j);

        int k = L.size();
        int goal = (1 << k) - 1;
        queue<tuple<int, int, int, int, int>> q;
        q.emplace(si, sj, maxe, 0, 0);
        vector<vector<unordered_map<int, int>>> vis(
            m, vector<unordered_map<int, int>>(n));
        vis[si][sj][0] = maxe;

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [i, j, e, mask, steps] = q.front();
            q.pop();
            if (mask == goal)
                return steps;

            if (g[i][j] == 'R')
                e = maxe;
            if (e == 0)
                continue;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;
                if (g[ni][nj] == 'X')
                    continue;

                int ne = e - 1;
                int nmask = mask;

                for (int l = 0; l < k; ++l)
                    if (L[l].first == ni && L[l].second == nj)
                        nmask |= (1 << l);
                if (vis[ni][nj].count(nmask) && vis[ni][nj][nmask] >= ne)
                    continue;

                vis[ni][nj][nmask] = ne;
                q.emplace(ni, nj, ne, nmask, steps + 1);
            }
        }

        return -1;
    }
};
