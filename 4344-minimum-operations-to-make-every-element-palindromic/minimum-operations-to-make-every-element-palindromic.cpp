using ll = long long;
static vector<ll>pre[2];
int init = []()
{
        for(int i=1;i<=100000;i++)
        {
        string cur = to_string(i);
        string lol = cur;
        reverse(lol.begin(),lol.end());
        string oddlen = cur.substr(0,cur.size()-1) + lol;
        string evenlen = cur + lol;
        ll v1 = stoll(oddlen);
        ll v2 = stoll(evenlen); 
        if(v1 < 1e9 ) pre[v1&1].push_back(v1);
        if(v2 < 1e9 ) pre[v2&1].push_back(v2);
        }
    sort(pre[0].begin(),pre[0].end());
    sort(pre[1].begin(),pre[1].end());
    return 0;
}();
class Solution {
public:
    
    long long minOperations(vector<int>& nums) {
        ll ans = 0;
        for(int i:nums)
        {
            auto it = lower_bound(pre[i&1].begin(),pre[i&1].end(),i);
            ll best = LLONG_MAX;
            if(it!=pre[i&1].end()) best = min(best,(*it-i)/2);
            if(it!=pre[i&1].begin()) --it;
            best = min(best,(i-*it)/2);
            ans+=best;
        }
        return ans;
    }
};