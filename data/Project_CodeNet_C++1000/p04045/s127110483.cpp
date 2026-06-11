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

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;


bool is_banned[10];
bool check(ll n){
    string t = "";
    while(n){
        if(is_banned[n % 10]) return false;
        n /= 10;
    }

    return true;
}

int main(){
    ll n,k;
    cin >> n >> k;

    rep(i,0,k){
        ll d;
        cin >> d;
        is_banned[d] = true;
    }

    ll ans = n;
    while(1){
        if(check(ans)) break;
        ans++;
    }

    cout << ans << endl;
    return 0;
}
