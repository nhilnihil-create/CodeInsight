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
const int MOD = 1e9 + 7;
const int INF = 2e18;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    cin >> a;
    vector<int> countLeft(N, 0), countRight(N, 0);
    countLeft[0] = max(0LL, a[0]); countRight[N - 1] = max(0LL, a[N - 1]);
    for (int i = 1; i < N; i++) {
        if (a[i] > 0) countLeft[i] = countLeft[i - 1] + a[i];
        else countLeft[i] = countLeft[i - 1];
    }
    for (int i = N - 2; i >= 0; i--) {
        if (a[i] > 0) countRight[i] = countRight[i + 1] + a[i];
        else countRight[i] = countRight[i + 1];
    }
    vector<int> sum(N + 1, 0);
    int ans = 0;
    for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + a[i - 1];
    for (int i = 0; i + K - 1 < N; i++) {
        int temp = 0;
        if (i != 0) temp += countLeft[i - 1];
        if (i + K - 1 != N - 1) temp += countRight[i + K];
        temp += max(0LL, sum[i + K] - sum[i]);
        ans = max(ans, temp);
    }
    cout << ans << endl;
}