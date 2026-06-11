#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT{
private:
    vector<T> array;
    int n;

public:
    // 初期化
    BIT() {}
    BIT(int _n) : array(_n + 1, 0), n(_n) {}

    // 1番目から i番目までの累積和を求める
    T sum(int i) {
        T s = 0;
        while(i > 0) {
            s += array[i];
            i -= i & -i;      // LSB 減算
        }
        return s;
    }

    // [i, j] の要素の総和
    T sum(int i, int j) {
        T ret_i = sum(i-1);
        T ret_j = sum(j);
        return ret_j - ret_i;
    }

    // i 番目に 要素 x を追加
    void add(int i, T x) {
        while(i <= n) {
            array[i] += x;
            i += i & -i;      // LSB 加算
        }
    }
};

int main(void) {
    int N; cin >> N;
    int M; cin >> M;
    BIT<int> fenwick(M+5);
    vector<pair<int, pair<int, int>>> Q(N);
    for (int i = 0; i < N; i++) {
        int l, r; cin >> l >> r;
        r++;
        int len = r - l;
        Q[i] = {len, {l, r}};
    }
    sort(Q.begin(), Q.end());

    int added = 0;
    for (int d = 1; d <= M; d++) {
        for (int i = added; i < N && Q[i].first < d; i++) {
            int left = Q[i].second.first;
            int right = Q[i].second.second;
            fenwick.add(left, 1);
            fenwick.add(right, -1);
            added++;
        }

        int ans = N - added;
        for (int crt = 0; crt <= M; crt += d) {
            ans += fenwick.sum(crt);
        }
        cout << ans << endl;
    }
}