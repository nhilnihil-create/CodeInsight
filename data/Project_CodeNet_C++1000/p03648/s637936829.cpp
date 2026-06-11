#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<typename U, typename V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

int main() {
    ll K; cin >> K;
    ll q = K / 50, r = K % 50;
    int N = 50;
    vector<ll> A(N);
    rep(i, N) {
        A[i] = q + N - 1;
    }
    rep(i, N) {
        if(i < r) A[i] += N - r + 1;
        else A[i] -= r;
    }
    cout << N << "\n";
    rep(i, N) cout << A[i] << " ";
    cout << "\n";
}