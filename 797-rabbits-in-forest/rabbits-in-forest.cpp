class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(int val: answers){
            if(val ==0) ans++;
            else if(mp.find(val) != mp.end()){
                mp[val]--;
                if(mp[val] == 0) mp.erase(val);
            } 
            else{
                ans += val+1;
                mp[val] += val;
            }
        }
        return ans;
    }
};