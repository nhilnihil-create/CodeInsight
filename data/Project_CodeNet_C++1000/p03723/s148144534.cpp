#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h> // sqrt
using namespace std;

int main() {
    long a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c && a % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    long A, B, C;
    while (true) {
        if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
            break;
        }
        ans++;
        A = (b + c) / 2;
        B = (a + c) / 2;
        C = (b + c) / 2;
        a = A;
        b = B;
        c = C;
    }
    cout << ans << endl;
}