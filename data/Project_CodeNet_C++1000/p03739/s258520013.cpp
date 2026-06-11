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

const ll MOD = 1e9+7;

int main(){
    ll n;
    cin >> n;
    ll a[n],b[n];
    rep(i,0,n){
        cin >> a[i];
        b[i] = a[i];
    }

    ll ans1 = 0,memo = 0;
    rep(i,0,n){
        memo += a[i];
        if(i % 2 == 0 && memo <= 0){
            ans1 += abs(memo) + 1;
            memo = 1;
        }
        else if(i % 2 == 1 && memo >= 0){
            ans1 += memo + 1;
            memo = -1;
        }
    }

    ll ans2 = 0;
    memo = 0;
    rep(i,0,n){
        memo += a[i];
        if(i % 2 == 1 && memo <= 0){
            ans2 += abs(memo) + 1;
            memo = 1;
        }
        else if(i % 2 == 0 && memo >= 0){
            ans2 += memo + 1;
            memo = -1;
        }
    }

    cout << min(ans1,ans2) << endl;
}
