class Solution {
public:
    int sumCounts(vector<int>& nums) {
        static __uint128_t seen;
        int n=nums.size(), ans=0;
        for(int l=0; l<n; l++){
            seen=0;
            int cnt=0;
            for(int r=l; r<n; r++){
                int x=nums[r];
                cnt+=((seen>>x)&1)==0; 
                seen|=((__uint128_t)1<<x);
                ans+=cnt*cnt;
            } 
        }
        return ans;
    }
};
