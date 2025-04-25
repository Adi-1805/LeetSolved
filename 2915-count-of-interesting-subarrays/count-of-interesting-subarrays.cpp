#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& a, int m, int k) {
        long long res = 0;
        long long count = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;

        for (int x : a) {
            count += (x % m == k);
            int modVal = (count - k) % m;
            if (modVal < 0) modVal += m;
            res += freq[modVal];
            freq[count % m]++;
        }

        return res;
    }
};
