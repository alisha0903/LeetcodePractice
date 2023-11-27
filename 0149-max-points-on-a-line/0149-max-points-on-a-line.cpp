class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1; 
        int n=points.size();
        for(int i=0;i<n-1;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                //calculating the slope
                double x = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                if(points[j][1]-points[i][1]<0 &&(points[j][0]-points[i][0])==0 ) //infinite slop for Perpendicular line
                mp[abs(x)]++; 
                else
                    mp[x]++;//slope number k counts keep adding
            }
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);  // +1 for the current point(point itself)
            ans = max(temp, ans);
        }
        return ans;    
    }
};