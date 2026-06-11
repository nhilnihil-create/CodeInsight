#include <iostream>
#include <vector>
#include <algorithm>
// #include <set>
// #include <string>
// #include <cmath>
// #include <map>
// #include <iomanip>

#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;
// typedef long long ll;

// void p() {
//     cout << "\n";
// }
// template<class Head, class... Body>
// void p(Head head, Body... body) {
//     cout << head << ",";
//     p(body...);
// }

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}


int main(int argc, char const *argv[]) {
    int N;
    ull W;
    cin >> N >> W;
    vector<ull> w(N), v(N);
    vector<vector<ull>> w2v(4);
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
        w2v[(int)(w[i] - w[0])].push_back(v[i]);
    }

    for (int i = 0; i < 4; ++i) {
        sort(w2v[i].begin(), w2v[i].end(), greater<ull>());
    }
    // cout << w2v << endl;

    vector<vector<ull>> w2v_cum(4);
    for (int i = 0; i < 4; ++i) {
        w2v_cum[i].push_back(0);
        ull sum = 0;
        for (ull item : w2v[i]) {
            sum += item;
            w2v_cum[i].push_back(sum);
        }
    }
    // cout << w2v_cum << endl;

    ull ans = 0;
    for (int i = 0; i <= w2v[0].size(); ++i) {
        ull w0 = (w[0] + 0) * i;
        for (int j = 0; j <= w2v[1].size(); ++j) {
            ull w1 = (w[0] + 1) * j;
            for (int k = 0; k <= w2v[2].size(); ++k) {
                ull w2 = (w[0] + 2) * k;
                for (int l = 0; l <= w2v[3].size(); ++l) {
                    ull w3 = (w[0] + 3) * l;
                    if (w0 + w1 + w2 + w3 > W) break;
                    ull sum = w2v_cum[0][i] + w2v_cum[1][j] + w2v_cum[2][k] + w2v_cum[3][l];
                    if (ans < sum) {
                        ans = sum;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
