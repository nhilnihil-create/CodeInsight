#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int H, W; cin >> H >> W;

    vector<string> a(H);
    rep(i, H) {
        cin >> a[i];
    }
    vector<int> cnt(27);
    rep(i, H) rep(j, W) {
        int ind = a[i][j] - 'a';
        cnt[ind] += 1;
    }

    priority_queue<int> pque;
    rep(i, cnt.size()) {
        if (cnt[i]) pque.emplace(cnt[i]);
    }

    int need_nb = 4;

    rep(i, H/2) {
        rep(j, W/2) {
            int nb = pque.top(); pque.pop();
            if (nb < 4) {
                cout << "No" << endl;
                return 0;
            }
            nb -= 4;
            pque.emplace(nb);
        }
    }

    need_nb = 4;
    if (H % 2 == 1) {
        rep(i, W/2) {
            int nb = pque.top(); pque.pop();
            if (nb < 2) {
                cout << "No" << endl;
                return 0;
            }
            nb -= 2;
            pque.emplace(nb);
        }
    }
    if (W % 2 == 1) {
        rep(i, H/2) {
            int nb = pque.top(); pque.pop();
            if (nb < 2) {
                cout << "No" << endl;
                return 0;
            }
            nb -= 2;
            pque.emplace(nb);
        }
    }
    /*
    if (H % 2 == 1 && W % 2 == 1) {
        int nb = pque.top(); pque.pop();
        if (nb < 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    */

    cout << "Yes" << endl;
    return 0;
}