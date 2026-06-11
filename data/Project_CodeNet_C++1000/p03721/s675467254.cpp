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
    int N;
    ll K;
    cin >> N >> K;
    map<int, ll> data;
    for (int i = 0; i < N; i++) {
        int a;
        ll b;
        cin >> a >> b;
        if (data.count(a)) {
            data[a] += b;
        }
        else {
            data[a] = b;
        }
    }
    ll sum = 0;
    for (pair<int, ll> p : data) {
        sum += p.second;
        if (sum >= K) {
            cout << p.first << endl;
            break;
        }
    }
}
