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
const int inf = 2e17;
const int mod = 1e9 + 7;

signed main() {
    int N;
    cin >> N;
    vi T(N), A(N);
    cin >> T >> A;
    vector<bool> checkT(N, false), checkA(N, false);
    checkT[0] = true;
    for (int i = 1; i < N; i++) if (T[i - 1] != T[i]) checkT[i] = true;
    checkA[N - 1] = true;
    for (int i = N - 2; i >= 0; i--) if (A[i] != A[i + 1]) checkA[i] = true;
    int ans = 1;
    for (int i = 0; i < N; i++) {
        if ((checkT[i] && T[i] > A[i]) || (checkA[i] && A[i] > T[i])) {
            cout << 0 << endl;
            return 0;
        }
        if (!(checkA[i] || checkT[i])) ans = (ans * min(T[i], A[i])) % mod;
    }
    cout << ans << endl;
}