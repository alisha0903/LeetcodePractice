class Solution {
public:
    bool canJump(vector<int>& nums) {
      int maxLocation = 0;
    for(int i=0; i<nums.size(); i++) {
        if(maxLocation<i) return false; 
        maxLocation = (i+nums[i]) > maxLocation ? i+nums[i] : maxLocation; 
    }
    return true;
    }
};