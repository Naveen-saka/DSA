class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        multiset<int>ms;
        int ans = 0;
        for(int i=0;i<flips.size();i++)
        {
            ms.insert(flips[i]);
            if(*ms.rbegin() == i+1) ans++;
        }
        return ans;
    }
};