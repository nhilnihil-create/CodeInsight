#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


template <class Abel> struct BIT {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;                     // to be set
    
    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};


using pint = pair<int,int>;
int N, M;
vector<pint> inter;

int main() {
    cin >> N >> M;
    inter.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> inter[i].first >> inter[i].second, ++inter[i].second;
    sort(inter.begin(), inter.end(), [&](pint i, pint j) {
            return i.second - i.first < j.second - j.first;});

    //for (int i = 0; i < N; ++i) cout << inter[i].first << ", " << inter[i].second << endl;

    vector<int> res(M);
    BIT<int> bit(M + 10);
    int pos = 0;
    for (int d = 1; d <= M; ++d) {
        while (pos < N && inter[pos].second - inter[pos].first <= d-1) {
            bit.add(inter[pos].first, inter[pos].second, 1);
            ++pos;
        }
        for (int i = d; i <= M; i += d) {
            res[d-1] += bit.sum(i, i+1);
        }
        res[d-1] += (N - pos);
    }

    for (int d = 0; d < M; ++d) cout << res[d] << endl;
}
