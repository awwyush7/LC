class Solution {
public:
    int help(int i, int sum, vector<int> &rods, vector<vector<int>> &dp){
        int n = rods.size();
        if(i == n){
            if(sum == 0) return 0;
            return -1e5;
        }
        if(dp[i][sum + 5000] != -1) return dp[i][sum + 5000];
        int op1,op2,op3;
        op1 = rods[i] + help(i + 1, sum - rods[i], rods, dp);
        op2 = rods[i] + help(i + 1, sum + rods[i], rods, dp);
        op3 = help(i+1, sum, rods, dp);
        return dp[i][sum + 5000] =  max(max(op1,op2),op3);
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(n, vector<int>(1e5,-1));

        int ans= help(0,0,rods, dp);
        return ans/2;
    }
};