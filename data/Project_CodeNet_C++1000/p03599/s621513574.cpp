#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

#define NMAX 4000

ll dp[NMAX];

void init(){
    rep(i, 0, NMAX) dp[i] = -1;
}

int main(){
    init();
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    // dp[i] := 総重量 i <= f で，なおかつ解け残しがない時の最大砂糖溶解量
    dp[0] = 0;
    auto func = [&](ll cur, ll w, ll s) {
        ll weight = cur + 100 * w + s;
        if(weight > f) return false;
        ll sugar = dp[cur] + s;
        ll water = cur + 100 * w - dp[cur];
        // if(water % 100) exit(1);
        if(sugar > e * (water / 100)) return false;
        return true;
    };
    rep(i, 0, f+1) {
        if(dp[i] == -1) continue;
        if(func(i, a, 0)) dp[i + 100 * a] = max(dp[i + 100 * a], dp[i]);
        if(func(i, b, 0)) dp[i + 100 * b] = max(dp[i + 100 * b], dp[i]);
        if(func(i, 0, c)) dp[i + c] = max(dp[i + c], dp[i] + c);
        if(func(i, 0, d)) dp[i + d] = max(dp[i + d], dp[i] + d);
    }

    //rep(i, 0, f+1) cerr << i << " " << dp[i] << endl;
    ll mass = 100*a, sugar = 0;
    rep(i, 1, f+1) {
        if(i * sugar < dp[i] * mass) {
            sugar = dp[i];
            mass = i;
        }
        if(i == 2634) cerr << dp[i] << endl;
    }
    cout << mass << " " << sugar << endl;
    return 0;
}