#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //int:2*10**9
typedef long double ld;
typedef pair<ll,ll> P;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define vec2(name,i,j) vector<vector<ll>> name(i,vector<ll>(j))
#define vec2f(name,i,j,k) vector<vector<ll>> name(i,vector<ll>(j,k))
#define vec3(name,i,j,k) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k)))
#define vec3f(name,i,j,k,l) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k,l)))
#define vec4(name,i,j,k,l) vector<vector<vector<vector<ll>>>> name(i,vector<vector<vector<ll>>>(j,vector<vector<ll>>(k,vector<ll>(l))))
#define vec4f(name,i,j,k,l,m) vector<vector<vector<vector<ll>>>> name(i,vector<vector<vector<ll>>>(j,vector<vector<ll>>(k,vector<ll>(l,m))))
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
#define N 110000
vector<ll> minht(N);
vector<ll> maxht(N);
vector<ll> minha(N);
vector<ll> maxha(N);
vector<ll> t(N);
vector<ll> a(N);
vector<ll> minh(N);
vector<ll> maxh(N);

int main(){
    ll n; cin >> n;
    REP(i,n){
        cin >> t[i];
        if (i==0) minht[i]=maxht[i]=t[i];
        else if (i==n-1) {maxht[i]=t[i]; minht[i]=0;}
        else if (t[i]>t[i-1]) minht[i]=maxht[i]=t[i];
        else {maxht[i]=t[i]; minht[i]=0;}
    }
    REP(i,n){
        cin >> a[i];
    }
    FORD(i,n-1,0){
        if (i==n-1) minha[i]=maxha[i]=a[i];
        else if (i==0) {maxha[i]=a[i]; minha[i]=0;}
        else if (a[i]>a[i+1]) minha[i]=maxha[i]=a[i];
        else {maxha[i]=a[i]; minha[i]=0;}
    }
    REP(i,n){
        maxh[i]=min(maxha[i],maxht[i]);
        minh[i]=max(minha[i],minht[i]);
    }
    /*REP(i,n){
        cout << maxht[i] << " " << minht[i] << endl;
    }
    REP(i,n){
        cout << maxha[i] << " " << minha[i] << endl;
    }
    REP(i,n){
        cout << maxh[i] << " " << minh[i] << endl;
    }*/
    ll ans = 1;
    REP(i,n){
        if (maxh[i]<minh[i]) ans = 0;
        else if (minh[i]==0) ans = (ans*maxh[i])%MOD;
        else ans = (ans*(maxh[i]-minh[i]+1))%MOD;
    }
    cout << ans << endl;
}