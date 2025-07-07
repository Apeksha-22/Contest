class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        int posistep=0,negistep=0;
        vector<int>v=nums;
        for(int i=0;i<n-1;i++){
            if(v[i]==1)continue;
            else{
                v[i]=1;
                v[i+1]=-1*v[i+1];
                posistep++;
            }
        }
        if(v[n-1]==-1)posistep=-1;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==-1)continue;
            else{
                nums[i]=-1;
                nums[i+1]=-1*nums[i+1];
                negistep++;
            }
        }
        if(nums[n-1]==1)negistep=-1;
        if(posistep==-1 && negistep==-1)return false;
        else if(posistep!=-1 && negistep!=-1)return min(posistep,negistep)<=k;
        else if(posistep!=-1)return posistep<=k;
        return negistep<=k;
    }
};
