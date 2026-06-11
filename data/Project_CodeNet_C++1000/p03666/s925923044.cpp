#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    for(i = 0;i <= n-1;++i){
        j = n-1 - i;
        ll tmin = i*c - j*d;
        ll tmax = i*d - j*c;
        if(tmin <= b-a && b-a <= tmax){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}