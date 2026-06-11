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
    string A, B;
    cin >> A >> B;
    if (A.size() > B.size()) {
        cout << "GREATER" << endl;
        return 0;
    }
    if (A.size() < B.size()) {
        cout << "LESS" << endl;
        return 0;
    }
    for (int i = 0; i < A.size(); i++) {
        if (A.at(i) > B.at(i)) {
            cout << "GREATER" << endl;
            return 0;
        }
        if (A.at(i) < B.at(i)) {
            cout << "LESS" << endl;
            return 0;
        }
        if (i == A.size() - 1) {
            cout << "EQUAL" << endl;
            return 0;
        }
    }
}