#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;
const long long INF = 1e18;

int GCD(int a, int b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}
long long slow_mult(long long base, long long exp, long long mod = MOD) {
    long long tot = 0;
    for(;exp > 0;exp >>= 1){
       if((exp & 1) == 1) tot = (tot + base) % mod;
       base = base * 2 % mod;
    }
    return tot;
}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s; cin >> s;
    int n = s.size();

    // case 1: a__a
    //         s.size() must be even for p1 to win
    // case 2: a__b
    //         s.size() must be odd
    // case 3: a_(ab)_b
    //         s.size() must be odd

    if(s[0] == s[n - 1]){
        if(n % 2)
            cout << "Second";
        else
            cout << "First";
    } else {
        if(n % 2)
            cout << "First";
        else
            cout << "Second";
    }

    return 0;
}
