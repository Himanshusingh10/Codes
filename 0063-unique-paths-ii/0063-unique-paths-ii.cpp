class Solution {
public:
        int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1&&m==1&&grid[0][0]==1) return 0;
        if(n==1&&m==1&&grid[0][0]==0) return 1;
        int dp[n][m];
        dp[0][0]=1;
        int val=1;
        for(int i=0;i<n;i++){
            if(grid[i][0]!=1){
                dp[i][0]=val;
            }
            else{
                val=0;
                dp[i][0]=0;
            }
        }
        val=1;
        for(int j=0;j<m;j++){
            if(grid[0][j]!=1){
                dp[0][j]=val;
            }
            else{
                val=0;
                dp[0][j]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }
                else if(dp[i-1][j]==0&&dp[i][j-1]!=0){
                    dp[i][j]=dp[i][j-1];
                }
                else if(dp[i-1][j]!=0&&dp[i][j-1]==0){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};