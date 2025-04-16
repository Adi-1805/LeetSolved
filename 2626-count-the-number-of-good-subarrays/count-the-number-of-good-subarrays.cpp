class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int pairs = 0, l = 0, r = -1;
        long long ans = 0;
        while(l < n){
            while(pairs<k and r < n-1){
                r++;
                pairs += mp[nums[r]];
                mp[nums[r]]++;
            }
            if(pairs >= k){
                ans += n -r;
            }
            mp[nums[l]]--;
            pairs -= mp[nums[l]];
            l++;
        }
        return ans;
    }
};