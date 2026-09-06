class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int ans = 1 , gs = speed.back();
        int n = speed.size();
        for(int i=n-2;i>=0;i--)
        {
            if(position[i+1]-position[i]>distance && speed[i]<=gs)
            {
                ans++;
                gs = speed[i];
            }
        }
        return ans;
    }
};