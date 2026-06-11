#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

LL f(int x1, int x2) {
    if(x1 == 1 && x2 == 1) {
        return 2;
    }else if(x1 == 1 && x2 == 2){
        return 2;
    }else if(x1 == 2 && x2 == 1){
        return 1;
    }else{
        return 3;
    }
}

int main() {
    int N;
    string s1, s2;
    cin >> N;
    cin >> s1;
    cin >> s2;
    vector<int> x;
    REP(i, N) {
        if(s1[i] == s2[i]) {
            x.push_back(1);
        }
        if(s1[i] != s2[i]) {
            x.push_back(2);
            i++;
        }
    }
    vector<LL> dp(x.size());
    dp[0] = x[0] == 1 ? 3 : 6;
    FOR(i, 1, x.size()) {
        dp[i] = (dp[i - 1]*f(x[i - 1], x[i]))%mod;
    }
    cout << dp[x.size() - 1] << endl;
    return 0;
}

