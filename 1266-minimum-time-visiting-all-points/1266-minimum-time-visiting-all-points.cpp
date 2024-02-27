class Solution {
public:
    int toTime(vector<int>&a,vector<int>&b)
    {
        int xdiff=abs(a[0]-b[0]);
        int ydiff=abs(a[1]-b[1]);
        return max(ydiff, xdiff);
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time=0;
        for(int i=1;i<points.size();i++)
        {
            time+=toTime(points[i-1],points[i]);
        }
        return time;
    }
};