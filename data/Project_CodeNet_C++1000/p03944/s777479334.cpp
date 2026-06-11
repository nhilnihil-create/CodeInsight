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
    int W, H, N;
    cin >> W >> H >> N;
    vector<vi> data(N, vi(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> data[i][j];
        }
    }
    int X = 0, Y = 0;
    for (int i = 0; i < N; i++) {
        if (data[i][2] == 1) {
            X = max(X, data[i][0]);
        }
        else if (data[i][2] == 2) {
            W = min(W, data[i][0]);
        }
        else if (data[i][2] == 3) {
            Y = max(Y, data[i][1]);
        }
        else {
            H = min(H, data[i][1]);
        }
    }
    if (W - X <= 0 || H - Y <= 0) {
        cout << 0 << endl;
    }
    else {
        cout << (W - X) * (H - Y) << endl;
    }
}
