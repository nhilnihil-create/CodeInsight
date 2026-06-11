#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//https://www.creativ.xyz/dump-cpp-652/
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
 
// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
 
#define DUMPOUT cerr
 
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
struct ruiseki{
    vector <int> s;
    ruiseki(vector <int> &a){
        s.resize(a.size()+1);
        for(int i=1;i<s.size();i++){
            s[i] = s[i-1] + a[i-1];
        }
    }
    int get(int r, int l){
        if(r < 0 || l >= s.size()) return INF;
        return s[l] - s[r];
    }
};

struct LazySegTree{ //seg sum
    int n;
    vector <int> node, lazy;
   
    LazySegTree(vector <int> v){
        int sz = v.size();
        n = 1;
        while(n<sz) n*=2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i]; //一番下側
        for(int i=n-2;i>=0;i--) node[i] = node[2*i+1]+node[2*i+2];
    }
    void eval(int k,int l, int r){
        if(lazy[k] != 0){
            node[k] += lazy[k];
            if(r - l >1){
                lazy[2*k+1] += lazy[k]/2;
                lazy[2*k+2] += lazy[k]/2;
            }
            lazy[k] = 0;
        }
    }
    void add(int a, int b, int x, int k=0, int l=0, int r=-1) {
        
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};
//http://tsutaj.hatenablog.com/entry/2017/03/30/224339
vector <int> zaatsu(vector <int> &a){
    vector <int> tmp = a;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    //rep(i,tmp.size()) cout<<tmp[i]<<endl;
    
    map <int,int> ma;
    for(int i=0;i<tmp.size();++i){
        ma[tmp[i]] = i;
    }

    vector <int> ret(a.size());
    for(int i=0;i<a.size();i++){
        ret[i] = ma[a[i]];
    }
    return ret;
}
signed main(void) { cin.tie(0); ios::sync_with_stdio(false);
    int n, k; cin>>n>>k;
    vector <int> a(n);
    rep(i,n) {cin>>a[i]; a[i] -= k;}
    
    struct ruiseki r(a);
    
    auto comp = zaatsu(r.s);
    vector <int> data(214514);
    struct LazySegTree Lseg(data);
    int ans = 0;
    //cout<<comp<<endl;
    
    rep(i, n+1){
        int now = comp[i];
        
        ans += Lseg.getsum(0, now + 1);
        Lseg.add(now, now+1, 1);
    }
    
    cout<<ans<<endl;
}