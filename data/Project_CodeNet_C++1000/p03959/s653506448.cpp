#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n;
    cin >> n;
    vi a(n+1, 0), t(n+1, 0), mHeight(n, 0);
    repf(i, n) cin >> t[i];
    rep(i, n)  cin >> a[i];

    repf(i, n){
        if(t[i] == t[i-1]) continue;
        mHeight[i-1] = t[i];
        if(a[i-1] < t[i]){
            cout << 0 << endl;
            return 0;
        }
    }

    for(ll i=n-1; i>=0; i--){
        if(a[i] == a[i+1]) continue;
        if(mHeight[i] == 0){
            mHeight[i] = a[i];
            if(t[i+1] < a[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        else if(mHeight[i] != a[i]){
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1;
    rep(i, n){
        if(mHeight[i] == 0){
            ans *= min(t[i+1], a[i]);
            ans %= MODV;
        }
    }
    cout << ans << endl;
}