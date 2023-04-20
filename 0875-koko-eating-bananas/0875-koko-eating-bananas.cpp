class Solution {
public:
    long long timeTaken(int mid,vector<int>&piles)
    {
        long long sum=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%mid==0)
                sum+=piles[i]/mid;
            else sum+=piles[i]/mid+1;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        
        while(low<=high)
        {
           int mid=low+(high -low)/2;
            if(timeTaken(mid,piles)<=h)
                high=mid-1;
            
            else low=mid+1;
        }
        return low;
    }
};