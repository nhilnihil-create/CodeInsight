#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll len = 0;

    for (ll i = 0; i < 50; ++i) {
        if ((1LL << i) - 1 <= N) continue;
        len = i - 1;
        N -= (1LL << len) - 1;
        break;
    }

    // まずは(1, 2, ..., len)を作る
    vector<ll> p(len);
    for (ll i = 0; i < len; ++i) {
        p[i] = i + 1;
    }

    // len+1を適宜追加していく
    for (ll i = len; i >= 0; --i) {
        if ((1LL << i) <= N) {
            // iとi+1の間にlen + 1を追加
            p.insert(p.begin() + i, ++len);
            N -= (1LL << i);
        }
    }

    cout << len * 2 << endl;

    // 前半は作った1~lenの順列
    for (ll n : p) {
        cout << n << " ";
    }

    // 後半は1~lenの昇順列
    for (ll i = 1; i <= len; ++i) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
