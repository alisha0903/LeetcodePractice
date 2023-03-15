class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(nums1.size(),-1);
        stack<int>st;
        unordered_map<int,int>umap;
        for(int i=0;i<nums2.size();i++)
        {
            int val=nums2[i];
            while(!st.empty() && val>st.top())
            {
                umap[st.top()]=val;
                st.pop();
            }
            st.push(val);
            
        }
        for(int i=0;i<nums1.size();i++)
        {
            int val=nums1[i];
            if(umap.find(val)!=umap.end())
            {
                res[i]=umap[val];
            }
            
        }
        
        return res;
        
    }
};