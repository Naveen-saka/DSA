class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 , p = 1;
        int k = n;
        while(n)
        {
            sum+=(n%10);
            p*=(n%10);
            n/=10;
        }
        return !(k%(sum+p));
    }
};