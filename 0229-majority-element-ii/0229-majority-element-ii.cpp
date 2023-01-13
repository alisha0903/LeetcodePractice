class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>el;
        
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        for(auto it: freq)
        {
            if(it.second>nums.size()/3)
                el.push_back(it.first);
            
        }
            
       return el; 
    }
};