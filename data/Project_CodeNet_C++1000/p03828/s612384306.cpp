#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

bool isPrime(llint n) {
    llint i;

    if (n<2) return false;
    else if (n==2) return true;
    if (n%2==0) return false;
    for(i=3;i*i<=n;i+=2) {
        if(n%i==0) return false;
    }
    return true;
}

vector<pair<llint, llint>> prime_factorize(llint n) {
    vector<pair<llint, llint> > res;
    llint num;

    for(llint p=2;p*p<=n;p++) {
        if (n%p!=0) continue;
        num = 0;
        while (n%p==0) { ++num; n /= p; }
        res.push_back(make_pair(p,num));
    }
    if (n!=1) res.push_back(make_pair(n,1));
    return res;
}

int main(void) {
    llint n;
    cin >> n;

    llint ans = 1;
    vector<pair<llint, llint>> res(1001);
    for(llint in=1;in<=n;in++) {
        auto restmp = prime_factorize(in);
        for(auto irestmp:restmp) {
            res.at(irestmp.first).second += irestmp.second;
        }
    }
    for(auto ires:res) {
        ans *= 1+ires.second;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
