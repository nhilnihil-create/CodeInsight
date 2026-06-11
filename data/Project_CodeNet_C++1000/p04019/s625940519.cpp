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
    string S;
    cin >> S;
    bool check = true;
    bool n = false, s = false;
    for (char c : S) {
        if (c == 'N') {
            n = true;
        }
        else if (c == 'S') {
            s = true;
        }
        if (n && s) {
            break;
        }
    }
    if (n != s) {
        cout << "No" << endl;
        return 0;
    }
    bool w = false, e = false;
    for (char c : S) {
        if (c == 'W') {
            w = true;
        }
        else if (c == 'E') {
            e = true;
        }
        if (w && e) {
            break;
        }
    }
    if (w == e) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
