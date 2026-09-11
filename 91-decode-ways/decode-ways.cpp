class Solution {
public:
    vector<int> dp;
    int solve(string s, int i) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0;
        for (int j = i; j < s.size() && j < i + 2; j++) {
            int n = stoi(s.substr(i, j - i + 1));
            if (n >= 1 && n <= 26)
                ans += solve(s, j + 1);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return solve(s, 0);
    }
};