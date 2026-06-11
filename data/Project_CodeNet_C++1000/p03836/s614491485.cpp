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

int main(void) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = c-a, y = d-b;
    string ans;
        for(ll i = 0; i < x; i++) ans += 'R';
        for(ll i = 0; i < y; i++) ans += 'U';
        for(ll i = 0; i < x; i++) ans += 'L';
        for(ll i = 0; i < y; i++) ans += 'D';
        ans += 'D';
        for(ll i = 0; i < x+1; i++) ans += 'R';
        for(ll i = 0; i < y+1; i++) ans += 'U';
        ans += 'L';  ans += 'U';
        for(ll i = 0; i < x+1; i++) ans += 'L';
        for(ll i = 0; i < y+1; i++) ans += 'D';
        ans += 'R';


    cout << ans << endl;
    return 0;
}
