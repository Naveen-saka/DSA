class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int maxi = 0;
        int ans = 0;
        for(int i=0;i<flips.size();i++)
        {
            maxi = max(maxi,flips[i]);
            if(maxi == i+1) ans++;
        }
        return ans;
    }
};