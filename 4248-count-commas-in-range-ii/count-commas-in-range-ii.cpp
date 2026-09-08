class Solution {
    using ll = long long;
public:
    ll countCommas(ll n) {
        ll ans = 0;
        vector<ll> comma = {0,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5};
        for(ll d = 1;d<=min(16LL,(ll)log10((long double)n)+1);d++)
        {
            ll l = (ll)pow(10,d-1);
            ll r = (ll)min(n,(ll)pow(10,d)-1);
            ll c = r - l + 1;
            ans+=(c*comma[d]);
        }
        return ans;
    }
};