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

ll n;
string a;
vector<string> ans;
string c = "abcdefghijklm";

int main(void) {
    ll n;
    cin >> n;
    ll a[n], sum[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(ll i = 0; i < n; i++){
        if(i==0) sum[i] = a[i];
        else sum[i] = sum[i-1]+a[i];
    }
    sort(sum, sum+n, greater<ll>());
    sort(a, a+n, greater<ll>());
    ll ans = 1;
    for(ll i = 1; i < n; i++){
       // cout << sum[i] << endl;
        if(sum[i]*2>=a[i-1]) ans++;
        else break;
    }
    cout << ans << endl;
    return 0;
}
