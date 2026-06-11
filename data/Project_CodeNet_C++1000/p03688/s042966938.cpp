#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, N) for (int i = 0; i < (N); i++)
#define REP(i, a, N) for (int i = a; i < (N); i++)
#define rrep(i, N, k) for (int i = (N); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - (int)1e8;
const ll INFLL = numeric_limits<ll>::max() - (ll)1e17;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> count;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        count[A[i]]++;
    }
    bool check = true;
    if (count.size() >= 3) check = false;
    if (count.size() == 2) {
        if (count.rbegin()->first - count.begin()->first > 1) check = false;
        if (count.rbegin()->first < N / 2) check = false;
        if (count.begin()->second != N - (N - count.rbegin()->first) * 2) check = false;
    }
    if (count.size() == 1 && (count.begin()->first > N / 2 && count.begin()->first != N - 1)) check = false;
    cout <<(check ? "Yes" : "No") << endl;
    return 0;
}