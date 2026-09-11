class Solution {
public:
    unordered_map<string, int> mp;

    int solve(string a, string b) {
        if (a == b) return 1;

        string key = a + "#" + b;

        if (mp.count(key))
            return mp[key];

        int n = a.size();

        for (int i = 1; i < n; i++) {
            if (solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i), b.substr(i)))
                return mp[key] = 1;

            if (solve(a.substr(0, i), b.substr(n - i)) &&
                solve(a.substr(i), b.substr(0, n - i)))
                return mp[key] = 1;
        }

        return mp[key] = 0;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return 0;
        return solve(s1, s2);
    }
};

