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
    ll n, m;
    cin >> n >> m;
    ll check;
    ll MAX = 0;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        if(i==0) check = a;
        else check = __gcd(check, a);
        MAX = max(MAX, a);
    }
    if(check==m)
        cout << "POSSIBLE" << endl;
    else if(check==1 && MAX >= m)
        cout << "POSSIBLE" << endl;
    else {
        if(m%check==0 && m <= MAX)
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
