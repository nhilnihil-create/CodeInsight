#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    ll now = 1;
    for(ll i = 1;i<=N;++i){
        now*=i;
        now%=(ll)(1e9+7);
    }
    cout << now << '\n';
}
