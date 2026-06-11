#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    ll ans = (N/2) * min(min(8 * Q, 4 * H), min(2 * S, D)) + (N % 2) * min(min(4 * Q, 2 * H), S);
    cout << ans << endl;
    return 0;
}