#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int sa[101010], sb[101010], ta[101010], tb[101010];

int main() {
    string S, T;
    cin >> S >> T;
    int q;
    cin >> q;

    for (int i=1; i<=S.size(); ++i) {
        sa[i] = sa[i-1] + (S[i-1] == 'A');
        sb[i] = sb[i-1] + (S[i-1] == 'B');
    }
    for (int i=1; i<=T.size(); ++i) {
        ta[i] = ta[i-1] + (T[i-1] == 'A');
        tb[i] = tb[i-1] + (T[i-1] == 'B');
    }

    rep(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = sa[b] - sa[a-1] + (sb[b] - sb[a-1]) * 2;
        int y = ta[d] - ta[c-1] + (tb[d] - tb[c-1]) * 2;

        //cout << x << ", " << y << endl;
        if (x%3 == y%3) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
