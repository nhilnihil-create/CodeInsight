#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;


int main() {
    ll N;
    cin >> N;
    vector<ll> A;
    for (ll i = 0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }    
    sort(A.begin(),A.end());
    vector<ll> wa(N);
    ll w = 0;
    for (ll i = 0;i<N;i++) {
        w += A.at(i);
        wa.at(i) = w;
    }
    ll cnt = 0;
    bool kieru = false;
    for (ll i = 0;i<N-1;i++) { 
        if (wa.at(i) * 2 < A.at(i+1)) {
            cnt = max(cnt,i);
            kieru = true;
        }
    }
    if (kieru) cout << N -cnt-1 << endl;
    else cout << N << endl;
}