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
const int INF = 9e18;

signed main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        A[i] = 1 + (i * 20001);
    }
    B[p[0]] = 0;
    for (int i = 1; i < N; i++) {
        int temp = p[i] - p[i - 1];
        temp *= -20001;
        temp++;
        B[p[i]] = B[p[i - 1]] + temp;
    }
    int minValue = *min_element(B.begin(), B.end());
    for (int i = 0; i < N; i++) B[i] += abs(minValue) + 1;
    for (int i = 0; i < N; i++) cout << A[i] << (i == N - 1 ? '\n' : ' ');
    for (int i = 0; i < N; i++) cout << B[i] << (i == N - 1 ? '\n' : ' ');
}
