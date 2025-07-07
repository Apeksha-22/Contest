class Solution {
public:
    bool check(int n){
        for(int i=2; i<n-1; i++){
            if(n%i == 0)
            return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x : nums){
            freq[x]++;
        }

        for(auto& a : freq){
            if(a.second > 1 && check(a.second))
            return true;
        }
        return false;
    }
};
