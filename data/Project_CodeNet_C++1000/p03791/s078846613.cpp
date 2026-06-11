#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;

ll n,m,q,T;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    int c1,c2,c3,c4,c5;
    ll a,b,c,d;
    ll x,y;

    cin >> n;

    vector<ll> X;
    vector<ll> SP;
    vector<ll> PL;

    ll prev = 0;
    ll sum = 0;

    ll ans = 1;

    ll curr = 1;
    ll plm = 1;

    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        sum += a-prev-1;
        ans *= c1-plm+2;
       // cout << plm << " " << curr << "\n";
        if(a < curr){
            plm++;
            //curr = a;
        }
        else{
            curr += 2;
        }
        ans %= big;

    }

    cout << ans << "\n";

    return 0;
}
