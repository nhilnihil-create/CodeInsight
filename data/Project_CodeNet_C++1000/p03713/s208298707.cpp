#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<pair<int, ll>>>;

const int INF = 1001001001;
ll h, w;

ll solve1(ll a){
    ll res = h - a;
    ll b = res/2, c = res - b;
    return max(abs(a-b), max(abs(a-c), abs(b-c))) * w;
}

ll solve2(ll a){
    ll res = h - a;
    ll b = w/2, c = w - b;
    return max(abs(a*w - res*b), max(abs(a*w - res*c), abs(res*b - res*c)));
}

int main(){
    cin >> h >> w;
    ll ans = INF;
    for(ll a = 1; a <= h-1; a++){
        ll tmp1 = solve1(a);
        ll tmp2 = solve2(a);
        ans = min(ans, min(tmp1, tmp2));
    }
    swap(h, w);
    for(ll a = 1; a <= h-1; a++){
        ll tmp1 = solve1(a);
        ll tmp2 = solve2(a);
        ans = min(ans, min(tmp1, tmp2));
    }
    cout << ans << endl;
}