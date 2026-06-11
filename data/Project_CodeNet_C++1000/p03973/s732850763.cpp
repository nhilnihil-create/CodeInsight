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
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    ll ans = A.front() - 1;
    ll now = 2;
    rep(i, 1, N) {
        if (A[i] == now) {
            ++now;
        }
        if (A[i] % now == 0) {
            A[i] -= now + 1;
            ++ans;
        }
        ans += A[i] / now;
    }
    cout << ans << endl;
    return 0;
}