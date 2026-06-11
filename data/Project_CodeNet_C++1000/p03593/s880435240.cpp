#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 998244353;
signed main() {
    int h, w;
    cin>>h>>w;
    map<char, int> m;
    char c;
    for (int i = 0; i < h * w; i++) cin>>c, m[c]++;

    int cnt1, cnt2 = 0, cnt4 = 1;
    if (h % 2 && w % 2) cnt1 = 1;
    else cnt1 = 0;

    if (h % 2) cnt2 += w / 2;
    if (w % 2) cnt2 += h / 2;

    cnt4 *= h / 2;
    cnt4 *= w / 2;

    for (auto&& p: m) {
        if (p.second % 2) {
            p.second--;
            cnt1--;
            break;
        }
    }

    for (auto&& p: m) {
        if (p.second % 2) {
            cout<<"No"<<endl;
            return 0;
        } else if (p.second % 4 == 2) {
            p.second -= 2;
            cnt2--;
        }
    }

    if (cnt2 < 0) {
        cout<<"No"<<endl;
        return 0;
    }

    for (auto&& p: m) while (cnt4 > 0 && p.second > 0) cnt4--, p.second -= 4;

    for (auto&& p: m) {
        while (cnt2 > 0 && p.second > 0) p.second -= 2, cnt2--;
    }

    if (cnt1 == cnt2 && cnt2 == cnt4 && cnt4 == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}