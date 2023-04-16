class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
       int n=nums.size();
        long long res=0;
        for(int i=0;i<n-1;i++){
            int mx=nums[i], mn=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]>mx)mx=nums[j];
                else if(nums[j]<mn)mn=nums[j];
                res+=mx-mn;
            }
        }
        return res; 
    }
};