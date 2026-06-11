#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=3.14159265358979323846;
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) {
        cin>>a[i];
    }
    
    ll sum1=0,sum2=0;
    rep(i,n) {
        if(i<k) sum1+=a[i];
        else sum2+=max(0LL,a[i]);
    }
    
    ll ans=max(0LL,sum1)+sum2;
    rep(i,n-k) {
        sum2+=max(0LL,a[i]);
        sum1-=a[i];
        sum1+=a[i+k];
        sum2-=max(0LL,a[i+k]);
        ans=max(ans,max(0LL,sum1)+sum2);
    }
    
    cout<<ans<<endl;
    
}
