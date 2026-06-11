#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

ll Q, H, S, D;
ll n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> Q >> H >> S >> D;
    cin >> n;
    ll one = min(4 * Q, min(H * 2, S));
    ll two = min(one * 2, D);
    ll ans = n / 2 * two + (n & 1) * one;
    cout << ans << endl;
    return 0;
}
