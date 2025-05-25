class Solution {
public:
    int maxSubstrings(string w) {
        int len = w.length();
        if (len < 4) {
            return 0;
        }

        vector<int> dp(len + 1, 0);
        vector<int> max_dp(26, -1);

        for (int i = 1; i <= len; ++i) {
            dp[i] = dp[i-1];

            if (i >= 4) {
                char s = w[i-4];
                int si = s - 'a';
                if (max_dp[si] == -1) {
                    max_dp[si] = dp[i-4];
                } else {
                    max_dp[si] = max(max_dp[si], dp[i-4]);
                }
            }

            char e = w[i-1];
            int ei = e - 'a';
            if (max_dp[ei] != -1) {
                dp[i] = max(dp[i], 1 + max_dp[ei]);
            }
        }
        return dp[len];
    }
};
