#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

int main() {
    cin >> H >> W;
    ll ans = H*W, rect1, rect2, rect3, diff;
    if(H%3 == 0 || W%3 == 0) ans = 0;
    rep(i, H+1){
        rect1 = i*W;
        rect2 = (H-i)*(W/2);
        rect3 = (H-i)*(W-W/2);
        diff = max(abs(rect1 - rect2), max(abs(rect2 - rect3), abs(rect3 - rect1)));
        ans = min(ans, diff);

        rect2 = ((H-i)/2)*W;
        rect3 = ((H-i)-(H-i)/2)*W;
        diff = max(abs(rect1 - rect2), max(abs(rect2 - rect3), abs(rect3 - rect1)));
        ans = min(ans, diff);
    }
    rep(i, W+1){
        rect1 = i*H;
        rect2 = (W-i)*(H/2);
        rect3 = (W-i)*(H-H/2);
        diff = max(abs(rect1 - rect2), max(abs(rect2 - rect3), abs(rect3 - rect1)));
        ans = min(ans, diff);

        rect2 = ((W-i)/2)*H;
        rect3 = ((W-i)-(W-i)/2)*H;
        diff = max(abs(rect1 - rect2), max(abs(rect2 - rect3), abs(rect3 - rect1)));
        ans = min(ans, diff);

    }
    cout << ans;
}
