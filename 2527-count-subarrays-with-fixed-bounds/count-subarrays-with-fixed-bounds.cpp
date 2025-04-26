class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int ans = 0;
        int minL = -1, maxL = -1;
        int start = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == minK) minL = i;
            if(nums[i] == maxK) maxL = i;
            if(nums[i] < minK or nums[i] > maxK) start = i;
            if(minL != -1 and maxL != -1) ans += max(0, min(minL,maxL)-start);
        }
        return ans;
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i; j < nums.size(); j++){
        //         minL = *min_element(nums.begin()+i,nums.end()-nums.size()+j);
        //         maxL = *max_element(nums.begin()+i,nums.end()-nums.size()+j);
        //         if(maxL == maxK and minL == minK) ans++;
        //     }
        // }
    }
};