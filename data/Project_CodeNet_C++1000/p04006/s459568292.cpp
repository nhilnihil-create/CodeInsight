#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()


const i64 inf = 1e18;

void solve(long long N, long long x, std::vector<long long> a){
    vector<vector<i64>> table(N, vector<i64>(N, inf));
    rep(i, N){
        rep(j, N){
            if(j != 0) table[i][j] = min(table[i][j - 1], a[(i - j + N) % N]);
            else table[i][j] = a[i];
        }
    }
    i64 ans = inf;
    rep(i, N){
        i64 tmp = x * i;
        rep(j, N) tmp += table[j][i];
        ans = min(ans, tmp);
    }
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
    long long N;
    scanf("%lld",&N);
    long long x;
    scanf("%lld",&x);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, x, std::move(a));
    return 0;
}
