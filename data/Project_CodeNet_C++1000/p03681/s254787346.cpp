#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    ll N, M;
    cin >> N >> M;
    int num = max(N, M) - min(N, M);
    if (num > 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for (ll i = 1; i <= N; i++) {
        ans *= i;
        ans %= 1000000007;
    }
    for (ll i = 1; i <= M; i++) {
        ans *= i;
        ans %= 1000000007;
    }
    if (num == 0) {
        ans *= 2;
        ans %= 1000000007;
    }
    cout << ans << endl;
}
