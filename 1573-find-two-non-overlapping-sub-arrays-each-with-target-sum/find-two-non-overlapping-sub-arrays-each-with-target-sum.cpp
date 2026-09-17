class Solution {
public:
    int find_dec(vector<int>& v, int l, int r, int x) {
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (v[m] == x)
                return m;
            if (v[m] > x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = 0;

        vector<int> pre(n, 0), prei(n, INT_MAX);
        vector<int> suf(n, 0), sufi(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            pre[i] = sum;
        }

        for (int i = 0; i < n; i++) {
            if (pre[i] == target) {
                prei[i] = i + 1;
            } else {
                auto it =
                    lower_bound(pre.begin(), pre.begin() + i, pre[i] - target);

                if (it != pre.begin() + i && *it == pre[i] - target) {
                    int idx = it - pre.begin();
                    prei[i] = i - idx;
                }
            }

            if (i > 0)
                prei[i] = min(prei[i], prei[i - 1]);
        }

        sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            suf[i] = sum;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (suf[i] == target) {
                sufi[i] = n - i;
            } else {
                int idx = find_dec(suf, i, n - 1, suf[i] - target);

                if (idx != -1)
                    sufi[i] = idx - i;
            }

            if (i + 1 < n)
                sufi[i] = min(sufi[i], sufi[i + 1]);
        }

        int ans = INT_MAX;

        for (int i = 0; i + 1 < n; i++) {
            if (prei[i] != INT_MAX && sufi[i + 1] != INT_MAX)
                ans = min(ans, prei[i] + sufi[i + 1]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};