class Solution {
public:
    bool checkAlphaNumeric(string s) {
        for (char ch : s) {
            if (!isalnum(ch) && ch != '_') return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>business={"electronics", "grocery", "pharmacy", "restaurant"};
        int n=code.size();
        vector<string>res;
        vector<vector<string>>temp;
        for(int i=0; i<n; i++){
            if(code[i].size() !=0 && checkAlphaNumeric(code[i]) && isActive[i]){
                if(find(business.begin(),business.end(),businessLine[i])!=business.end())
                temp.push_back({businessLine[i],code[i]});
            }
        }
        sort(temp.begin(),temp.end());
        for(auto x : temp){
            res.push_back(x[1]);
        }
        return res;
    }
};
