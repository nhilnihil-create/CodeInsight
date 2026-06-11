#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    ll n,x;
    cin>>n>>x;
    chmax(x,n-x);
    ll ans=0;
    ll now=x;
    ans+=now;
    now=n-now;
    ans+=((n/now)*2-1)*now;
    if(n%now==0) {
        ans-=now;
        cout<<ans<<endl;
        return 0;
    }
    ll pre=now;
    now=n%now;
    while(now>0) {
        //cout<<pre<<" "<<now<<" "<<ans<<endl;
        ans+=((pre/now)*2)*now;
        if(pre%now==0) ans-=now;
        ll tmp=pre;
        pre=now;
        now=tmp%now;
    }
    cout<<ans<<endl;
}
