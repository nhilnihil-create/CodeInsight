#include"bits/stdc++.h"
using namespace std;

int main() {
    int64_t W, H;
    cin >> W >> H;
    vector<int64_t> p(W), q(H);
    for (int64_t i = 0; i < W; i++) {
        cin >> p[i];
    }
    for (int64_t i = 0; i < H; i++) {
        cin >> q[i];
    }

    //行,列ごちゃまぜで小さい順に取りたい
    struct Element {
        int64_t value, row_or_col;
        bool operator<(const Element& rhs) const {
            return value < rhs.value;
        }
        bool operator>(const Element& rhs) const {
            return value > rhs.value;
        }
    };

    priority_queue<Element, vector<Element>, greater<Element>> pq;
    for (int64_t i = 0; i < W; i++) {
        pq.push({ p[i], 0 });
    }
    for (int64_t i = 0; i < H; i++) {
        pq.push({ q[i], 1 });
    }

    int64_t row_line_num = 0, col_line_num = 0, ans = 0;
    while (!pq.empty()) {
        Element e = pq.top();
        pq.pop();
        if (e.row_or_col == 0) {
            ans += e.value * (H + 1 - row_line_num);
            col_line_num++;
        } else {
            ans += e.value * (W + 1 - col_line_num);
            row_line_num++;
        }
    }
    cout << ans << endl;
}