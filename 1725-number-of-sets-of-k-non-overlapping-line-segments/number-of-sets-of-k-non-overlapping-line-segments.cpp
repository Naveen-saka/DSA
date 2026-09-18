class Solution {
public:
    int m = 1e9 + 7;
    int go(int i,int n,int k,auto &dp)
    {
        if(!k) return !k;
        if(i>=n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans = go(i+1,n,k,dp);
        for (int j = i + 1;n-j>k-1; j++) 
        {
            ans += go(j,n,k - 1,dp);
            ans %= m;
        }
        return dp[i][k] = ans%m;
    }
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));        
        return go(0,n,k,dp)%m;
    }
};