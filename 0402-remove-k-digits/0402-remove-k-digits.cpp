class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size(),c=0;
        stack<char>st;
        st.push(num[0]);
        if(n<=k)
        return "0";
        if(k==0)
        return num;
        for(int i=1;i<n;i++){
            while(c<k && !st.empty() && st.top()>num[i]){
                c++;
                st.pop();
            }
            st.push(num[i]);
            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
            while(c<k && !st.empty())
            {
                c++;
                st.pop();
            }
        int z=st.size();
        string res;
        for(int i=0;i<z;i++){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        if(res.length()==0)
        res="0";
        return res;
    }
};