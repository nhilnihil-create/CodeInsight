#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    ll ans = abs(a - b);
    rep(i, 0, n){
        ll s = (d * (-n + 1 + i)) + (i * c);
        ll e = (c * (-n + 1 + i)) + (i * d);
        if(s <= ans && ans <= e){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
