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
    int N, M;
    cin >> N >> M;
    map<int, int> count, check;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        count[X % M]++;
        check[X]++;
    }
    map<int, int> oddCount;
    for (auto temp : check) {
        if (temp.second % 2 == 1) oddCount[temp.first % M]++;
    }
    int ans = count[0] / 2;
    if (M % 2 == 0) {
        ans += count[M / 2] / 2;
        count[M / 2] = 0;
        oddCount[M / 2] = 0;
    }
    for (int i = 1; i <= M / 2 - (M % 2 == 0); i++) {
        int minus = min(count[i], count[M - i]);
        count[i] -= minus;
        oddCount[i] -= minus;
        count[M - i] -= minus;
        oddCount[M - i] -= minus;
        ans += minus;
    }
    for (int i = 1; i <= 1e5; i++) {
        ans += (count[i] - max(0LL, oddCount[i])) / 2;
    }
    cout << ans << endl;
}
