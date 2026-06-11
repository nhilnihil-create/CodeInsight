#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, m;
    cin >> n >> m;

    map<ll, ll> a;
    rep(i, 0, m){
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        a[tmp1]++;
        a[tmp2]++;
    }

    fore(i, a){
        if(i.second % 2 == 1){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
