class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, c1 = 0;
        int len = INT_MAX;

        for (int r = 0; r < n; r++) 
        {
            c1 += (s[r] - '0');
            while (c1 >= k) 
            {
                if (c1 == k) len = min(len, r - l + 1);
                c1 -= (s[l] - '0');
                l++;
            }
        }

        string ans(n, 'z');
        for (int i = 0; i + len <= n; i++) 
        {
            string sub = s.substr(i, len);
            if (count(sub.begin(), sub.end(), '1') == k) ans = min(ans, sub);
        }
        return (ans == string(n, 'z')) ? "" : ans;
    }
};
