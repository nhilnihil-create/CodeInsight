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
    ll n;
    cin >> n;
    vector<ll> c(100020, 0);
    for(ll i = 1; i <= n; i++){
        ll a;
        cin >> a;
        c[i] = a;
    }
    ll ans = 0;
    ll d = 0;
    for(ll i = 1; i <= n; i++){
        if(c[i]%2!=0 && i<n && c[i+1]!=0){
            c[i]--;
            c[i+1]--;
            ans++;
        }
        d = c[i]/2;
        ans+=d;
        c[i]-=d*2;
    }
    cout << ans << endl;
    return 0;
}
