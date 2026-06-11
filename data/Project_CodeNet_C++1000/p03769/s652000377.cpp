#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 1e9+7
#define N 2001
#define MAX_V 400010
#define vec vector<int>
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umap unordered_map<ll,int,custom_hash>
struct pair_hash
{
    template<class T1,class T2>
    size_t operator() (const pair<T1,T2> &p)const{
        return hash<T1>()(p.first)^hash<T2>()(p.second);
    }
};

int ans;
vec a;
void pr(int n){
    a.pb(n);
    ans++;
    return;
}
main(){
    ll n=lin();
    vector<ll> v;
    v.pb(0);
    v.pb(1);
    rep2(i,2,40){
        v.pb((v[i-1]+1)*2-1);
    }
    sort(ALL(v),greater<ll>());
    int pos=0;
    while(n<v[pos]){
        pos++;
    }
    int mem=40-pos;
    n-=v[pos];
    rep(i,41)v[i]++;
    vec s;
    while(n){
        while(n>=v[pos]){
            s.pb(40-pos);
            n-=v[pos];
        }
        pos++;
    }
    sort(ALL(s));
    cout<<mem*2+s.size()*2<<endl;
    int now=0;
    int temp=1;
    while(temp<=mem){
        while(now<s.size()&&s[now]<temp){
            cout<<mem+1+now<<" ";
            now++;
        }
        cout<<temp<<" ";
        temp++;
    }
    rep2(i,1,mem)cout<<i<<" ";
    rep3(i,mem+s.size(),mem+1)cout<<i<<" ";
}