// う　し　た　ぷ　に　き　あ　く　ん　笑

// 問題考察
// 条件を満たすためには、特定のマスに同じ文字を書かなければならない。
// h,wを変えて小さいh,wでシミュレーションをしたところ、同じ文字でなければならないマスが何個あるかわかった。

// h,wが偶数のとき
// 同じ文字が書かれた4マス h*w/4個

// hが偶数、wが奇数（逆なら転置して）
// 同じ文字が書かれた4マス h*(w-1)/4個
// 同じ文字が書かれた2マス h*1/2個

// h,wが奇数
// 同じ文字が書かれた4マス (h-1)*(w-1)/4個
// 同じ文字が書かれた2マス (h-1+w-1)/2個
// 同じ文字が書かれた1マス 1個

// 式を簡潔に書き表す
// hh = h-h%2, ww = w-w%2
// 4 hh*ww/4
// 2 (h%2*ww+w%2*hh)/2
// 1 (h%2)*(w%2)

// 後はAの文字を数えて↑に割り当てて行けばいい
// 4マス→2マス、1マスの順で割り当てていく

#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;

    array<int, 'z' - 'a' + 1> chars = {};

    for (int i = 0; i < h * w; i++) {
        char a;
        cin >> a;
        chars[a - 'a']++;
    }

    const int hh = h - h % 2, ww = w - w % 2;

    int s4 = hh * ww / 4;
    int s2 = (h % 2 * ww + w % 2 * hh) / 2;
    int s1 = (h % 2) * (w % 2);

    array<int, 3> a{4, 2, 1};
    array<int, 3> sqs{s4, s2, s1};

    priority_queue<int> pq;
    for (auto &&i : chars) {
        if (i > 0) pq.emplace(i);
    }

    for (int i = 0; i < 3; i++) {
        while (sqs[i] > 0) {
            if (pq.top() >= a[i]) {
                const int top = pq.top();
                pq.pop();
                if (top - a[i] > 0) pq.emplace(top - a[i]);
                sqs[i]--;
            } else
                break;
        }
    }

    cout << (pq.empty() ? "Yes" : "No") << endl;
}
