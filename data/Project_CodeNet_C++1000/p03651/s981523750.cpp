#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位


int main(void){
    ll n, k;
    cin >> n >> k;
    ll a[n];
    ll MAX = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        MAX = max(MAX, a[i]);
    }
    ll check = a[0];
    for(ll i = 1; i < n; i++)
        check = __gcd(check, a[i]);
    //bool ok = true;
    if(k%check==0 && MAX >= k)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
