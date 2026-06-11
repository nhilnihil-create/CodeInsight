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
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    int sum = accumulate(A.begin(), A.end(), 0LL);
    int base = N * (N + 1) / 2;
    if (sum % base != 0) {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> dif;
    for (int i = 0; i < N; i++) {
        if (i == 0) dif.push_back(A[i] - A[N - 1]);
        else dif.push_back(A[i] - A[i - 1]);
    }
    int calc = sum / base;
    for (int & i : dif) i -= calc;
    for (auto temp : dif) {
        if (abs(temp) % N != 0 || temp > 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}