#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
// #include <cmath>
// #include <string>
// #include <map>
// #include <set>

// #define MOD 1000000007

using namespace std;
typedef unsigned long long ull;
// typedef long long ll;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}


template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}

vector<vector<ull>> calc_comb(int n, int r) {
    vector<vector<ull>> ret(n+1, vector<ull>(n+1, 0));
    for (int i = 0; i <= n; ++i) {
        ret[i][0] = 1;
        ret[i][i] = 1;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            ret[i][j] = ret[i-1][j] + ret[i-1][j-1];
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    int N, A, B;
    cin >> N >> A >> B;
    vector<ull> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ull>());
    // cout << v << endl;

    ull sum = 0;
    for (int i = 0; i < A; ++i) {
        sum += v[i];
    }
    cout << fixed << setprecision(10) << (double)sum / A << endl;

    int start = 0;
    for (int i = A-1; i > 0; --i) {
        if (v[i] < v[i-1]) {
            start = i;
            break;
        }
    }
    int end = N-1;
    for (int i = A-1; i < N-1; ++i) {
        if (v[i] > v[i+1]) {
            end = i;
            break;
        }
    }

    int n = end - start + 1;
    // p("start", start, " end", end);
    int r_min, r_max;
    r_min = A - start;
    if (start == 0) {
        r_max = min(n, B - start);
    } else {
        r_max = r_min;
    }
    // p("n", n, " r_min", r_min, " r_max", r_max);
    auto comb = calc_comb(n, r_max);
    ull count = 0;
    for (int r = r_min; r <= r_max; ++r) {
        count += comb[n][r];
    }
    cout << count << endl;

    return 0;
}
