#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <iomanip>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n, m, k;
    cin >> n >> m >> k;
    bool ok = false;
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j <= m; j++){
            ll a = m*i-j*i+(n-i)*j;
            //cout << i << " " << j << " " << a << endl;
            if(a==k){
                ok=true;
                break;
            }
        }
        if(ok==true) break;
    }
    if(ok==true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
