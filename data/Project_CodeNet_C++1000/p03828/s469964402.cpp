#include <iostream>
#include <vector>
#include <map>
// #include <algorithm>
// #include <set>
// #include <cmath>
// #include <string>
 
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;
 

map<int, int> factorize(int n) {
    map<int, int> ret;
    for (int i = 2; i <= n; i++) {
        bool first = true;
        while (n % i == 0) {
            if (first) {
                ret[i] = 1;
                first = false;
            } else {
                ret[i] += 1;
            }
            n /= i;
        }
    }
    return ret;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& m) {
    os << "{";
    for (const auto x : m) {
        os << x.first << ":" << x.second << " ";
    }
    os << "}";
    return os;
}

map<int, int> merge(const map<int, int>& m1, const map<int, int>& m2) {
    map<int, int> ret = m1;
    for (auto item : m2) {
        auto iter = ret.find(item.first);
        if (iter == ret.end()) {
            ret[item.first] = item.second;
        } else {
            ret[item.first] += item.second;
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
 
    map<int, int> all_factors;
    for (int i = 2; i <= N; i++) {
        auto factors = factorize(i);
        // cout << i << endl;
        // cout << factors << endl;
        all_factors = merge(all_factors, factors);
    }
    // cout << all_factors << endl;

    ull ans = 1;
    for (auto item : all_factors) {
        ans = (ans * (item.second + 1)) % MOD;
    }
    cout << ans << endl;
 
    return 0;
}
