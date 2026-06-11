#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
const int maxn = 5e3 + 5;
const int mod = 1e9 + 7;
const int logn = log2(maxn) + 1;

int f[maxn][maxn];
int Pow(int x , int y){
    if(y == 0)return 1;
    int r = Pow(x , y / 2);
    if(y & 1)return (ll)r * r  % mod * x % mod;
    return (ll)r * r % mod;
}
int n , m;
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    cin >> n >> s;
    m = s.size();
    f[0][0] = 1;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j <= n ; ++j){
            if(j > 0)f[i][j] = f[i - 1][j - 1] * 2;
            else f[i][j] = f[i - 1][j];
            if(f[i][j] >= mod)f[i][j] -= mod;
            f[i][j] += f[i - 1][j + 1];
            if(f[i][j] >= mod)f[i][j] -= mod;
        }
    }
    cout << 1ll * f[n][m] * Pow(Pow(2,m),mod-2) % mod;
}
