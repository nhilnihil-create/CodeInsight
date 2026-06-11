#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    
    int n;cin>>n;
    ll tary[n];
    ll aary[n];
    rep(i,n) cin>>tary[i];
    rep(i,n) cin>> aary[i];

    ll kakutei[n];
    rep(i,n) kakutei[i]=0;
    kakutei[0]=tary[0];
    kakutei[n-1]=aary[n-1];
    ll l_min_ary[n];
    rep(i,n) l_min_ary[i] = INF;
    ll r_min_ary[n];
    rep(i,n) r_min_ary[i] = INF;

    rep(i,n)
    {
        if (i==0)
        {
            l_min_ary[0] = tary[i];
            continue;
        }
        
        if (l_min_ary[i-1]!=tary[i])
        {
            kakutei[i] = tary[i];
            l_min_ary[i] = tary[i];
        }
        else
        {
            l_min_ary[i] = tary[i];

        }
    }
    // rREP(i, n-1, 0)
    for (int i=n-1;i>=0;i--)
    {
        if (i==n-1)
        {
            r_min_ary[n-1] = aary[n-1];
            continue;
        }

        if (r_min_ary[i+1] != aary[i])
        {
            kakutei[i] = aary[i];
            r_min_ary[i] = aary[i];
        }
        else
        {
            r_min_ary[i] = r_min_ary[i+1];
            /* code */
        }
        
    }

    ll ans = 1;
    bool flag = true;
    rep(i,n)
    {
        if (kakutei[i]!=0)
        {
            if (r_min_ary[i]>= kakutei[i] && l_min_ary[i] >= kakutei[i])
            {
                continue;
            }
            else
            {
                flag = false;
                break;
            }
            
        }
        else
        {
            ans *= min(l_min_ary[i], r_min_ary[i]);
            ans %= MOD;
        }
    }
    if (n==1 && tary[0]!=aary[0])
    {
        cout << 0 << endl;
    }
    else if (flag)
    {
        cout << ans << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    
}
