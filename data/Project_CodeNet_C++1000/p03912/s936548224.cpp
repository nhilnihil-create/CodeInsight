#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> X(N);
    for (int64_t& x : X) {
        cin >> x;
    }

    const int64_t max_value = *max_element(X.begin(), X.end());

    vector<int64_t> num(max_value + 1, 0);
    for (int64_t x : X) {
        num[x]++;
    }

    //card[i][j] := カードの値をMで割ったあまりがiで、カード数を2で割った余りがｊであるもの
    vector<vector<stack<int64_t>>> card(M, vector<stack<int64_t>>(2));
    for (int64_t i = 0; i <= max_value; i++) {
        if (num[i] == 0) {
            continue;
        }
        card[i % M][num[i] % 2].push(num[i]);
    }

    //マッチングを考えていく
    int64_t ans = 0;
    while (true) {
        bool change = false;
        for (int64_t i = 0; i < M; i++) {
            //奇数番目のものは奇数番目のもの同士でくっつければ良い
            while (!card[i][1].empty()) {
                int64_t top = card[i][1].top();
                card[i][1].pop();

                int64_t pair = (M - i) % M;

                //card[pair][1]に要素があればそれと結合
                if (!card[pair][1].empty()) {
                    int64_t inv = card[pair][1].top();
                    card[pair][1].pop();
                    ans++;
                    change = true;

                    if (inv != 1) {
                        card[pair][0].push(inv - 1);
                    }
                } else if (!card[pair][0].empty()) {
                    //偶数側から貰ってくる
                    int64_t inv = card[pair][0].top();
                    card[pair][0].pop();
                    ans++;
                    change = true;

                    //一つ減るので奇数側に追加
                    card[pair][1].push(inv - 1);
                }

                //一つ減るので偶数側に追加(1だったら消滅)
                if (top != 1) {
                    card[i][0].push(top - 1);
                }
            }
        }
        if (!change) {
            break;
        }
    }

    //同じカード同士で結合
    for (int64_t i = 0; i < M; i++) {
        for (int64_t j = 0; j < 2; j++) {
            while (!card[i][j].empty()) {
                ans += card[i][j].top() / 2;
                card[i][j].pop();
            }
        }
    }

    cout << ans << endl;
}