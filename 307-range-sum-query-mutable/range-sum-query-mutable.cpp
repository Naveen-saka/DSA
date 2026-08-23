class NumArray {
public:
    vector<int>sg,v;
    int go(int i,int l,int r)
    {
        if(l == r) return sg[i] = v[l];
        int mid = l+(r-l)/2;
        int ls = go(2*i+1,l,mid);
        int rs = go(2*i+2,mid+1,r);
        return sg[i] = ls + rs;
    }
    
    int up(int i,int l,int r,int idx,int val)
    {
        if(l == r) return sg[i] = val;
        int mid = l+(r-l)/2;
        int lol = 0;
        if(idx<=mid) lol = up(2*i+1,l,mid,idx,val);
        else lol = up(2*i+2,mid+1,r,idx,val);
        return sg[i] = sg[2*i+1] + sg[2*i+2];
    }

    int tell(int i,int l,int r,int lft,int rgt)
    {
        if(lft > r || rgt < l) return 0;
        if(lft<=l && r<=rgt) return sg[i];
        int mid = l+(r-l)/2;
        return tell(2*i+1,l,mid,lft,rgt) + tell(2*i+2,mid+1,r,lft,rgt);
    }
    NumArray(vector<int>& nums) {
        v = nums;
        sg.assign(4 * nums.size(), 0);
        go(0,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        up(0,0,v.size()-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return tell(0,0,v.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */