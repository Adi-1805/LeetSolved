class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0; int j = n;
        int k = 0;
        bool flag = 1;
        vector<int> arr(2*n, 0);
        while(i < n and j < 2*n){
            if(flag){
                arr[k++] = nums[i++];
                flag = 0;
            }
            else{
                arr[k++] = nums[j++];
                flag = 1;
            }
        }
        arr[2*n-1] = nums[2*n-1];
        return arr;
    }
};