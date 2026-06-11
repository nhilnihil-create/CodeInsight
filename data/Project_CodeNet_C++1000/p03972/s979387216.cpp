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
 
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
 
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


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

#endif

#define mod 1000000007
//typedef pair<int, int> P;
#define INF (1LL<<60)

// ax+by=1の解
int extgcd(int a, int b, int& x, int& y){
    int d = a;
    if (b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a / b)*x;
    }
    else{
        x = 1; y = 0;
    }
    return d;
}

// mod mでのaの逆数
int mod_inv(int a, int m){
    int x, y;
    extgcd(a, m, x, y);
    return (m + x%m) % m;
}

int factorial(int n, int p){
    int r = 1;
    for (int i = 1; i <= n; i++)
        r = (r*i) % p;
    return r;
}

void solve(){
    int W, H;
    cin >> W >> H;
    priority_queue<int, vector<int>, greater<int>> pW, pH;
    rep(i,W){
        int a; cin >> a;
        pW.push(a);
    }
    rep(i,H){
        int a; cin >> a;
        pH.push(a);
    }
    
    int ans = 0;
    rep(i,W+H){
        if(pW.empty()){
            ans += pH.top() * (pW.size()+1);
            pH.pop();
            continue;
        }
        if(pH.empty()){
            ans += pW.top() * (pH.size()+1);
            pW.pop();
            continue;
        }
        
        if(pW.top() < pH.top()){
            ans += pW.top() * (pH.size()+1);
            pW.pop();
        }else if(pW.top() > pH.top()){
            ans += pH.top() * (pW.size()+1);
            pH.pop();
        }else{
            if(pW.size() < pH.size()){
                ans += pH.top() * (pW.size()+1);
                pH.pop();
            }else{
                ans += pW.top() * (pH.size()+1);
                pW.pop();
            }
        }
    }
    cout << ans << endl;
    
}

signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed << setprecision(18);
    solve();
}
