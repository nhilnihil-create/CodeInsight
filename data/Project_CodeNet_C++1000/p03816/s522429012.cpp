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

    map<ll, ll> a;
    rep(i, 0, n){
        ll tmp;
        cin >> tmp;
        a[tmp]++;
    }

    ll sum = 0;
    ll d = 0;
    fore(t, a){
        if(t.second > 1){
            d += t.second - 1;
        }
        sum++;
    }
    if(d % 2 == 0){
        cout << sum << endl;
    }else{
        cout << sum - 1 << endl;
    }

    return 0;
}
