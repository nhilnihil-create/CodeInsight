#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()


void solve(long long n, std::vector<long long> a){
    i64 wa = 0, tmp = 0;
    rep(i, n){
        wa += a[i];
        if(i % 2 == 0){
            if(wa <= 0){
                tmp += 1 - wa;
                wa = 1;
            }
        }else{
            if(wa >= 0){
                tmp += wa + 1;
                wa = -1;
            }
        }
    }
    i64 ans = tmp;
    wa = 0; tmp = 0;
    rep(i, n){
        wa += a[i];
        if(i % 2 == 1){
            if(wa <= 0){
                tmp += 1 - wa;
                wa = 1;
            }
        }else{
            if(wa >= 0){
                tmp += wa + 1;
                wa = -1;
            }
        }
    }
    cout << min(tmp, ans) << endl;
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
    long long n;
    scanf("%lld",&n);
    std::vector<long long> a(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&a[i]);
    }
    solve(n, std::move(a));
    return 0;
}
