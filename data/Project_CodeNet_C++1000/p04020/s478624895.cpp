#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()


void solve(long long N, std::vector<long long> A){
    i64 ans = 0;
    rep(i, N){
        ans += A[i] / 2;
        A[i] %= 2;
        if(A[i] == 1){
            if(i != 0 && A[i - 1] == 1){
                A[i] = A[i - 1] = 0;
                ans++;
            }else if(i != N - 1 && A[i + 1] != 0){
                A[i] = 0;
                A[i + 1]--;
                ans++;
            }
        }
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
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
