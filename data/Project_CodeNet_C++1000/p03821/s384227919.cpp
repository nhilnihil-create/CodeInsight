#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template<typename T> void print(const T & v);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    ll cnt = 0;
    for(int i = N - 1; i >= 0; i--){
        a[i] += cnt;
        if(a[i] % b[i] != 0){
            cnt += b[i] - (a[i] % b[i]);
        }
    }
    cout << cnt << endl;
    return 0;
}


// Use For Debug
template <typename T>
void print(T const & v){
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
