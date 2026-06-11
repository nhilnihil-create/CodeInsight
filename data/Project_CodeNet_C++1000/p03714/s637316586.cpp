#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n;
Vi a;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>n;
    a.resize(3*n);
    rep(i,3*n){
        cin>>a[i];
    }
    priority_queue< ll ,vector<ll>,greater<ll>> fr;
    priority_queue<ll> bk;
    ll sfr=0;
    rep(i,n){
        sfr += a[i];
        fr.push(a[i]);
    }
    Vi frs(n+1,0);
    Vi bks(n+1,0);
    frs[0] = sfr;
    rep(i,n){
        ll tp = fr.top();
        if(tp > a[n+i]){
            frs[i+1] = sfr;
            continue;
        }
        fr.pop();
        fr.push(a[n+i]);
        sfr += a[n+i] - tp;
        frs[i+1] = sfr;
    }
    ll sbk=0;
    rep(i,n){
        sbk +=  a[3*n-1-i];
        bk.push(a[3*n-1-i]);
    }
    bks[0] = sbk;
    rep(i,n){
        ll tp = bk.top();
        if(tp < a[2*n-1-i]){
            bks[i+1] = sbk;
            continue;
        }
        bk.pop();
        bk.push(a[2*n-1-i]);
        sbk += a[2*n-1-i] - tp;
        bks[i+1] = sbk;
    }
    ll ans = -INT64_MAX;
    rep(i,n+1){
        chmax(ans,frs[i]-bks[n-i]);
        //cout<<frs[i]<<" "<<bks[n-i]<<endl;
    }
    print(ans);
    return 0;
}