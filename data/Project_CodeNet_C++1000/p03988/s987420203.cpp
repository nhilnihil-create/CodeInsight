#include<bits/stdc++.h>
using namespace std;

void ans(bool b) {
    cout << (b ? "Possible" : "Impossible") << endl;
    exit(0);
}

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> a(N);
    for (int64_t& A : a) {
        cin >> A;
    }

    int64_t one_num = count(a.begin(), a.end(), 1);
    if (one_num == 1) {
        //1のものが中心のスターグラフじゃないとダメ
        //1以外のものは全て2じゃないとおかしい
        //逆にそうであれば構築可能
        int64_t two_num = count(a.begin(), a.end(), 2);
        ans(two_num == N - 1);
    } else if (one_num >= 2) {
        ans(N == 2);
    }

    int64_t max_value = *max_element(a.begin(), a.end());
    int64_t max_num = count(a.begin(), a.end(), max_value);

    if (max_num == 1) {
        ans(false);
    }

    //maxを両端にして一列に並べるようなものを考える
    int64_t min_value;

    if (max_value % 2 == 0) {
        min_value = max_value / 2;

        //min_valueは1個でないといけない
        int64_t min_num = count(a.begin(), a.end(), min_value);
        if (min_num != 1) {
            ans(false);
        }
    } else {
        min_value = max_value / 2 + 1;

        //min_valueは2個でないといけない
        int64_t min_num = count(a.begin(), a.end(), min_value);
        if (min_num != 2) {
            ans(false);
        }
    }

    //min_value未満のものがあったらダメ
    int64_t ng_num = count_if(a.begin(), a.end(), [min_value](int64_t v) { return v < min_value; });
    if (ng_num > 0) {
        ans(false);
    }

    for (int64_t i = min_value + 1; i <= max_value; i++) {
        int64_t num = count(a.begin(), a.end(), i);
        if (num <= 1) {
            ans(false);
        }
    }

    ans(true);
}