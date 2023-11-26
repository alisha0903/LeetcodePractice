class Solution {
public:
    int jump(vector<int>& nums) {
        
        int i=0,end=0,maxend=0,step=0, n=nums.size();
        while(end<n-1)
        {
            step++;
            for(;i<=end;i++)
            {
                maxend=max(maxend,i+nums[i]);
            if(maxend>=n-1)
                return step;
            }
            if(end==maxend)break;
            end=maxend;
            
        }
        return n==1? 0:1;
        
    }
};
      