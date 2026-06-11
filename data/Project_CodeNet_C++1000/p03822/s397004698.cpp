#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll,ll>;
using um = unordered_map<ll,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;
#define debug(v) cout<<#v<<": ",prt(v);
template <typename A,typename B>
inline void prt(pair<A,B> p){cout<<"("<<p.first<<", "<<p.second<<")\n";}
template <typename A,typename B,typename C>
inline void prt(tuple<A,B,C> p){cout<<"("<<get<0>(p)<<", "<<get<1>(p)<<", "<<get<2>(p)<<")\n";}
inline void prt(bool p){if(p)cout<<"True"<<'\n';else cout<<"False"<<'\n';}
template <typename T> 
inline void prt(vector<T> v){cout<<'{';for(ll i=0;i<v.size();i++){cout<<v[i];if(i<v.size()-1)cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(deque<T> v){cout<<'{';for(ll i=0;i<v.size();i++){cout<<v[i];if(i<v.size()-1)cout<<", ";}cout<<'}'<<'\n';}
template <typename A,typename B>
inline void prt(map<A,B> v){cout<<'{';ll c=0;for(auto &p: v){cout<<p.first<<":"<<p.second;c++;if(c!=v.size())cout<<", ";}cout<<'}'<<'\n';}
template <typename A,typename B>
inline void prt(unordered_map<A,B> v){cout<<'{';ll c=0;for(auto &p: v){cout<<p.first<<":"<<p.second;c++;if(c!=v.size())cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(set<T> v){cout<<'{';for(auto i=v.begin();i!=v.end();i++){cout<<*i;if(i!=--v.end())cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(multiset<T> v){cout<<'{';for(auto i=v.begin();i!=v.end();i++){cout<<*i;if(i!=--v.end())cout<<", ";}cout<<'}'<<'\n';}
//1-indexedなので注意！！！！
//＄１には頂点数＋３くらいをいれるといい
vector<vector<ll>> graph(100003, vector<ll>(0));  // DAG
vector<ll> order(0);  // トポロジカルソートされた頂点を格納
vector<bool> used(100003,0);  // 訪問済みフラグ

// 辿れるところまで辿る深さ優先探索
void dfs(ll u){
    if(used[u]) return;
    used[u] = true;
    for(ll v : graph[u]) dfs(v);
    order.emplace_back(u);     // 帰りがけ順で頂点を入れていく
}

// トポロジカルソート
//Nは頂点数
void tsort(ll N){
    for(ll v = 1; v <= N; v++) dfs(v);
    reverse(order.begin(), order.end());
}
//1-indexedなので注意！！！！
//1-indexedなので注意！！！！
//1-indexedなので注意！！！！
//1-indexedなので注意！！！！
signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N+1,0);
    for(ll i=2;i<=N;++i)cin>>a[i];
    for(ll i=2;i<=N;++i){graph[a[i]].emplace_back(i);}
    tsort(N);
    vector<ll> dp(N+1,0);
    for(ll i=N-1;i>=0;--i){
        vl vec={};
        for(auto p: graph[order[i]])vec.emplace_back(dp[p]+1);
        ll n=vec.size();
        sort(vec.rbegin(), vec.rend());
        for(ll j=0;j<n;++j){
            chmax(dp[order[i]],j+vec[j]);
        }
    }
    prt(dp[1]);

    return 0;
}

