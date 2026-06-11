#include"bits/stdc++.h"
using namespace std;

int main() {
    string S, T;
    int64_t q;
    cin >> S >> T >> q;
    vector<int64_t> a(q), b(q), c(q), d(q);
    for (int64_t i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    //B->AA->BBBB->Bと戻せるのでBを一度全てAAに変換して考える
    //結局Aの数を3で割った余りが一致していれば変換可能
    //累積和を計算
    vector<int64_t> sum_S(S.size() + 1), sum_T(T.size() + 1);
    sum_S[0] = sum_T[0] = 0;
    for (uint64_t i = 0; i < S.size(); i++) {
        sum_S[i + 1] = sum_S[i] + (S[i] == 'A' ? 1 : 2);
    }
    for (uint64_t i = 0; i < T.size(); i++) {
        sum_T[i + 1] = sum_T[i] + (T[i] == 'A' ? 1 : 2);
    }

    for (int64_t i = 0; i < q; i++) {
        int64_t num_S = sum_S[b[i]] - sum_S[a[i] - 1];
        int64_t num_T = sum_T[d[i]] - sum_T[c[i] - 1];
        cout << (num_S % 3 == num_T % 3 ? "YES" : "NO") << endl;
    }
}