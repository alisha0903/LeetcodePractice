class Solution {
public:
    int pivotInteger(int n) { 
        int total=n*(n+1)/2;
        int ans,sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=i;
            if(sum*2==total+i)
            {
                return i;
            }
        }
        return -1;
       
    }
};