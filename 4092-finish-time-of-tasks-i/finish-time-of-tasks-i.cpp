class Solution {
    using ll = long long;
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<ll> dp(n, -1);
        vector<vector<ll>> v(n);
        for (auto &i : edges) v[i[0]].push_back(i[1]);

        std::function<ll(int)> lol = [&](int i) -> ll {
            if (v[i].empty()) return dp[i] = 1LL * baseTime[i];
            if (dp[i] != -1) return dp[i];
            ll e = LLONG_MAX, l = LLONG_MIN;
            for (int idx = 0; idx < v[i].size(); idx++) {
                ll ans = lol(v[i][idx]);
                e = min(e, ans);
                l = max(l, ans);
            }
            return dp[i] = 2LL * l - e + baseTime[i];
        };

        return lol(0);
    }
};
