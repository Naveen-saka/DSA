class Solution {
public:
    using ll = long long;
    int countGoodRotations(vector<int>& nums) {
        auto &v = nums;
        ll n = v.size();
        ll ans = 0 , sl = 0 , sr = 0;
        for(ll i=0;i<n/2;i++) sl+=(v[i]);
        for(ll i=n/2;i<n;i++) sr+=(v[i]);
        ll l = 0 , r = n/2;
        ans+=(sl>sr);
        ll p = n;
        p--;
        while(p--)
        {
            sl+=(v[r]-v[l]);
            sr+=(v[l]-v[r]);
            ans+=(sl>sr);
            cout<<sl<<" "<<sr<<"\n";
            l = (l+1)%n;
            r = (r+1)%n;
        }
        return ans;
    }
};