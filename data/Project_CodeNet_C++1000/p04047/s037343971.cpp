
// Problem : Longest Path on Grid
// Contest : CodeChef - TSEC January Codeathon
// URL : https://www.codechef.com/TJCN2019/problems/TSECJC06
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

/* DEBUGGING */
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

/* MACROS */ 
typedef long long int ll;
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef map<int,int> mii;

#define  ff          first
#define  ss          second
#define  pb          push_back
#define  IOS         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  lb          lower_bound
#define  ub          upper_bound
#define  all(x)      (x).begin(), (x).end()
#define  lcm(x, y)   ((x) * (y) / __gcd(x, y))
#define  ps(x,y)     fixed<<setprecision(y)<<x
#define  setbit(x)   __builtin_popcountll(x)
#define  rep(i,a,b)  for(int i=a ; i<b ; ++i)
#define  repr(i,a,b) for(int i=a ; i>=b ; --i)

/* CONSTANTS */ 
#define PI 3.141592653589793
const ll MOD = 1e9 + 7;
const ll INF = 1000000000;
const ll MAX_N = 2e5 + 2;

// #define cerr if(false)cerr
/* CODE STARTS HERE */

void solve(){
    int n; cin >> n;
    vi v(2*n);
    
    for(auto &x:v) cin >> x;
    sort(all(v));
    
    ll sum = 0;
    repr(i,(2*n)-2,0) sum += min(v[i],v[i+1]),i--;
    cout << sum;
}

int main(){
    IOS;
    solve();
}