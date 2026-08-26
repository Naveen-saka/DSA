class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;
        multiset<int>ms;
        auto &v = nums;
        int l = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i<x) continue;
            // ms.insert(nums[i]);
            ms.insert(v[l]);
            l++;
            auto it2 = ms.lower_bound(v[i]);
            if(it2!=ms.end()) ans = min(ans,(*it2-v[i]));
            if(it2!=ms.begin())
            {
               it2--;
               ans = min(ans,abs(*it2-v[i]));
            }
        }
        return ans;
    }
};