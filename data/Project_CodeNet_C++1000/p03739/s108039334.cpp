#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    llint n;
    cin >> n;

    vector<llint> a(n);
    for(int in=0;in<n;in++) {
        cin >> a.at(in);
    }

    llint sgn, sum, ans1, ans2;

    sgn = 1;
    sum = 0;
    ans1 = 0;
    for(int in=0;in<n;in++) {
        sum += a.at(in);
        if(sum*sgn>0) {
            ;
        }
        else {
            ans1 += abs(sum-sgn);
            sum += sgn*abs(sum-sgn);
        }
        sgn *= -1;  
    }

    sgn = -1;
    sum = 0;
    ans2 = 0;
    for(int in=0;in<n;in++) {
        sum += a.at(in);
        if(sum*sgn>0) {
            ;
        }
        else {
            ans2 += abs(sum-sgn);
            sum += sgn*abs(sum-sgn);
        }
        sgn *= -1;  
    }

    llint ans;
    ans = ans1;
    chmin(ans, ans2);
    cout << ans << endl;
    return 0;
}
