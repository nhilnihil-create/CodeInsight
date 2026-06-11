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
    int n;
    cin >> n;
    vi data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            deq.push_front(data[i]);
        }
        else {
            deq.push_back(data[i]);
        }
    }
    if (n % 2 == 1) {
        for (int x : deq) {
            cout << x << " ";
        }
    }
    else {
        for (int i = n - 1; i >= 0; i--) {
            cout << deq[i] << " ";
        }
    }
    cout << endl;
}
