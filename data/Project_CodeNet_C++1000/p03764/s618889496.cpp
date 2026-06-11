#include <bits/stdc++.h>
using namespace std;

using i64=int64_t;

#define rep(i,x,y) for(i64 i=i64(x),i##_max_for_repmacro=i64(y); i<i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
 
const int inf=1.01e9;
const i64 inf64=4.01e18;
const double eps=1e-9;
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

void solve(){
    i64 n,m;
    cin >> n >> m;

    vector<i64> x(n),y(m);
    rep(i,0,n) cin >> x[i];
    rep(i,0,m) cin >> y[i];

    i64 s=0,t=0,mod=1000000007;
    rep(i,0,n-1) s=(s+(i+1)*(n-i-1)%mod*(x[i+1]-x[i])%mod)%mod;
    rep(i,0,m-1) t=(t+(i+1)*(m-i-1)%mod*(y[i+1]-y[i])%mod)%mod;

    cout << s*t%mod << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
