class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0; int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R') balance++;
            if(s[i] == 'L') balance--;
            if(balance == 0) cnt++;
        }
        return cnt;
    }
};