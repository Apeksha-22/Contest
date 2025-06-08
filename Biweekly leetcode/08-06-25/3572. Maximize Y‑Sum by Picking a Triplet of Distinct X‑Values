class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
    unordered_map<int, int> mp;

    int n = x.size();
    for (int i = 0; i < n; i++) {
        mp[x[i]] = max(mp[x[i]], y[i]);
    }
    vector<int> maxYs;
    for (auto& p : mp) {
        maxYs.push_back(p.second);
    }
    if (maxYs.size() < 3) return -1;
    sort(maxYs.begin(), maxYs.end(), greater<int>());

    return maxYs[0] + maxYs[1] + maxYs[2];
    }
};
