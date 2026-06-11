#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/rope>

using namespace __gnu_pbds; 
using namespace __gnu_cxx;
using namespace std;

typedef long long ll;

#define eb emplace_back
#define pb push_back
// #define mp make_pair
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
template<typename T> using oset = tree <T, null_type, less_equal <T>, rb_tree_tag, tree_order_statistics_node_update >;
template<typename T> using MinPriorityQueue = priority_queue <T, vector <T>, greater <T> >;
template<typename T> void done(T ans) {cout << ans << "\n"; exit(0);}

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 mt(seed);

clock_t time_p=clock();
void printTime(){
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}
 

const int mod = 1e9 + 7;
const int N = 3e5 + 5;

int fac[N],invf[N];
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x - y >= 0 ? x - y : x - y + mod; }
inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}
void initcombi(int n) {
    for (int i = fac[0] = 1; i <= n; i++) { fac[i] = 1ll * fac[i - 1] * i % mod; }
    invf[n] = power(fac[n], mod - 2);
    for (int i = n; i; i--) { invf[i - 1] = 1ll * invf[i] * i % mod; }
}
 
inline int NCR(int n, int m) {
    if (n < m) { return 0; }
    return 1ll * fac[n] * invf[m] % mod * invf[n - m] % mod;
}


int main() {
    io();

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), pre(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(i) {
            pre[i] += pre[i - 1] + a[i];

        }
        else {
            pre[i] = a[i];
        }

    }
    for(int i = 0; i < n; i++) {
        pre[i] -= (1LL * (i + 1) * k);
    }

    oset<ll> s;
    ll ans = 0;
    s.insert(0);
    for(int i = 0; i < n; i++) {
        ans += s.order_of_key(pre[i] + 1);
        s.insert(pre[i]);

    }
    cout << ans;

}