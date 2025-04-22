class Solution
{
    static const int N = 1e4 + 1;
    vector<int> factors[N];
    void preCompute(){
        for(int i = 1; i < N; i++)
            for(int j = 2*i; j < N; j += i) factors[j].push_back(i);
    }

    int M = 1e9 + 7;
    vector<int> fact;
    vector<int> ifact;

    int poW(int base, int power){
        if(power == 0)
            return 1;
        if(power == 1)
            return base;
        int res = poW(base, power / 2);
        if(power % 2)
            return (1LL*res*res % M*base) % M;
        return (1LL*res*res) % M;
    }

    void solve(){
        fact.resize(N);
        ifact.resize(N);
        fact[0] = 1;
        for(int i = 1; i < N; i++) fact[i] = (1LL*fact[i - 1]*i) % M;
        ifact[N - 1] = poW(fact[N - 1], M - 2);
        for(int i = N - 2; i >= 0; i--) ifact[i] = (1LL*(i + 1)*ifact[i + 1]) % M;
    }

    int ncr(int n, int r){
        if(r < 0 || r > n) return 0;
        int res = (1LL*fact[n]*ifact[n - r]) % M;
        res = (1LL*res*ifact[r]) % M;
        return res;
    }

public:
    int idealArrays(int n, int maxValue){
        preCompute();
        solve();
        int sz = log2(maxValue) + 2;
        vector<vector<int>> dp(maxValue + 1, vector<int>(sz + 1));

        for(int i = 1; i <= maxValue; i++) dp[i][1] = 1;
        for(int i = 2; i <= maxValue; i++){
            for(int j = 1; j <= sz; j++){
                for(auto k : factors[i]) dp[i][j] += dp[k][j - 1];
            }
        }

        int ans = 0;
        for(int i = 1; i <= maxValue; i++){
            for(int j = 1; j <= sz; j++){
                int combo = ncr(n - 1, j - 1) % M;
                int ways = dp[i][j];
                ans = (1LL*ans + 1LL*combo*ways) % M;
            }
        }
        return ans;
    }
};