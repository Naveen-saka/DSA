class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        vector<int>o,e;
        for(int i:nums)
        {
            if(i&1) o.push_back(i);
            else e.push_back(i);
        }
        if(o.empty() || e.empty()) return 1;
        sort(o.begin(),o.end());
        sort(e.begin(),e.end());
        int fo = 1 , fe = 1;
        // for odd
        for(int i:nums)
        {
            if(!(i&1))
            {
                if(o[0]>=i) 
                {
                    fo = 0;
                    break;
                }
            }
        }
        // for even
        for(int i:nums)
        {
            if((i&1))
            {
                if(o[0]>=i) 
                {
                    fe = 0;
                    break;
                }
            }
        }
        return fe | fo;
    }
};