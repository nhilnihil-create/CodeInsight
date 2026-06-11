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
    string S, T;
    cin >> S >> T;
    S = " " + S;
    T = " " + T;
    vector<int> sumS(S.length() + 1), sumT(T.length() + 1);
    for (int i = 1; i < S.length(); i++) {
        if (S[i] == 'A') sumS[i] = sumS[i - 1] + 1;
        else sumS[i] = sumS[i - 1] + 2;
    }
    for (int i = 1; i < T.length(); i++) {
        if (T[i] == 'A') sumT[i] = sumT[i - 1] + 1;
        else sumT[i] = sumT[i - 1] + 2;
    }
    int q;
    cin >> q;
    auto judge = [&](int a, int b, int c, int d) {
        int s = sumS[b] - sumS[a - 1];
        int t = sumT[d] - sumT[c - 1];
        return s % 3 == t % 3;
    };
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (judge(a, b, c, d) ? "YES" : "NO") << endl;
    }
}
