#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<v<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> A(M,0);
    vector<ll> B(M,0);
    for(ll i=0;i<M;++i){
        cin>>A[i]>>B[i];
    }
    vector<vector<ll>> G(N+1, vector<ll>(0));
    for(ll i=0;i<M;++i){
        G[A[i]].emplace_back(B[i]);
        G[B[i]].emplace_back(A[i]);
    }
    ll now=1;
    vector<bool> check(N+1,0);check[1]=1;
    deque<ll> ans;ans.emplace_back(1);
    while(1){
        bool k=0;
        for(auto p: G[now]){
            if(!check[p]){
                ans.emplace_back(p);
                now=p;check[p]=1;
                k=1;break;
            }
        }
        if(!k)break;
    }
    now=1;
    while(1){
        bool k=0;
        for(auto p: G[now]){
            if(!check[p]){
                ans.emplace_front(p);
                now=p;check[p]=1;
                k=1;break;
            }
        }
        if(!k)break;
    }

    prt(ans.size())
    for(auto p: ans){
        cout<<p<<" ";
    }cout<<endl;
    return 0;
}
