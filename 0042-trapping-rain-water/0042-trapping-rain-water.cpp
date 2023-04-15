class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n),right(n);
        int mx=height[0];
        for(int i=0;i<height.size();i++)
        {
            if(height[i]>mx)
            {left[i]=height[i];
             mx=height[i];
            }
            else left[i]=mx;
            
        }
        mx=0;
         for(int i=height.size()-1;i>=0;i--)
        {
            if(height[i]>mx)
            {right[i]=height[i];
             mx=height[i];
            }
            else right[i]=mx;
        }
        int sum=0;
        for(int i=0;i<height.size();i++)
        {
            sum+=min(left[i],right[i])-height[i];
        }
        return sum;
    }
};