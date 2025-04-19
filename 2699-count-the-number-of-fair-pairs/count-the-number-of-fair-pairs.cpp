class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper){
        sort(nums.begin(), nums.end());
        long long count = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            int minReq = lower - nums[i], maxReq = upper - nums[i];
            auto r = upper_bound(nums.begin() + i + 1, nums.end(), maxReq);
            auto l = lower_bound(nums.begin() + i + 1, nums.end(), minReq);
            count += (r - l);
        }
        return count;
    }
};