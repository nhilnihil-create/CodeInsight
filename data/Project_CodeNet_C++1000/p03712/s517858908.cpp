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
    ll h,w;
    cin >> h >> w;
    char c[h+2][w+2];
    rep(i,0,h+2) rep(j,0,w+2) c[i][j] = '#';

    rep(i,1,h+1){
        rep(j,1,w+1){
            cin >> c[i][j];
        }
    }

    rep(i,0,h+2){
        rep(j,0,w+2){
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}
