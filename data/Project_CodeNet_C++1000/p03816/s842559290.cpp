#include <iostream>
#include <vector>
#include <map>
// #include <string>
// #include <algorithm>
// #include <set>
// #include <cmath>

using namespace std;
typedef unsigned long long ull;


template<typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& m) {
    os << "{";
    for (const auto x : m) {
        os << x.first << ":" << x.second << " ";
    }
    os << "}";
    return os;
}


int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, int> M;
    for (int i = 0; i < N; i++) {
        auto iter = M.find(A[i]);
        if (iter == M.end()) {
            M[A[i]] = 1;
        } else {
            M[A[i]] += 1;
        }
    }
    // cout << M << endl;

    int count = 0;
    int n_2 = 0;
    for (auto item : M) {
        if (item.second % 2 == 0) {
            count += (item.second - 2) / 2;
            n_2 += 1;
        } else {
            count += (item.second - 1) / 2;
        }
    }
    count += (n_2 + 1) / 2;

    cout << N - count*2 << endl;

    return 0;
}
