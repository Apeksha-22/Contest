class Solution {
public:
    string resultingString(string s) {
        int n=s.size();
        stack<char>tem;
            for(int j=0; j<n; j++){
                if(!tem.empty() && (abs(s[j] - tem.top()) == 1 || abs(s[j] - 
                tem.top()) == 25)){
                    tem.pop();
                }else
                tem.push(s[j]);
            }
       string res = "";
        while (!tem.empty()) {
            res += tem.top();
            tem.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
