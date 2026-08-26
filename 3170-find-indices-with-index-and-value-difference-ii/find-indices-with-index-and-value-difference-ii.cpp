class Solution {
public:
    vector<int> findIndices(vector<int>& v, int id, int vd) {
        multiset<pair<int,int>>ms;
        int l = 0;
        for(int i=0;i<v.size();i++)
        {
            if(i<id) continue;
            ms.insert({v[l],l});
            l++;
            auto l1 = ms.lower_bound({v[i]+vd,INT_MIN});
            auto l2 = ms.lower_bound({v[i]-vd,INT_MIN});
            if(l1!=ms.end()) return {i,l1->second};
            // if(l2!=ms.end()) 
            // {
            //     if((v[i]-l2->first)>=vd) return {i,l2->second};
            //     if(l2 != ms.begin()) 
            //     {
            //         --l2;
            //         if((v[i]-l2->first) >= vd) return {i,l2->second};
            //     }
            // }
            if(ms.begin()->first<=v[i]-vd) return {i,ms.begin()->second};
        }
        return {-1,-1};
    }
};