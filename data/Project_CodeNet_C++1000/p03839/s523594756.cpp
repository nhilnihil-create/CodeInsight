#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<double, double> Pdd;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

const ll mod = 1e9+7;
const int INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

ll a[100000];
ll f[100000];
ll b[100000];
ll l[100000];
int main(void){
    int n, k; cin >> n >> k; for(int i = 0;i < n;i++)cin >> a[i];
    if(a[0] > 0)f[0] = a[0];
    else f[0] = 0;
    for(int i = 1;i < n-k;i++){
        f[i] = f[i-1];
        if(a[i] > 0)f[i] += a[i];
    }
    if(a[n-1] > 0)b[n-1] = a[n-1];
    else b[n-1] = 0;
    for(int i = n-2;i >= k;i--){
        b[i] = b[i+1];
        if(a[i] > 0)b[i] += a[i];
    }
    l[0] = 0;
    for(int i = 0;i < k;i++)l[0] += a[i];
    for(int i = 1;i <= n-k;i++)l[i] = l[i-1] + a[i+k-1] - a[i-1];
    ll ans = b[k];
    if(l[0] > 0)ans += l[0];
    for(int i = 1;i < n-k;i++){
        ll t = f[i-1] + b[i+k];
        if(l[i] > 0)t += l[i];
        ans = max(ans, t);
    }
    ll t = f[n-k-1]; if(l[n-k] > 0)t += l[n-k];
    ans = max(ans, t);
    cout << ans << endl;
 	return 0;
}