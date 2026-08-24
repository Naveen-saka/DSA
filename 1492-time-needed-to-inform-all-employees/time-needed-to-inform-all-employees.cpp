class Solution {
public:
    int tell(int i,auto &mn,auto &it,auto &v)
    {
        if(v[i].empty()) return 0;
        int maxi = 0;
        int cur = it[i];
        for(int j=0;j<v[i].size();j++)
        {
            cur+=tell(v[i][j],mn,it,v);
            maxi = max(maxi,cur);
            cur = it[i];
        }
        return maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& mn, vector<int>& it) {
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)
        {
            if(i == headID) continue;
            v[mn[i]].push_back(i);
        }
        return tell(headID,mn,it,v);
    }
};