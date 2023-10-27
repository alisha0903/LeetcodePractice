class Solution {
public:
    int lengthOfLastWord(string s) {

        int count=0;
        int l=s.length();
        for(int i=l-1;i>=0;i--)
        {
            if(s[i] == ' ' && count > 0) return count;
            if(s[i]!=' ')
                count++;
            
        }
        return count;
    }
};