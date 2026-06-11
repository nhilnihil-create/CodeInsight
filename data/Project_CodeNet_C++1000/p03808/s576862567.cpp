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
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
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
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n) {
        cin>>a[i];
        sum+=a[i];
    }
    
    if(sum%(n*(n+1)/2)!=0) {
        cout<<"NO"<<endl;
        return 0;
    }
    
    ll k=sum/(n*(n+1)/2);
    ll cnt=0;
    rep(i,n-1) {
        ll d=a[i+1]-a[i];
        if((k-d)%n!=0) {
            cout<<"NO"<<endl;
            return 0;
        }
        ll x=(k-d)/n;
        if(x<0) {
            cout<<"NO"<<endl;
            return 0;
        }
        cnt+=x;
    }
    
    cout<<(cnt<=k ? "YES" : "NO")<<endl;
}
