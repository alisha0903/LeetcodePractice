class Solution {
public:
    int minOperations(string s) {
        
        int res = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            if (s[i] - '0' != i % 2)//char at even digits should be same ie jb jb diff aaega that is the no of opn to be done
                res++;
        return min(res, n - res);
    }
};