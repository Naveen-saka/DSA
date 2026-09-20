class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        long long ans = 0;

        vector<pair<int,int>> v;

        for(auto& t : intervals){
            v.push_back({t[0],1});
            v.push_back({t[1],-1});
        }

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
        if (a.first != b.first)
            return a.first < b.first;

        return a.second > b.second;
       });
        long long count = 0;

        for(auto& p : v){
            if(p.second == -1){
                count--;
                ans += count;
            }else{
                count++;
            }
        }
        return ans;
    }
};