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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    if(a[0]>k) {
        ans += a[0]-k;
        a[0]=k;
    }
    for(ll i = 0; i < n-1; i++){
        if(a[i]+a[i+1]>k){
            ll b = a[i]+a[i+1]-k;
            ans+=b;
            a[i+1]-=b;
            if(a[i+1]<0) a[i+1] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
