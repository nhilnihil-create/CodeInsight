#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> a(n), b;
    rep(i,n) cin >> a[i];
    if(n%2){
        ll tmp = n-1;
        while(tmp>=0){
            b.push_back(a[tmp]);
            tmp -= 2;
        }
        ll tmp2 = 1;
        while(tmp2<=n-2){
            b.push_back(a[tmp2]);
            tmp2 += 2;
        }
    }else{
        ll tmp = n-1;
        while(tmp>=1){
            b.push_back(a[tmp]);
            tmp -= 2;
        }
        ll tmp2 = 0;
        while(tmp2<=n-2){
            b.push_back(a[tmp2]);
            tmp2 += 2;
        }
    }
    rep(i,n){
        cout << b[i];
        if(i != n-1) cout << ' ';
        else cout << endl;
    }
    return 0;
}