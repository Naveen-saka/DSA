class Solution {
public:
    string ans = string(301,'z');
    char chu = '#';
    void go(int i,auto &t,auto &mp,string cur)
    {
         if(i==t.size()/2)
         {
            string c2;
            string lol = cur;
            reverse(lol.begin(),lol.end());
            if(chu!='#')  c2 = cur + chu +  lol;
            else  c2 = cur + lol;
            if(c2>t) ans = min(ans,c2);
            return;
         }
         for(auto &[a,b]:mp)
         {
            if(b == 0 || a<t[i]) continue;
            if(a == t[i] && (b%2 == 0))
            {
                cur+=a;
                b-=2;
                go(i+1,t,mp,cur); 
                cur.pop_back();
                b+=2;
            }
            if(a>t[i])
            {
                cur+=a;
                b-=2;
                string m = cur;
                for(auto &p:mp) if(p.second) m.append(p.second/2,p.first);
                cout<<m;
                string r = m;
                reverse(r.begin(),r.end());
                if(chu!='#') m+=chu;
                m+=r;
                ans = min(ans,m);
                return;
            }
         }
    }
    string lexPalindromicPermutation(string s, string target) {
        map<char,int>mp;
        int o = 0;
        for(char ch:s) mp[ch]++;
        for(auto &[a,b]:mp) 
        {
            o+=(b&1);
        }
        if(o>=2) return "";
        for(auto &[a,b]:mp) 
        {
           if(b&1)
           {
             chu = a;
             b-=1;
           }
        }
        go(0,target,mp,"");
        if(ans == string(301,'z')) return "";
        return ans;
    }
};
