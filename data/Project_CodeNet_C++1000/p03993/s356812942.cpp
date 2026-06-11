#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    ll a[n+1];
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    vector<ll> c(n+1, 1);
    for(ll i = 1; i <= n; i++){
        if(c[i]!=1) continue;
        ll check = a[i];
        if(i==a[check] && check==a[i]){
            ans++;
            c[check]=0;
        }
        c[i]=0;
    }
    cout << ans << endl;
    return 0;
}
