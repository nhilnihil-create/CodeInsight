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
    string s, t;
    cin >> s >> t;
    Int res = s.size() + t.size();
    for (Int i = 1; i <= (Int)min(s.size(), t.size()); i++) {
        bool check = true;
        for (Int j = 0; j < i; j++) {
            if (s[s.size() - i + j] != t[j]) {
                check = false;
            }
        }
        if (check) {
            res = min(res, (Int)(s.size() + t.size()) - i);
        }
    }
    print(res);
    return 0;
}
