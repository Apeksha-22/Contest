class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pfix(n+1, 0);

        for(int i=1; i<=n; i++){
            pfix[i] = pfix[i-1] ^ nums[i-1];
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
        for(int i=0; i<=n; i++){
            dp[i][1] = pfix[i];
        }

        for(int x = 2; x<=k; x++){
            for(int y = x; y<=n; y++){
                for(int z = x-1; z<y; z++){
                    int segXOR = pfix[y] ^ pfix[z];
                    int maxXOR = max(segXOR, dp[z][x-1]);
                    dp[y][x] = min(dp[y][x], maxXOR);
                }
            }
        }
        return dp[n][k];
    }
};
