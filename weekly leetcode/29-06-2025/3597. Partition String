class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string>seen;
        vector<string>res;
        string x="";
        for(int i=0; i<s.size(); i++){
            x += s[i];
            if(seen.find(x) == seen.end()){
                seen.insert(x);
                res.push_back(x);
                x = "";
            }else continue;
        }
        return res;
    }
};
