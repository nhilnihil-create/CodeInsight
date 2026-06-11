#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

int main(){
    ll n;
    cin >> n;
    ll a[n] = {};
    ll cnt = 0,memo = 0;
    rep(i,0,n) cin >> a[i];
    sort(a,a+n);

    rep(i,0,n){
        if(i > 0 && memo*2 < a[i]){
            cnt = 0;
        }
        cnt++;
        memo += a[i];
    }
    cout << cnt << endl;
    return 0;
}
