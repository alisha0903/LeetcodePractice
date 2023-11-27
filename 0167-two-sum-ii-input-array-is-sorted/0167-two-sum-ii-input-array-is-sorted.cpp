class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0,end=numbers.size()-1;
        vector<int>res;
        for(int i=0;i<=numbers.size()-1;i++)
        {
            if(numbers[start]+numbers[end]==target)
            {res.push_back(start+1);
             res.push_back(end+1);
             break;
               
            }
            else if(numbers[start]+numbers[end]>target)
                end--;
            else start++;
        }
        return res;
    }
};