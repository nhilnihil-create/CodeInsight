#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()


void solve(long long a_I, long long a_O, long long a_T, long long a_J, long long a_L, long long a_S, long long a_Z){
    i64 ans = (a_I / 2 + a_J / 2 + a_L / 2) * 2 + a_O;
    i64 flag = a_I % 2 + a_J % 2 + a_L % 2;
    if(flag == 3) ans += 3;
    else if(a_I % 2 + a_J % 2 == 2 && a_L != 0) ans += 1;
    else if(a_I % 2 + a_L % 2 == 2 && a_J != 0) ans += 1;
    else if(a_L % 2 + a_J % 2 == 2 && a_I != 0) ans += 1;
    cout << ans << endl;
}

struct IoSetup {
    IoSetup() {
        // cin.tie(nullptr);
        // ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

int main(){
    long long a_I;
    scanf("%lld",&a_I);
    long long a_O;
    scanf("%lld",&a_O);
    long long a_T;
    scanf("%lld",&a_T);
    long long a_J;
    scanf("%lld",&a_J);
    long long a_L;
    scanf("%lld",&a_L);
    long long a_S;
    scanf("%lld",&a_S);
    long long a_Z;
    scanf("%lld",&a_Z);
    solve(a_I, a_O, a_T, a_J, a_L, a_S, a_Z);
    return 0;
}
