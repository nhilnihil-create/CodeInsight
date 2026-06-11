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
const ll INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

ll x[100000];
ll y[100000];

int main(void){
    ll n, m; cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> x[i];
    for(int i = 0;i < m;i++)cin >> y[i];
    ll xx = 0;
    for(int i = 0;i < n-1;i++){
        xx += (x[i+1] - x[i]) * (i+1) * (n-i-1);
        xx %= mod;
    }
    ll yy = 0;
    for(int i = 0;i < m-1;i++){
        yy += (y[i+1] - y[i]) * (i+1) * (m-i-1);
        yy %= mod;
    }
    cout << (xx * yy) % mod << endl;
	return 0;
}