#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define pb push_back
#define pf push_front
#define eb emplace_back
using namespace std;
typedef long long ll;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b; return true;} return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b; return true;} return false;}
template<class t> int SIZE(t s){return (int)s.size();}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using vvi=vc<vc<int>>;
using pi=pair<int,int>;
using vi=vc<int>;
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
const long long INF = 1LL << 60;



//vvc<pair<ll,ll>> beto(1e3+7,vc<pair<ll,ll>>()); // pair<行先,コスト>

ll bell(ll start, ll goal, vvc<pair<ll,ll>>& beto){
    ll n = SIZE(beto);
    vc<ll> dist(n,INF);
    dist[start] = 0;
    rep(roop,n) {
        bool ch = false;
        rep(i,n){
            for (pair<ll,ll> p: beto[i]){
                if(dist[i] != INF && dist[i]+ p.second < dist[p.first]){
                    dist[p.first] = dist[i] + p.second;
                    ch = true;
                    //cout << i+1 << "->" << p.first+1 << " " << dist[p.first] << endl;
                    if(roop == n-1 && p.first == goal) return -1*INF;
                }
            }
        }
        if(!ch) break;
    }
    return dist[goal];
}

int main(){
    cout << fixed << setprecision(20);
    ll n,m; cin >> n >> m;
    vvc<pair<ll,ll>> beto(n,vc<pair<ll,ll>>());
    rep(i,m){
        ll a,b,c; cin >>a >> b >> c;
        a--; b--;
        beto[a].eb(make_pair(b,c*-1));
    }
    ll ans = bell(0,n-1,beto);
    if(ans == INF*-1) cout << "inf" << endl;
    else cout << ans*-1 << endl;
    return 0;
}
