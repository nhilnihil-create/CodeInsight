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
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    int left = A - D, right = A + D;
    int ok = D - C + 1, ng = C * 2 - 1;
    int base = D - C;
    for (int i = 1; i < N - 1; i++) {
        left -= D;
        right += D;
        ok += base;
        ng -= base;
    }
    if (left <= B && B <= right) {
        if (ng <= 0) {
            cout << "YES" << endl;
            return 0;
        }
        int ans = (B - left) % (ok + ng);
        cout << (ans < ok ? "YES" : "NO") << endl;
    } else {
        cout << "NO" << endl;
    }
}