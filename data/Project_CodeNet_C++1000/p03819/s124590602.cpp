#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)(n-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T>
string join(const vector<T>&v, string del=", "){ stringstream s;
    for(auto x : v) s << del << x; return s.str().substr(del.size());
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>&v){
    if(v.size()) o << "[" << join(v) << "]"; return o;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T> >&vv){
    int l = vv.size();
    if(l){ o<<endl; rep(i,l) o << (i==0 ? "[ " : ",\n  " ) << vv[i] << (i==l-1 ? " ]" : ""); }
    return o;
}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

template<typename T>
struct BIT{
    int n;
    vector<T> dat;
    BIT(int n) : n(n), dat(n+1,0){}
    void add(int x, T val){
        for(int i = x+1; i <= n; i += (i & -i)) dat[i] += val;
    }
    T sum(int x){
        T ret = 0;
        for(int i = x+1; i > 0; i -= (i & -i)) ret += dat[i];
        return ret;
    }
    T sum(int a, int b){
        return sum(b) - sum(a-1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    int n,m; cin >> n >> m;
    vector<tuple<int,int,int>> t;
    rep(i,n){
        int l,r; cin >> l >> r;
        t.emplace_back(r-l,l,r);
    }
    t.emplace_back(m+1,-1,-1);
    sort(all(t));

    auto bit = BIT<int>(m+2);
    int i = 0;
    REP(d,1,m+1){
        while(get<0>(t[i]) < d){
            int l = get<1>(t[i]);
            int r = get<2>(t[i]);
            bit.add(l, 1);
            bit.add(r+1, -1);
            i++;
        }
        int ans = n-i;
        for(int di=0; di<m+1; di+=d){
            ans += bit.sum(di);
        }
        cout << ans << endl;
    }
    return 0;
}