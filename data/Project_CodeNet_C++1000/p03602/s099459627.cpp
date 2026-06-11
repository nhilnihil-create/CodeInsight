#include "bits/stdc++.h"

using namespace std;
using ll = long long;

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define precision(n) fixed<<setprecision(n)

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

void io(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);    
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <ext/rope>
// using namespace __gnu_pbds; 
// using namespace __gnu_cxx;
// template<typename T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;
// template<typename T> using MinPriorityQueue = priority_queue <T, vector <T>, greater <T> >;
// template<typename T> void done(T ans) {cout << ans << "\n"; exit(0);}


template <typename A>
istream& operator>>(istream& input,vector<A>& x) { for(auto& i:x) input>>i; return input; }
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {  for(auto& i:x) output<<i<<' '; return output; }
template<typename T, typename U> 
istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> 
ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

signed main () {
    io();
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        
        }
    }
    int flag = 0;
    
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][k] + a[k][j] < a[i][j]) {
                    debug(i, j, k);
                    flag = 1;
                }
  
            }
        }   
    }
    if(flag) {
        cout << "-1";
        return 0;
    }
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            flag = 0;
            for(int k = 0; k < n; ++k) {
                if(i == k || j == k)    continue;
                if(a[i][k] + a[k][j] == a[i][j]) {
                    flag = 1;
                }
  
            }
            debug(flag, i, j, a[i][j]);
            if(flag == 0)
                sum += a[i][j];
        }   
    }
    cout << sum / 2;

}

//asdasdlkjl