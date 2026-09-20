class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            int val = s[i] - 'a' + 1;
            ans+=((i+1)*(27-val));
        }
        return ans;
    }
};