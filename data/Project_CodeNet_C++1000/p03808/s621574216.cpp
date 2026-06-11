#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;
    ll sum = 0;
    ll div = n*(n+1)/2;
    vector<ll> a(n); rep(i,n) cin >> a[i], sum += a[i];
    if(sum%div != 0){ cout << "NO" << endl; return 0; }
    ll num = sum / div;
    ll count = 0;
    rep(i,n){
        ll k = a[(i+1)%n] - a[i];
        k -= num;
        k *= -1;
        if(k < 0 || k%n != 0){ cout << "NO" << endl; return 0; }
        count += k/n;
    }
    cout << (num == count ? "YES" : "NO") << endl;
}