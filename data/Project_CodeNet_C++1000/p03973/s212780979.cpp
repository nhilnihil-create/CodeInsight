#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 998244353;
const int INF = 2e18;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    int ans = (A[1] - 1), maxValue = 2;
    for (int i = 2; i <= N; i++) {
        if (maxValue == A[i]) {
            maxValue++;
        } else if (maxValue * 2 - 1 > A[i]) {
            ans += (A[i] > maxValue);
        } else {
            ans += (A[i] - 1) / maxValue;
        }
    }
    cout << ans << endl;
}
