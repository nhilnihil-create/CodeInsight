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

ll gcd (ll a, ll b) {
    ll x = min(a, b);
    ll y = max(a, b);
    if (y % x == 0) {
        return x;
    }
    else {
        return gcd(y % x, x);
    }
}

ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    int N;
    cin >> N;
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll num;
        cin >> num;
        ans = lcm(ans, num);
    }
    cout << ans << endl;
}
