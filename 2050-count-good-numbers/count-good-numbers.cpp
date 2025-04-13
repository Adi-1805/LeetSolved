class Solution {
    const int M = 1e9+7;
    long long binExpRecur(long long int a, long long int b){
        if(b==0) return 1;
        long long res = binExpRecur(a,b/2);
        if(b&1) return (a*((1LL*res*res)%M)%M);
        return (1LL*res*res)%M;
    }
public:
    int countGoodNumbers(long long n) {
        long long ans = 0;
        if(n&1) return int(binExpRecur(5, (n/2+1))*binExpRecur(4,n/2) % M);
        return int(binExpRecur(5,n/2)*binExpRecur(4,n/2) % M);
    }
};