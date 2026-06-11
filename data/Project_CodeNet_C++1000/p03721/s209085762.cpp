#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> ab(N);
    ll a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        ab[i] = {a, b};
    }
    sort(ab.begin(), ab.end());
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        a = ab[i].first;
        b = ab[i].second;
        cnt += b;
        if (K <= cnt) {
            cout << a << endl;
            return 0;
        }
    }
    return 0;
}
