#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i]>>b[i];
    }

    ll ans=0;
    for(int d = 30; d >= -1; d--) {
        vector<bool> bit(31,true);
        for(int i = 30; i > d; i--) {
            bit[i]=(k&(1<<i));
        }
        for(int i = d; i >= 0; i--) {
            bit[i]=0;
            if(k&(1<<i)) break;
        }

        ll now=0;
        for(int i = 0; i < n; i++) {
            bool add=true;
            for(int j = 0; j <= 30; j++) {
                if(!bit[j] && (a[i]&(1<<j))) add=false;
            }
            if(add) now+=b[i];
        }
        chmax(ans,now);
        //cout<<now<<endl;
    }
    cout<<ans<<endl;
}