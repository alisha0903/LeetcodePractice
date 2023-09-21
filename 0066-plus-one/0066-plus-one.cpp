class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        int n=digits.size();
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                digits[i]++;
            if(digits[i]==10&&i!=0)
            {
                digits[i]=0;
                digits[i-1]++;
            }
            else break;
        }
        if(digits[0]==10)
        {digits[0]=0;
         digits.insert(digits.begin(),1);
         }
        return digits;
    }
};