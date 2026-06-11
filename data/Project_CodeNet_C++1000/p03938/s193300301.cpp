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
    if (print_space_enable) cout << " ";
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
    std::cout << std::endl;
}

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n), b(n), p(n);
    for (Int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (Int i = 0; i < n; i++) {
        a[i] = 1;
    }
    for (Int i = 0; i < n; i++) {
        b[i] = 1;
    }
    for (Int i = 0; i < n; i++) {
        a[p[i] - 1] += i;
    }
    for (Int i = 0; i < n; i++) {
        b[p[i] - 1] += i;
    }
    for (Int i = 0; i < n - 1; i++) {
        a[i + 1] += a[i];
    }
    for (Int i = n - 1; i > 0; i--) {
        b[i - 1] += b[i];
    }
    print(a);
    print(b);
    return 0;
}
