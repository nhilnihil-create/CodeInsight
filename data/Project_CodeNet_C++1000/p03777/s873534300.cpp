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
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using Graph = vector<vector<int>>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int myAbs(int num) {
    if (num > 0)
        return num;
    else
        return -num;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

vector<bool> seen;
void dfs(const Graph& G, int v, int count) {
    seen[v] = true;
    count = 0;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        if (count > 2) continue;
        count++;
        cout << count << ":" << next_v << endl;
        dfs(G, next_v, count);
    }
}

const long long INF = 1LL << 60;

int main() {
    char a, b; cin >> a >> b;
    if (a == 'H' && b == 'H') cout << 'H' << endl;
    else if (a == 'H' && b == 'D') cout << 'D' << endl;
    else if (a == 'D' && b == 'H') cout << 'D' << endl;
    else cout << 'H' << endl;
}