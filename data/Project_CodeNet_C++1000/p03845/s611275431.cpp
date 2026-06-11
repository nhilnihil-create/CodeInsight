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
    cin >> N;
    vi T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    int M;
    cin >> M;
    vector<vi> drink(M, vi(2));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> drink[i][j];
        }
    }
    int time = 0;
    for (int x : T) {
        time += x;
    }
    for (int i = 0; i < M; i++) {
        int d = drink[i][1] - T[drink[i][0] - 1];
        cout << time + d << endl;
    }
}
