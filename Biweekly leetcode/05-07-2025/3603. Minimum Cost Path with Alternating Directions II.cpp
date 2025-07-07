class Solution {
public:
using ll = long long;
ll f(int p, int i, int j, vector<vector<int>>& wc,vector<vector<vector<ll>>>&dp){
    if(i== wc.size()-1 && j==wc[0].size()-1)return 0;
    if(i== wc.size() || j==wc[0].size())return 1e15;
    if(dp[i][j][p]!= -1)return dp[i][j][p];
    ll ans = LLONG_MAX;
    if(p%2 == 1){
        ans = min(ans,(i+2)*(j+1)+f(0,i+1,j,wc,dp));
        ans = min(ans,(i+1)*(j+2)+f(0,i,j+1,wc,dp));
    }else ans = min(ans,wc[i][j]+f(1,i,j,wc,dp));

    return dp[i][j][p] = ans;
}
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<ll>>>dp(m,vector<vector<ll>>(n,vector<ll>(2,-1)));
        return 1 + f(1,0,0,waitCost,dp);
    }
};
