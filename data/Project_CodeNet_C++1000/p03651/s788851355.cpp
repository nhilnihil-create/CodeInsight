#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll gcdf(ll a, ll b)
{
    if(a < b) swap(a,b);
    while(a%b){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    ll tmp;
    ll m = 0;
    cin >> tmp;
    m = max(m,tmp);
    for(i = 1;i < n;++i){
        ll a;
        cin >> a;
        m = max(m, a);
        tmp = gcdf(tmp, a);
    }
    if(k > m || k%tmp) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;

    return 0;
}