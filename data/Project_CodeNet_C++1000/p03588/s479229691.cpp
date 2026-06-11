#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n;
    ll now = -1,cnt=INF;
    for(i=0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        if(x>now){
            now = x;
            cnt = y;
        }
    }
    cout << now + cnt << endl;
    return 0;
}