class Solution {
public:
    long long maximumProfit(vector<int>& prices, int maxTransactions) {
        vector<long long> profit(maxTransactions + 1), buyProfit(maxTransactions, -1e9), sellProfit(maxTransactions);
        for (int price : prices) {
            for (int t = maxTransactions; t >= 1; --t) {
                profit[t] = max({profit[t], buyProfit[t - 1] + price, sellProfit[t - 1] - price});
                buyProfit[t - 1] = max(buyProfit[t - 1], profit[t - 1] - price);
                sellProfit[t - 1] = max(sellProfit[t - 1], profit[t - 1] + price);
            }
        }
        return *max_element(profit.begin(), profit.end());
    }

};
