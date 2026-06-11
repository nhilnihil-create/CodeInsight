#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
ll sz(string &s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

int main(){
    ll N,W;
    cin >> N >> W;
    ll v[N],w[N];
    vector<ll> vec[4];

    rep(i,0,N){
        cin >> w[i] >> v[i];
        vec[w[i] - w[0]].push_back(v[i]);
    }

    rep(i,0,4) sort(vec[i].begin(),vec[i].end(),greater<ll>());
    rep(i,0,4) rep(j,1,sz(vec[i])) vec[i][j] += vec[i][j-1];

    ll ans = 0,temp = 0;
    rep(i,0,sz(vec[0])+1){
        rep(j,0,sz(vec[1])+1){
            rep(k,0,sz(vec[2])+1){ 
                rep(l,0,sz(vec[3])+1){
                    if((i+j+k+l)*w[0]+(j+2*k+3*l) > W) break;
                    temp = 0;
                    if(i > 0) temp += vec[0][i-1];
                    if(j > 0) temp += vec[1][j-1];
                    if(k > 0) temp += vec[2][k-1];
                    if(l > 0) temp += vec[3][l-1];
                    ans = max(ans,temp); 
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
