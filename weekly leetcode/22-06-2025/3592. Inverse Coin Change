class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int>coin;
        vector<long long>dp(n+1, 0);
        dp[0] = 1;

        for(int i=1; i<=n; i++){
            int tar = numWays[i-1];
            if(dp[i] == (long long)tar - 1){
                coin.push_back(i);

                for(int j=i; j<=n; j++){
                    dp[j] += dp[j-i];
                }
            }if(dp[i] != tar)
            return {};
        }
        return coin;
    }
};
