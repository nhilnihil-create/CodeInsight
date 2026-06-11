#include <bits/stdc++.h>
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
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
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


void solve(){
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    set<ll> se;
    rp(i,1500){
        rp(j,1500){
            se.insert(i*c+j*d);
        }
    }
    double ratio=0.0;
    ll ans_gro=100*a;
    ll ans_sug=0;
    for(ll i=0; i<=f/100; i++){
        for(ll j=0; j<=f/100-i*a; j++){
            ll rest=f-100*(i*a+j*b);
            if(rest<0) continue;
            auto it=se.upper_bound(min(rest,(i*a+j*b)*e));
            if(it==se.begin()) continue;
            it--;
            if(chmax(ratio,(double)*it/(double)(100*(i*a+j*b)+*it))){
                ans_gro=100*(i*a+j*b)+*it;
                ans_sug=*it;
            }
        }
    }
    cout << ans_gro << " " << ans_sug << endl;
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}