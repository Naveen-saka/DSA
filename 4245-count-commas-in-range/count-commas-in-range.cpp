class Solution {
public:
    int countCommas(int n) {
        int d = 0 , p = n;
        while(p)
        {
            d++;
            p/=10;
        }
        int ans = 0;
        for(int i=4;i<d;i++)
        {
            int digi = i;
            int val = 9*(int)pow(10,digi-1);
            ans+=val;
        }
        if(d>=4) ans+=(n-(int)pow(10,d-1)+1);
        return ans;
    }
};