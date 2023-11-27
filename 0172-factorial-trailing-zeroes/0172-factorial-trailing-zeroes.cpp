class Solution {
public:
    int trailingZeroes(int n) {
        //the total factors of 5 will be the number of trailing zeroes
        //for eg  25  has 1 5 so two additional
    int sum=0;
	int tmp=0;
	while(n/5>0)
	{
		n=n/5;
		sum+=n;
		
    }
    return sum;
    }
};