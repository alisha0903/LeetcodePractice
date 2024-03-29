class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0,j=height.size()-1,mx=0;
        while(i<j)
        {
            mx=max(mx,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j])
                i++;
            else if(height[i]>=height[j])
                j--;
        }
        return mx;
    }
};
