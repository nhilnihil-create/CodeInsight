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

vector<pair<char, int64_t>> run_length(string s) {
    vector<pair<char, int64_t>> ret;
    if (s.empty()) return ret;
    int64_t cnt = 0;
    char c = s[0];
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            cnt++;
        } else {
            ret.emplace_back(c, cnt);
            c = s[i];
            cnt = 1;
        }
        if (i + 1 == s.size()) {
            ret.emplace_back(c, cnt);
        }
    }
    return ret;
}

void solve() {
    Int n;
    cin >> n;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        print(1);
        return;
    }
    vector<Int> b;
    b.push_back(a[0]);
    for (Int i = 1; i < n; i++) {
        if (b.back() != a[i]) {
            b.push_back(a[i]);
        }
    }
    Int m = b.size();
    Int res = 0;
    Int mode = 0;
    for (Int i = 1; i < m; i++) {
        if (mode == 0) {
            if (b[i - 1] <= b[i]) {
                mode = 1;
            } else {
                mode = 2;
            }
        }
        if (mode == 1) {
            if (b[i - 1] > b[i]) {
                res++;
                mode = 0;
            }
        }
        if (mode == 2) {
            if (b[i - 1] < b[i]) {
                res++;
                mode = 0;
            }
        }
    }
    print(res + 1);
}

int main() {
    solve();
    return 0;
}
