class Solution {
public:
    string ans = string(301,'z');
    void go(int i,auto &t,auto &mp,string cur)
    {
         if(i==t.size())
         {
            if(cur>t) ans = min(ans,cur);
            return;
         }
         for(auto &[a,b]:mp)
         {
            if(b == 0 || a<t[i]) continue;
            if(a == t[i])
            {
                cur+=a;
                b--;
                go(i+1,t,mp,cur); 
                cur.pop_back();
                b++;
            }
            if(a>t[i])
            {
                cur+=a;
                b--;
                string m = cur;
                for(auto &p:mp) m.append(p.second,p.first);
                ans = min(ans,m);
                return;
                cur.pop_back();
                b++;
            }
         }
    }
    string lexGreaterPermutation(string s, string target) {
        map<char,int>mp;
        for(char ch:s) mp[ch]++;
        go(0,target,mp,"");
        if(ans == string(301,'z')) return "";
        return ans;
    }
};