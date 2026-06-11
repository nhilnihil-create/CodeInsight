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
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

auto comb=make_vec<ll>(51,51);
ll c(int i,int j) {
    if(comb[i][j]!=-1) return comb[i][j];
    if(j==0 || j==i) return comb[i][j]=1;
    return comb[i][j]=c(i-1,j-1)+c(i-1,j);
}

int main() {
    rep(i,51) rep(j,51) comb[i][j]=-1;
    int n,a,b;
    cin>>n>>a>>b;
    vector<double> vec(n);
    rep(i,n) cin>>vec[i];
    sort(all(vec),greater<double>());
    
    double ave=0;
    rep(i,a) ave+=vec[i];
    ave/=a;
    cout<<fixed<<setprecision(10)<<ave<<endl;
    
    if(vec[0]==vec[a-1]) {
        int pos=a-1;
        while(pos+1<n && vec[pos+1]==vec[0]) pos++;
        ll ans=0;
        FOR(i,a,min(b,pos+1)) ans+=c(pos+1,i);
        cout<<ans<<endl;
    }
    else {
        int l=a-1,r=l-1;
        while(l-1>=0 && vec[l-1]==vec[a-1]) l--;
        while(r+1<n && vec[r+1]==vec[a-1]) r++;
        cout<<c(r-l+1,a-l)<<endl;
    }
}
