class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>v = nums;
        for(int i:nums) v.push_back(i);
        int ans = 0;
        int c1 = count(nums.begin(),nums.end(),1);
        int l = 0 , sum = 0;
        //0 1 0 1 1 0 0 0 1 0 1 1 0 0 
        for(int r=0;r<v.size();r++)
        {
            sum+=v[r];
            if(r-l+1 == c1)
            {
                ans = max(ans,sum);
                sum-=v[l++];
            }
        }
        return c1 - ans;
    }
};