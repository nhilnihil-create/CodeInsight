#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int d(ll a){
    ll j;
    rep(i, 27){
        j = 27-i;
        if(a %(1<<j) == 0){
            return j;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    vll a(n);
    ll tot = 0;
    rep(i, n){
        ll x;
        cin >>x;
        a[i] = d(x);
        tot += a[i];       
    }
    sort(ALL(a));
    vi b;
    rep(i, n/2){
        b.eb(a[i]);
        b.eb(a[n-1-i]);
    }
    if(n%2 != 0) b.eb(a[n/2]);
    rep(i, n-1){
        if((b[i]+b[i+1])>=2){
            continue;
        }
        cout << "No" << endl;return 0;
    }
    // int c = n-1;
    // rep(i, n){
    //     if((a[i]+a[i+1])>=2){
    //         continue;
    //     }else{
    //        if(i+1 > n/2)  continue;
    //        swap(a[i+1], a[c--]);
    //        if((a[i]+a[i+1])<2){
    //            cout << "No" << endl;return 0;
    //        }
    //     }
    // }
    cout << "Yes" << endl;
    return 0;
}