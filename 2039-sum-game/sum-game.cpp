class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int lsum = 0 , rsum  = 0;
        int lc = 0 , rc = 0;
        for(int i=0;i<n/2;i++)
        {
            if(num[i] == '?') lc++;
            else lsum+=(num[i]-'0');
        }
        for(int i=n/2;i<n;i++)
        {
            if(num[i] == '?') rc++;
            else rsum+=(num[i] - '0');
        }
        if((lc+rc)&1) return 1;
        if(lsum == rsum) return lc != rc;
        int diff = (lsum-rsum);
        int ac = (rc-lc)/2;
        return (9*ac)!=diff;
    }
};