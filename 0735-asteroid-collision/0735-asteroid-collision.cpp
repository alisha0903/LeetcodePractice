class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
      int  n=asteroids.size();
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0||st.empty())
                st.push(asteroids[i]);
            else{
                if(!st.empty() && st.top()<0){
                st.push(asteroids[i]);
                continue;
                }
                while(!st.empty() &&st.top()>0&&st.top()<abs(asteroids[i]))
                { st.pop();}
                if(!st.empty()&&st.top()>0&&st.top()>abs(asteroids[i]))
                continue;
                if(!st.empty()&&st.top()>0&&st.top()==abs(asteroids[i]))
                { st.pop();
                continue;}
                else {
                    if(st.empty()||st.top()<0)
                    {st.push(asteroids[i]);}
                }
            }
        }

  vector<int>res(st.size());
        for(int i = (int)st.size()-1; i>= 0;i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
        
    }
};