#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, 0, N) {
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    ll cumsum = 0;
    rrep(i, N, 0) {
        ll cnt = ((A[i] + cumsum + B[i] - 1) / B[i]) * B[i] - A[i] - cumsum;
        ans += cnt;
        cumsum += cnt;
    }
    cout << ans << endl;
    return 0;
}