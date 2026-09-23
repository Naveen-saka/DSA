class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        auto &v = nums;
        int n = v.size();
        vector<int>pre(n,0);
        pre[0] = v[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + v[i];
        int ans = INT_MAX;
        int sum = 0;
        auto it = binary_search(pre.begin(),pre.end(),x);
        if(it)
        {
            int idx = lower_bound(pre.begin(),pre.end(),x) - pre.begin();
            ans = min(ans,idx + 1);
        }
        for(int i=n-1;i>=0;i--)
        {
            sum+=v[i];
            if(sum == x) ans = min(ans,n-i);
            else if(sum > x) break;
            else
            {
                auto it = binary_search(pre.begin(),pre.begin()+i,x - sum);
                if(it)
                {
                    int idx = lower_bound(pre.begin(),pre.begin()+i,x - sum) - pre.begin();
                    ans = min(ans,n - i + idx + 1);
                } 
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};