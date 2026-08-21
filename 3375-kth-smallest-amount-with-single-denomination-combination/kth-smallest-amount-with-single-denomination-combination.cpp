class Solution {
public:
    using ll = long long;
    ll gcd(ll a, ll b) 
    {
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    ll lcm(ll a,ll b)
    {
        return (a*b)/(gcd(a,b));
    } 
    long long findKthSmallest(vector<int>& coins, int k) {
        ll n = coins.size();
        auto &v = coins;
        if(n == 1LL) return 1LL*k*v.back();
        auto lol = [&](ll num)
        {
           ll p = 0;
           //if odd size --> add;
           //if even size --> subact
           for(ll i = 1LL;i<(1LL<<n);i++)
           {
               ll m = 1LL;
               ll pp = __builtin_popcount(i);
               if(!(pp&1)) m = -1LL;
               ll lc = 0;
               for(int j=0;j<n;j++)
               {
                  if((i>>j)&1LL) 
                  {
                     if(lc == 0) lc = v[j];
                     else lc = lcm(lc,v[j]);
                  }
               }
               p+=(m*(num/lc));
           }
           return p;
        };
        
        auto tell = [&](ll val)
        {
            ll l = 1 , r = k;
            while(l<=r)
            {
                ll mid = l+(r-l)/2;
                //count the number of elements
                ll ans = lol(mid*val);
                if(ans == k) return mid*val;
                if(ans<=k) l = mid + 1;
                else r = mid - 1;
            }
            return -1LL;
        };
        for(int i:v)
        {
            ll ans = tell(i);
            cout<<tell(i)<<" ";
            if(ans!=-1) return ans;
        }
        return 1LL; //intha varaku raadu....
    }
};