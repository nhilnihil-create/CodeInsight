#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

constexpr int MOD = 1000000007;

int mod(const ll &x){
    return x > 0 ? x % MOD : (x+MOD) % MOD;
}

int modm(const ll &x,const ll &m){
    return x * m % MOD;
}

int modpow(ll x, ll p) {
    int ret = 1;
    while(p > 0) {
        if (p & 1) ret = modm(ret,x);
        x = modm(x,x);
        p >>= 1;
    }
    return ret;
}

// x * modinv(d)
int modd(ll x,ll d) {
    return modm(x,modpow(d,MOD-2));
}

int main(void)
{
    IOS
    // const int N = 52;
    int n; cin >> n;
    vector<string> s;
    REP(i,2) {
        string x;
        cin >> x;
        s.push_back(x);
    }

    int ans = 1;
    int x = 0;
    while(x < s[0].size()) {
        int mul = 0;
        if (x == 0) {
            if (s[0][0] == s[1][0]) {
                mul = 3;
                x += 1;
            }
            else {
                mul = 6;
                x += 2;
            }
        } else {
            if (s[0][x] == s[1][x]) {
                // tate
                if (s[0][x-1] == s[1][x-1]) mul = 2;
                else mul = 1;
                x += 1;
            } else {
                // yoko
                if (s[0][x-1] == s[1][x-1]) mul = 2;
                else mul = 3;
                x += 2;
            }
        }

        //cerr << s[y][x] << " " << mul << endl;
        ans = modm(ans,mul);
        //cerr << ans << endl;
    }

    cout << ans << endl;

    return 0;
}