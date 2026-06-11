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
const int MOD = 1e9+ 7;
const int INF = 2e18;

template< typename T >
struct BinaryIndexedTree {
    vector< T > data;

    BinaryIndexedTree(int sz) {
        data.assign(++sz, 0);
    }

    T sum(int k) {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x) {
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};


signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N), explore(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] -= K;
        explore[i] = a[i];
        if (i > 0) explore[i] += explore[i - 1];
    }
    sort(explore.begin(), explore.end());
    map<int, int> eraseIdx;
    for (int i = 0; i < N; i++) eraseIdx[explore[i]] = -1;
    for (int i = 0; i < N; i++) {
        int temp = eraseIdx[explore[i]];
        if (temp == -1) eraseIdx[explore[i]] = i;
    }
    auto removeSum = BinaryIndexedTree<int>(N);
    int ans = 0, sum = 0;
    auto update  = [&]() {
        auto itr = lower_bound(explore.begin(), explore.end(), sum);
        int dist = distance(explore.begin(), itr);
        int minus = removeSum.sum(N - 1);
        if (dist > 0) minus -= removeSum.sum(dist - 1);
        dist = N - dist;
        ans += dist - minus;
    };
    for (int i = 0; i < N; i++) {
        update();
        sum += a[i];
        removeSum.add(eraseIdx[sum], 1);
        eraseIdx[sum]++;
    }
    cout << ans << endl;
}