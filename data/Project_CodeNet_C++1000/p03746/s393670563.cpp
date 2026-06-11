#include <bits/stdc++.h>
using namespace std;

#define int long long
 
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

#define YES puts("YES")
#define Yes puts("Yes")
#define NO  puts("NO")
#define No  puts("No")
#define ALL(v) (v).begin(), (v).end()
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
 
#if 1
//-------------
// DUMPマクロ
// https://www.creativ.xyz/dump-cpp-652/

#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

// vector
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
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
ostream& operator<<(ostream& os, set<T>& set_var) {
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
void dump_func(Head&& head, Tail&& ... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG
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

// http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

#endif


//*
#define mod 1000000007 /*/
#define mod 998244353 //*/

typedef pair<int, int> P;
#define INF (1LL<<60)

using Graph = vector<vector<int>>;

Graph g;

void solve(){
    int N, M;
    cin >> N >> M;
    g.resize(N);
    
    vector<int> a(M), b(M);
    rep(i,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    
    vector<bool> used(N);
    used[a[0]] = true;
    used[b[0]] = true;
    
    deque<int> path;
    path.push_back(a[0]);
    path.push_back(b[0]);
    
    while(true){
        bool update = false;
        int v = path.back();
        for(int i=0; i< g[v].size(); i++){
            int next = g[v][i];
            if(!used[next]){
                path.push_back(next);
                used[next] = true;
                update=true;
                break;
            }
        }

        v=path.front();
        for(int i=0; i< g[v].size(); i++){
            int next = g[v][i];
            if(!used[next]){
                path.push_front(next);
                used[next] = true;
                update=true;
                break;
            }
        }
        
        if(!update) break;
    }

    cout << path.size() << endl;
    for(auto v : path){
        cout << v+1 << " ";
    }
    cout << endl;
    
}

signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed << setprecision(18);
    solve();
}
