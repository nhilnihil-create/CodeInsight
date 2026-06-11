#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef vector<ll>VI;
typedef vector<bool>VB;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define bitrep(bit,A) for(int bit=A; ;bit=(bit-1)&A)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) (ll)((a).size())
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define SORT(c) stable_sort(ALL(c))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
const int MOD = 1000000007;
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
#define greater greater<int>()
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
using Edge=pair<int,ll>;
using Graph=vector<vector<ll> >;//ll or Edge
using Edge=pair<int,ll>;
//const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// g++ -o a a.cpp -Wall -lm -std=c++17
int main(){
    ll n,k;cin>>n>>k;
    VI a(n),m(n+1);
    rep(i,n){
        cin>>a[i];
        m[i+1]=a[i];
    }
    m[0]=0;
    rep(i,n)m[i+1]=max(m[i+1],m[i]);
    ll ans=INFTY;
    rep(bit,(1LL<<n)){
        VI list;
        rep(i,n)if(bit&(1LL<<i))list.push_back(i);
        if((ll)list.size()!=k)continue;
        ll maxH=0,res=0;
        rep(i,k){
            chmax(maxH,m[list[i]]);
            if(a[list[i]]<=maxH){
                maxH++;
                res+=maxH-a[list[i]];
            }
            else maxH=a[list[i]];
        }
        chmin(ans,res);
    }
    cout<<ans<<endl;
}