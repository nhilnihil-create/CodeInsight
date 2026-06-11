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
#include <bitset> // bitset
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

ll N;

int f (ll A) {
    ll B = N / A;
    int ans = 1;
    while(B > 9) {
        B /= 10;
        ans++;
    }
    return ans;
}

int main() {
    cin >> N;
    int ans = -1;
    for (ll i = floor(sqrt(N)); i > 0; i--) {
        if (N % i == 0) {
            ans = f(i);
            break;
        }
    }
    cout << ans << endl;
}
