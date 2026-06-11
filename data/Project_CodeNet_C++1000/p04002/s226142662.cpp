#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll h, w, n, a, b, ans[11];
map<P, ll> mp;
int main(void){
    // Your code here!
    cin >> h >> w >> n;
    for (ll i = 0; i < n; i++){
        cin >> a >> b;
        for (ll j = 0; j < 3; j++){
            for (ll k = 0; k < 3; k++){
                if (a + j < 3 || a + j > h) continue;
                if (b + k < 3 || b + k > w) continue;
                mp[P(a + j, b + k)]++;
            }
        }
    }
    ans[0] = (h - 2) * (w - 2);
    for (auto itr = mp.begin(); itr != mp.end(); ++itr){
        ans[itr->second]++;
        ans[0]--;
    }
    for (ll i = 0; i < 10; i++) cout << ans[i] << endl;
}
