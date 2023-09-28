class Solution {
public:
    int  countPrimes(int n)
    { //seive of erathosis jisse no time limit exceeded
       vector<bool> v(n, false);
        int ans = 0;
        for (int num=2;num<n;num++) {
            if (v[num]) 
                continue;
            ans++;
            for (long mult=(long)num * num; mult<n;mult+= num)
                v[mult]=true;
        }
        return ans;
    }
};