class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>>mp;
        sort(reservedSeats.begin(),reservedSeats.end());
        for(auto p:reservedSeats) mp[p[0]].push_back(p[1]);
        int ans = 0;
        for(auto [a,b]:mp)
        {
            vector<int>v = b;
            int c = 0;
            int c2 = binary_search(v.begin(),v.end(),2);
            int c3 = binary_search(v.begin(),v.end(),3);
            int c4 = binary_search(v.begin(),v.end(),4);
            int c5 = binary_search(v.begin(),v.end(),5);
            int c6 = binary_search(v.begin(),v.end(),6);
            int c7 = binary_search(v.begin(),v.end(),7);
            int c8 = binary_search(v.begin(),v.end(),8);
            int c9 = binary_search(v.begin(),v.end(),9);
            // 4 cases
            if((c4||c5) && (c6||c7)) c = 0;
            else if((c4||c5) && !(c6||c7)) 
            {
                if(!c8 && !c9) c = 1;
                else c = 0;
            }
            else if(!(c4||c5) && (c6||c7))
            {
                if(!c2 && !c3) c = 1;
                else c = 0;
            }
            else 
            {
                if(!c2 && !c3 && !c8 && !c9) c = 2;
                else c = 1;
            }
            ans+=c;
        }
        return ans + (n-mp.size())*2;
    }
};