/*
 * Author: .-O_O-.
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define rep0(a,b) for(int a=0;a<b;a++)
#define rep1(a,b) for(int a=1;a<=b;a++)
#define repp(a,b,c) for(int a=b;a<c;a++)
#define in insert
#define len length()
#define si size()
#define lb lower_bound
#define ub upper_bound
#define beg begin()
#define en end()
#define f first
#define s second
#define pr(a) cout<<a
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define nx cout<<"\n"
#define int long long
// void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
                                                     
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
const ll mod = 1000000007;
const ll N = 105;
const ll mm = 1e+18;
map<pair<int,int>,int>mp[2];
void f(vector<pair<pair<int,int>,int>>v,int idx){
    int n=(int)(v.si);
    rep0(i,(1<<n)){
        int aa=0;
        int bb=0;
        int cc=0;
        rep0(j,n){
            if((i>>j)&1){
                aa+=v[j].f.f;
                bb+=v[j].f.s;
                cc+=v[j].s;
            }
        }
        //deb(aa,bb,cc);
        auto it=mp[idx].find({aa,bb});
        if(it==mp[idx].en){
            mp[idx].in({{aa,bb},cc});
        }
        else it->s=min(it->s,cc);
    }
}
void solve()
{
    int n,ma,mb;
    cin>>n>>ma>>mb;
    vector<pair<pair<int,int>,int>>v;
    rep0(i,n){
        if(i==n/2){
            f(v,0);
            v.clear();
        }
        int a,b,c;
        cin>>a>>b>>c;
        v.pb({{a,b},c});
    }
    f(v,1);
    //deb(mp[0],mp[1]);
    int ans=0;
    int mi=mod;
    for(auto p:mp[0]){
        rep1(i,1000){
            if(i*ma>500||i*mb>500) break;
            auto it=mp[1].find({i*ma-p.f.f,i*mb-p.f.s});
            if(it!=mp[1].en){
                mi=min(mi,p.s+it->s);
            } 
        }
    }
    if(mi==mod) mi=-1;
    pr(mi);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    rep1(_i,t){
        //cout<<"Case #"<<_i<<": ";
        solve();
        //nx;
    }
    return 0;
}