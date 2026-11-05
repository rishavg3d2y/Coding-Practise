#include <iostream>
#include <algorithm>
#include <array>
#include <memory>
#include <vector>
using namespace std;
int main() {
    
    // TODO: Add the twisted mirror solution here.
    return 0;
     class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1000000007;
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<array<int,2>>> dp(
            m, vector<array<int,2>>(n, array<int,2>{0,0}));
        
        for (size_t i = 0; i< m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                int is_mirror= grid[m-i-1][n-j-1];
                if (i==0 && j==0){
                    dp[m-i-1][n-j-1][0]=1;
                    dp[m-i-1][n-j-1][1]=1;
            

                }
                else if (i==0){
                    if (is_mirror==1){
                    dp[m-i-1][n-j-1][0]=0 ;
                    dp[m-i-1][n-j-1][1]= dp[m-i-1][n-j][0] ;
                    }
                    else{
                     dp[m-i-1][n-j-1][1]= dp[m-i-1][n-j][0] ;
                     dp[m-i-1][n-j-1][0]= dp[m-i-1][n-j][0] ;

   
                    }
                }
                else if (j==0){
                      if (is_mirror==1){
                    dp[m-i-1][n-j-1][1]=0 ;
                    dp[m-i-1][n-j-1][0]= dp[m-i][n-j-1][1] ;
                    }
                    else{
                      dp[m-i-1][n-j-1][0]= dp[m-i][n-j-1][1] ;
                        dp[m-i-1][n-j-1][1]= dp[m-i][n-j-1][1] ;
   
                    }

                    }
                else{

                           if (is_mirror==0){
                        dp[m-i-1][n-j-1][0] =
                            (dp[m-i][n-j-1][1] + dp[m-i-1][n-j][0]) % MOD;
                        dp[m-i-1][n-j-1][1]= dp[m-i-1][n-j-1][0];
                }
                if (is_mirror==1){
                    dp[m-i-1][n-j-1][0]=dp[m-i][n-j-1][1];
                    dp[m-i-1][n-j-1][1]= dp[m-i-1][n-j][0];
                        
                }
            }
            }
            
        }
      return dp[0][0][0];
    }
};
}
