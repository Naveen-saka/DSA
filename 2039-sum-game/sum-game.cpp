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
        if(lc > rc)
        {
            int ac = (lc-rc)/2;
            int sum = rsum - lsum;
            if(sum<0) return 1;
            return 9*ac != sum;
        }
        int ac = (rc-lc)/2;
        int sum = lsum - rsum;
        if(sum<0) return 1;
        return 9*ac != sum;
    }
};