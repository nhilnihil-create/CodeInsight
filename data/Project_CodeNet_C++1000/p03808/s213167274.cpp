#include<iostream>
#include<vector>
#include<string>
#include<numeric>
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    ll sum = accumulate(all(A), 0LL);
    ll removed = N * (N + 1) / 2;
    if (sum % removed) {
        cout << "NO" << endl;
        return 0;
    }
    ll k = sum / removed;
    ll cnt = 0;
    rep(i, 0, N) {
        ll diff = A[(i + 1) % N] - A[i] - k;
        if (diff < 0) {
            if (diff % N) {
                cout << "NO" << endl;
                return 0;
            }
            else {
                cnt -= diff / N;
            }
        }
        else if (diff > 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (cnt == k) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}