class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0;
        auto &v = nums;
        int n = v.size();
        vector<int>nm(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && v[st.top()]>=v[i]) st.pop();
            if(!st.empty()) nm[i] = st.top();
            st.push(i);
        }
        // for(int i:nm) cout<<i<<" ";
        cout<<"\n";
        map<int,vector<int>>mp;
        for(int i=0;i<v.size();i++) mp[v[i]].push_back(i);
        for(int i=0;i<n;i++)
        {
            int cur = nm[i] - i - 1;
            // if(nm[i] == n) cur--;
            auto &p = mp[v[i]];
            auto r = lower_bound(p.begin(),p.end(),nm[i]) - p.begin();
            // if(r!=0) r--;
            auto l = upper_bound(p.begin(),p.end(),i) - p.begin();
            // cout<<cur-(r-l+1)<<"\n";
            ans+=cur-(r-l);
        }
        return ans;
    }
};