class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>p(101,1);
        p[0] = 0;
        p[1] = 0;
        for(int i=2;i*i<=100;i++)
        {
            if(!p[i]) continue;
            for(int j =i*i;j<=100;j+=i) p[j] = 0;
        }
        int p1 = -1 , p2 = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(p[nums[i]])
            {
                if(p1 == -1) p1 = i;
                p2 = i;
            }
        }
        return p2 - p1;
    }
};