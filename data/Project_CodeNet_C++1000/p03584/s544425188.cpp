#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N, K;
    cin>>N>>K;
    
    map<ll,ll> Ks;
    for(int i=1;i<33;i++){
        if((1LL<<i)&K){
            ll k=K-(1LL<<i);
            k|=(1LL<<i)-1;
            if(k<K) Ks[k]=0;
        }
    }
    
    Ks[K]=0;
    rep(i,N){
        ll a,b; cin>>a>>b;
        for(auto k:Ks){
            if((k.first&a)==a) Ks[k.first]+=b;
        }
    }
    ll mx=0;
    for(auto k:Ks) if(mx<k.second) mx=k.second;
    cout1(mx);
}