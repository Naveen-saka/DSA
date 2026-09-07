class Solution {
public:
    int m = 1e9 + 7;

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<long long> dp(n);
        vector<int> last(26, -1);

        dp[0] = 2;
        last[s[0] - 'a'] = 0;

        for (int i = 1; i < n; i++) {
            dp[i] = (2LL * dp[i - 1]) % m;
            int j = last[s[i] - 'a'];
            if (j != -1) {
                if (j == 0)
                    dp[i] = (dp[i] - 1 + m) % m;
                else
                    dp[i] = (dp[i] - dp[j - 1] + m) % m;
            }

            last[s[i] - 'a'] = i;
        }

        return (dp[n - 1] - 1 + m) % m;
    }
};