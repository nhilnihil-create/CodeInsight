#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>   
#include <stdio.h>    
 
using namespace std;
     
#define F first
#define S second
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define al 0x3F3F3F3F
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
//#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)2e5 + 123;
const ll inf = (ll)3e18 + 1;

const double pi = acos (-1.0);
const double eps = 1e-7;
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

int n, m, a, b, fact[N], inv[N], ans;

inline int mult (int a, int b) {
   return 1ll * a * b % mod;
}

inline int add (int a, int b) {
   a += b;
   if (a >= mod) a -= mod;
   return a;
}

inline int binpow (int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = mult (res, a);
      a = mult (a, a);
      b >>= 1;
   }
   return res;
}

inline int C (int n, int k) {
   return mult (fact[n], mult (inv[k], inv[n - k]));
}

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     
                                      
inline void Solve () {
   cin >> n >> m >> a >> b;
   fact[0] = inv[0] = 1;
   for (int i = 1; i <= n + m; i ++) {
      fact[i] = mult (fact[i - 1], i);
      inv[i] = binpow (fact[i], mod - 2);
   }
   for (int down = 0; down < n - a; down ++) {
      ans = add (ans, mult (C (b - 1 + down, down), C (n + m - 2 - b - down, m - 1 - b)));
   } 
   cout << ans;
}                                     

main () {                                       
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
// cin >> tt;                                                                                
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}
