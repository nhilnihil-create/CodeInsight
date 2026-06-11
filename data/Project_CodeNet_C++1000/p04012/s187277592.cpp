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
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    string w;
    cin >> w;
    int N = w.size();
    vb check(N, false);
    for (int i = 0; i < N; i++) {
        if (check.at(i)) {
            continue;
        }
        char c = w.at(i);
        int count = 1;
        for (int j = i + 1; j < N; j++) {
            if (w.at(j) == c) {
                count++;
                check.at(j) = true;
            }
        }
        if (count % 2 == 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}