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

int main(void){
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    for(ll i = 0;i < n;i++){
        if(a-b >= (n-1-i)*c - i*d && a-b <= (n-1-i)*d-i*c){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
 	return 0;
}
