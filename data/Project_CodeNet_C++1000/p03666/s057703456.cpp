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
//#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    for(ll i = 0; i < N; ++i) {//i回足す，N - 1 - i回引く
        ll maxv = A + D * i - C * (N - 1 - i);
        ll minv = A + C * i - D * (N - 1 - i);
        if(minv <= B && B <= maxv) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
