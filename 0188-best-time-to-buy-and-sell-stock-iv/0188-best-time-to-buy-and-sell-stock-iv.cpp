class Solution {
public:

    // int solveMem(int index, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
    //     int n = prices.size();
    //     if(index == n)
    //         return 0;

    //     if(k == 0)
    //         return 0;

    //     if(dp[index][buy][k] != -1)
    //         return dp[index][buy][k];

    //     int profit = 0;
        
    //     if(buy){
    //         int buykaro = -prices[index] + solveMem(index+1, 0, k, prices, dp);
    //         int skipkaro = 0 + solveMem(index+1, 1, k, prices, dp);
    //         profit = max(buykaro, skipkaro);
    //     }
    //     else{
    //         int sellkaro = +prices[index] + solveMem(index+1, 1, k-1, prices, dp);
    //         int skipkaro = 0 + solveMem(index+1, 0, k, prices, dp);
    //         profit = max(sellkaro, skipkaro);
    //     }

    //     dp[index][buy][k] = profit;
    //     return dp[index][buy][k];
    // }

    int solveTab(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){
                    int profit = 0;
                    if(buy){
                        int buykaro = -prices[index] + dp[index+1][0][limit];
                        int skipkaro = 0 + dp[index+1][1][limit];
                        profit = max(buykaro, skipkaro);
                    }
                    else{
                        int sellkaro = +prices[index] + dp[index+1][1][limit-1];
                        int skipkaro = 0 + dp[index+1][0][limit];
                        profit = max(sellkaro, skipkaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
 
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, -1)));
        // return solveMem(0, 1, k, prices, dp);

        return solveTab(k, prices);
    }
};