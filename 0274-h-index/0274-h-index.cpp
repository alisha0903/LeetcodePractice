class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
          if (citations.size()== 0)
        return 0;
      
        int len = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            if (len <= citations[i])
                return len;
            else
                len--;
        }
        return len;
    }
};