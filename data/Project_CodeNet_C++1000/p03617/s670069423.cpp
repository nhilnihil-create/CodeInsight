#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    ll q,h,s,d,n;
    cin >> q >> h >> s >> d;
    cin >> n;

    ll twol = q * 8;
    twol = min(twol, h * 4);
    twol = min(twol, s * 2);
    twol = min(twol, d);

    ll ans = 0;

    if(n % 2 == 0){
        ans = n / 2 * twol;
    }else{
        ll onel = q * 4;
        onel = min(onel, h * 2);
        onel = min(onel, s);

        ans = n / 2 * twol + onel;
    }

    cout << ans << endl;

    return 0;
}
