#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define ALL(obj) (obj).begin(), (obj).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};


int main() {
    cout<<fixed<<setprecision(10);

    ll n,m; cin>>n>>m;
    vint x(n); rep(i,n) cin>>x[i];
    map<ll,ll> tmp;
    rep(i,n){
        tmp[x[i]]++;
    }

    map<ll,ll> num, num_pair;

    for(auto p:tmp){
        num[p.first%m] += p.second;
        num_pair[p.first%m] += p.second/2;
    }

    // rep(i,m) cout<<num[i]<<" ";
    // puts("");

    ll ans = 0;

    // 0
    num_pair[0] = num[0]/2;
    if(m%2==0) num_pair[m/2] = num[m/2]/2;


    rep(i,m){
        if(i == ( m-i )%m) continue;
        // cout<<i<<": ";
        ll tmp = min(num[i], num[m-i]);
        ans += tmp;
        num_pair[i] -= max(0ll, (1 + tmp - (num[i] - 2*num_pair[i]))/2);
        num_pair[m-i] -= max(0ll, (1 + tmp - (num[m-i] - 2*num_pair[m-i]))/2);
        num[i] -= tmp;
        num[m-i] -= tmp;
        // cout<<ans<<endl;
    }

// puts("");
//     rep(i,m) cout<<num[i]<<" ";
// puts("");
//     rep(i,m) cout<<num_pair[i]<<" ";
// puts("");

    rep(i,m){
        // if(i==0 || (i == m-i)) continue;
        // cout<<num_pair[i]<<endl;
        ans += max(0ll, num_pair[i]);
        // cout<<ans<<endl;
    }

    cout<<ans<<endl;

    return 0;

}