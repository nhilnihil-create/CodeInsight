#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>
#include <cassert>
#include <bitset>

using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define bitcount(n) __builtin_popcountll(n)


typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = 500000 + 7;
const int M = 20;
const int inf = 1e9 + 7;
const long long linf = 1ll * inf * N * 1000;
const double pi = acos(-1);
const double eps = 1e-7;
const bool multipleTest = 0;


int x[N];
int n;
ll f[N];

void solve() {
    
    f[0] = 1;
    for(int i = 1; i < N; ++i) f[i] = f[i - 1] * i % inf;
    
    cin >> n;
    
    ll ans = 1;
    int pre = -1;
    
    int tol = 0;
    
    for(int i = 1; i <= n; ++i) {
        scanf("%d", x + i);
        if (x[i] == pre + 1) {
            
            ans = (ans * (i - tol)) % inf;
        
            ++tol;
            
        } else {
            x[i] = pre + 2;
            pre = x[i];
        }
    }
    
    ans = ans * f[n - tol] % inf;
    
    cout << ans << '\n';
    
}


int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
    //t1=clock();
#endif
    
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    for(int i = 0; i < Test; ++i) {
        solve();
    }
    
#ifdef _LOCAL_
    cout<<"\n" << clock() / CLOCKS_PER_SEC<<endl;
#endif
}
