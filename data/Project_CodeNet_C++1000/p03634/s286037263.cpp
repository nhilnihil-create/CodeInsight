#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

const int NM = 1e5+10;
map<pair<ll, ll>, ll> dist;
vector<ll> tree[NM];

bool isexist(ll a, ll b){
    if(a>b) swap(a,b);
    if(dist[make_pair(a,b)] != 0) return true;
    else return false;
}

ll get_dist(ll a, ll b){
    if(a>b) swap(a,b);
    return dist[make_pair(a,b)];
}

void reg(int a, int b, int d){
    if(a>b) swap(a,b);
    dist[make_pair(a,b)] = d;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    for(ll i=1; i<=n-1; i++){
        ll a,b,c;cin>>a>>b>>c;
        tree[a].push_back(b);
        tree[b].push_back(a);
        reg(a,b,c);
    }
    ll q, k; cin>>q>>k;
    vector<P> query(q);
    for(ll i=0; i<q; i++){
        cin>>query[i].first>>query[i].second;
    }
    // 幅優先探索
    queue<P> qu;
    qu.push(make_pair(k, 0));
    ll ad[NM] = {-1};
    for(ll i=0; i<NM; i++){
        ad[i] = -1;
    }
    ad[k] = 0;
    while(!qu.empty()){
        ll top = qu.front().first; 
        ll now = qu.front().second;
        qu.pop();
        for(ll t : tree[top]){
            if(ad[t] != -1) continue;
            ad[t] = now+get_dist(top, t);
            qu.push(make_pair(t, ad[t]));
        }
    }
    for(auto t : query){
        cout<< (ll)ad[t.first] + (ll)ad[t.second] <<'\n';
    }

}
