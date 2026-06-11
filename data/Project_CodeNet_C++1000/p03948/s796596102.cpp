#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll n, t, a[100100];
map<ll, ll> mp;
int main(void){
    // Your code here!
    cin >> n >> t;
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll sma = a[0];
    for (ll i = 1; i < n; i++){
        sma = min(sma, a[i - 1]);
        mp[a[i] - sma]++;
    }
    auto itr = mp.end(); itr--;
    cout << itr->second << endl;
}
