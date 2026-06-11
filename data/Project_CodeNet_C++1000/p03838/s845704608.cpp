#include <bits/stdc++.h>
using namespace std;

typedef int64_t Int;
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << '\n'; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) std::cout << " ";
    cout << fixed << setprecision(15) << head;
    print_space_enable = true;
    print(std::forward<Tail>(tail)...);
}

template<typename T>
void print(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << v[i];
    }
    std::cout << '\n';
}

void solve() {
    Int x, y;
    cin >> x >> y;
    Int res = INF;
    if (x <= y) {
        res = min(res, y - x);
    }
    if (-x <= y) {
        res = min(res, 1 + y - (-x));
    }
    if (x <= -y) {
        res = min(res, 1 + (-y) - x);
    }
    if (-x <= -y) {
        res = min(res, 2 + (-y) - (-x));
    }
    print(res);
}

int main() {
    solve();
    return 0;
}
