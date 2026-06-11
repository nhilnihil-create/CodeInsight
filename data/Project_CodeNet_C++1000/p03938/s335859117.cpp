#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;

    ll p[n];
    ll c[n];

    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
        c[p[i]] = i + 1;
    }

    ll a[n];
    ll b[n];

    rep(i, 0, n){
        a[i] = (i + 1) * 30000 + c[i];
        b[n - 1 - i] = (i + 1) * 30000;

    }

    rep(i, 0, n){
        cout << a[i] << " ";
    }
    cout << endl;

    rep(i, 0, n){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
