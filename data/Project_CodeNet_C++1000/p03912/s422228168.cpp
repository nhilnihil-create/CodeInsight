#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
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
    int n,m;
    cin >> n >> m;
    map<int,int> count;
    rep(i,0,n){
        int x;
        cin >> x;
        ++count[x];
    }

    vector<int> s(m),a(m);
    for(auto &p:count){
        s[p.first%m]+=p.second;
        a[p.first%m]+=p.second/2;
    }

    int ans=0;
    vector<bool> done(m);
    rep(i,0,m){
        if(done[i]) continue;

        int j=(m-i)%m,ma=0;
        if(i==j){
            ans+=s[i]/2;
            done[i]=true;
            continue;
        }
        rep(x,0,a[i]+1){
            rep(y,0,a[j]+1){
                ma=max(ma,min(s[i]-2*x,s[j]-2*y)+x+y);
            }
        }
        ans+=ma;
        done[i]=done[j]=true;
    }
    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
