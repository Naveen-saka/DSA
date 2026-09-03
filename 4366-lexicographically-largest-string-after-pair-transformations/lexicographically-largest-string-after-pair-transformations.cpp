class Solution {
public:

    string tell(int x)
    {
        if(x == 0) return "";
        int k = (int)log2(x);
        if(k > 25) k = 25;
        return string(1,'a'+k) + tell(x-(1<<k));
    }
    vector<string> largestString(vector<int>& nums) {
        // power of n unte maarutundi
        vector<string>ans;
        cout<<log2(67108864);
        for(int &i:nums) ans.push_back(tell(i));
        return ans;
    }
};