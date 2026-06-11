#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

ld comb(ll s, ll t){
    ll a = 1, b = 1;
    ld ans = 1;
    rep(i, 0, t){
        a = s - i;
        b = t - i;
        ans *= ld(a) / ld(b);
    }
    return ans;
}

int main(void){
    ll n, a, b;
    cin >> n >> a >> b;

    ll x[n];
    rep(i, 0, n){
        cin >> x[i];
    }

    sort(x, x + n, greater<ll>());

    ld ave;
    ll sum = 0;

    rep(i, 0, a){
        sum += x[i];
    }

    ave = sum / double(a);

    ll num = 0;
    ll f = 0;
    rep(i, 0, a){
        if(x[i] == x[a - 1]){
            f = i;
            break;
        }
    }
    rep(i, f, n){
        if(x[i] == x[a - 1]){
            num++;
        }
    }

    ld ans = 0;
    if(f == 0){
        rep(i, a, min(num, b) + 1){
            ans += comb(num, i);
        }

    }else{
        ans = comb(num, a - f);
    }

    printf("%.9Lf\n", ave);
    printf("%.0Lf\n", ans);
    return 0;
}
