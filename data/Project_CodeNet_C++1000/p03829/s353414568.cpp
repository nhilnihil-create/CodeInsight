#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, a, b;
    cin >> n >> a >> b;

    ll x[n];
    rep(i, 0, n){
        cin >> x[i];
    }

    ll sum = 0;
    rep(i, 0, n - 1){
        sum += min(b, (x[i + 1] - x[i]) * a);
    }

    cout << sum << endl;
}
