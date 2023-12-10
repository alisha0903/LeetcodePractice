class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
           unordered_set<int> m(nums1.begin(), nums1.end());//hrr elemnt ko set m daal dia
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {//arr 2 ka lemeent is in set/arr1
                res.push_back(a);//added in res
                m.erase(a);
            }
        return res;
         
    }
};