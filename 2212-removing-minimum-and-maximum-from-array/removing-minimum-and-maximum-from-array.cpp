class Solution {
public:
    int minimumDeletions(vector<int>& v) {
        int mini = min_element(v.begin(),v.end())-v.begin();
        int maxi = max_element(v.begin(),v.end())-v.begin();
        int n = v.size();
        return min({max(mini+1,maxi+1),n - min(mini, maxi),min(mini + 1 + (n - maxi), maxi + 1 + (n - mini))});
    }
};