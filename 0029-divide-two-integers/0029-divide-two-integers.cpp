class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)
            return 1;
        bool isPositive = (dividend<0==divisor<0);   
        unsigned int a=abs(dividend);
        unsigned int b=abs(divisor);
        unsigned int ans=0;
        while(a>=b){ // keeps omn going till 0..least number appear 
            short q = 0;
            while(a>(b<<(q+1)))// kind of recusrion thing
                q++;
            ans += (1<<q); 
            a = a - (b<<q); 
        }
        if(ans==(1<<31) and isPositive)   
            return INT_MAX;
        return isPositive ? ans : -ans;
    }
};