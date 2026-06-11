#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

ll myceil(ll a, ll b) {
    if(a % b == 0) return a / b;
    return (a + (b - a%b)) / b;
}

int main() {
    int N; cin >> N;
    ll ansT = 0, ansA = 0;
    ll t, a;
    cin >> t >> a;
    ansT = t, ansA = a;
    rep(i, N - 1) {
        cin >> t >> a;
        ll add = max(myceil(ansT, t), myceil(ansA, a));
        ansT = add * t;
        ansA = add * a;
    }
    cout << ansT + ansA << endl;
}
