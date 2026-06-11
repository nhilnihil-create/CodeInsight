#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

const int MAX_N=200010;

int N;
vector<int> a(MAX_N),b(MAX_N);

bool lower(int n){
    rep(i,2*N-1){
        if (a[i]<=n) b[i]=1;
        else b[i]=0;
    }
    ll p=INF,q=INF;
    rep(i,2*N-2) if (b[i]==b[i+1]){
        if (b[i]==1){
            if (i<N-1) chmin(p,N-i-2);
            else chmin(p,i-N+1);
        }
        else {
            if (i<N-1) chmin(q,N-i-2);
            else chmin(q,i-N+1);
        }
    }
    if (p==INF&&q==INF) return b[0]==1;
    if (min(p,q)==p) return true;
    else return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,2*N-1) cin >> a[i];
    int lb=0,ub=2*N;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if (lower(mid)) ub=mid;
        else lb=mid;
    }
    cout << ub << endl;
}