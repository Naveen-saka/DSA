class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int prev1 = nums[0];
        int prev2 = nums[1];
        nums[1]*=(-1);
        for(int i=2;i<nums.size();i++)
        {
            int val = nums[i];
            if(prev2 < prev1)
            {
                prev1 = val;
            }
            else
            {
                prev2 = val;
                nums[i]*=(-1);
            }
        }
        vector<int>ans;
        for(int i:nums)
        {
            if(i>0) ans.push_back(i);
        }
        for(int i:nums)
        {
            if(i<0) ans.push_back(-i);
        }
        return ans;
    }
};