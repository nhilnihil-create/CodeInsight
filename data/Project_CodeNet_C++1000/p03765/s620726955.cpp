#include <bits/stdc++.h>
using namespace std;
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
template< typename T >
struct ruiseki{
    vector <T> s;
    int sz;
    ruiseki(vector <T> &a){
        sz = a.size()+1;
        s.resize(sz);
        for(int i=1;i<sz;i++) s[i] = s[i-1] + a[i-1];
    }
    T get(int a, int b){
        if(b > sz-1) b = sz-1;
        return s[b] - s[a];
    }
};
signed main(void) { cin.tie(0); ios::sync_with_stdio(false);
    string s; cin>>s;
    string t; cin>>t;
    vector <int> a(s.size());   
    vector <int> b(t.size());
    rep(i,s.size()){
        if(s[i] == 'A') a[i] = 2;
        else a[i] = 1;
    }
    rep(i, t.size()){
        if(t[i] == 'B') b[i] = 1;
        else b[i] = 2;
    }
    //cout<<<<endl;
    struct ruiseki <int> sr(a);
    struct ruiseki <int> tr(b);
    int q; cin>>q;
    
    rep(unko, q){
        int a,b,c,d; cin>>a>>b>>c>>d;
        a--; c--;
        
        if(sr.get(a,b)%3 == tr.get(c,d)%3){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
}