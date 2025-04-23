class Solution {
    int calcDigitSum(int n){
        int sum = 0; int i = 0;
        while(n){
            int digit = n%10;
            sum += digit;
            n/=10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        vector<int> sums(37);
        for(int i = 1; i <= n; i++) sums[calcDigitSum(i)]++;

        int maxi = *max_element(sums.begin(), sums.end());
        int ans = 0;
        for(int val: sums) if(val==maxi) ans++;
        
        return ans;
    }
};