
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll mod = 1e9+7;
const double error = 1e-7;
const double PI = acos(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise\n"
#define tham getchar()
mt19937 rng((unsigned int) chrono::system_clock::now().time_since_epoch().count());

inline ll MOD(ll x, ll m = mod)
{
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9+5;
const ll infl = 1e18+1;
const int nmax = 1e3+5;
///====================== template =========================

int main(){
    FASTIO;
    int n;
    cin>>n;
    vector<int> hat(n);
    for(int i = 0; i<n; i++) cin>>hat[i];

    int mx = *max_element(hat.begin(), hat.end());
    int mn = *min_element(hat.begin(), hat.end());

    if(mx > mn+1){
        cout<<"No";
        return 0;
    }

    if(mx == mn){
        if(mx == n-1){
            cout<<"Yes";
            return 0;
        }
        if(mx*2 <= n){
            cout<<"Yes";
            return 0;
        }
        cout<<"No";
        return 0;
    }

    int mxcnt = 0;
    for(int i = 0; i<n; i++) if(hat[i] == mx) mxcnt++;

    if(mxcnt == 1){
        cout<<"No";
        return 0;
    }

    int mncnt = n - mxcnt;

//    debug(mxcnt);
//    debug(mncnt);
//    debug(mx);

    if(mncnt < mx && 2*(mx - mncnt) <= mxcnt){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}
