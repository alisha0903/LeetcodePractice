class Solution {
public:
   int longestCommonSubsequence(string &a, string &b) {
    int m=a.size();
       int n=b.size();
       int arr[m+1][n+1];
       for(int i=0;i<=n;i++)
           arr[0][i]=0;
       for(int i=0;i<=m;i++)
           arr[i][0]=0;
       for(int i=1;i<m+1;i++)
       {
           for(int j=1;j<n+1;j++)
           {
               if(a[i-1]==b[j-1])
                   arr[i][j]=arr[i-1][j-1]+1;
               else
                   arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
           }
       }
           return arr[m][n];
       }
       
};