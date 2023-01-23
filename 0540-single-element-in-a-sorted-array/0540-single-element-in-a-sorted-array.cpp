class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int beg=0,end=nums.size()-1,mid=(beg+end)/2;
        while(beg<end)
        {
            mid=(beg+end)/2;
            if((mid%2==0&&nums[mid]==nums[mid+1])||(mid%2==1)&&nums[mid]==nums[mid-1])
            beg=mid+1;
            else end=mid;
        }
        return nums[beg];
    }
};