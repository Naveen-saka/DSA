class Solution {
public:
    int n;
    vector<int>p,dp;
    int solve(int i)
    {
        if(i == p.size()-1) return p.back();
        if(dp[i]!=-1e9) return dp[i];
        int t = p[i] - solve(i+1);
        int nt = solve(i+1);
        return dp[i] = max(t,nt);
    }
    int stoneGameVIII(vector<int>& v) {
        n = v.size();
        p.resize(n);
        dp.resize(n);
        for(int i=0;i<n;i++) dp[i] = -1e9;
        p[0] = v[0];
        for(int i=1;i<n;i++) p[i] = p[i-1] + v[i];
        return solve(1);
    }
};