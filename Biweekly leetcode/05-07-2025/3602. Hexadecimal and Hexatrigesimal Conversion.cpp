class Solution {
public:
    string conversion(int val, int base){
        string s="";
        string x ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        int r=0;
        while(val>0){
            r = val % base;
            s += x[r];
            val /= base;
        }
        reverse(s.begin() , s.end());
        return s;
    }
    string concatHex36(int n) {
        int sqr = n*n;
        int cub = sqr*n;

        string x = conversion(sqr,16);
        string y = conversion(cub,36);

        return x+y;
    }
};
