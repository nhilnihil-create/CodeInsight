#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    ll ans = 0;

    h = min(h, q*2);
    s = min(s, 2*h);

    if(2*s < d){
        ans = n * s;
    }else{
        if(n % 2 == 0){
            ans = n * d / 2;
        }else{
            ans = (n-1) * d / 2+ s;
        }
    }
    cout << ans << endl;

}