class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        while(i<j)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i++];
            }
            else if(score>=1 && power + tokens[j] >=tokens[i])
            {
                score--;
                power+=tokens[j--];
            }
            else break;
        }
        while(i<j+1 && power>=tokens[i])
        {
            score++;
            power-=tokens[i++];
        }
        return score;
        
    }
};