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
typedef pair<int,int> ii;
const int maxn = 1e6 + 5;
const int logn = log2(maxn) + 1;
const int mod = 1e9 + 7;
int f[maxn];
int g[maxn];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(taskname".INP", "r")) {
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    }
    int n;cin >> n;
    int sum = n;
    f[n] = n;
    for(int i = n - 1 ; i >= 1 ; --i){
        f[i] = (sum - f[i + 2] + i + (i != n - 1) + (ll)(n - 1) * (n - 1)) % mod;
        if(f[i] < 0)f[i] += mod;
        sum += f[i];
        if(sum >= mod)sum -= mod;
    }
    cout << f[1];
}