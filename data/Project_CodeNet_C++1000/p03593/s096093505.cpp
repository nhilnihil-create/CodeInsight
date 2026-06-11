#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> vs(h);
    map<char, int> m;
    int ecnt = 0, ocnt = 0;
    bool ans = false;
    rep(i, h) cin >> vs[i];
    rep(i, h) {
        rep(ii, w) {
            m[vs[i][ii]]++;
        }
    }
    for (auto x : m) {
        if (x.second % 2 != 0) {
            ocnt++;
        }
        else {
            ecnt++;
        }
    }
    if ((w == 1) && (h == 1)) {
        ans = true;
    }
    else if (w == 1) {
        if ((h % 2 == 1) && (ocnt == 1)) ans = true;
        else if ((h % 2 == 0) && (ocnt == 0)) ans = true;
    }
    else if (h == 1) {
        if ((w % 2 == 1) && (ocnt == 1)) ans = true;
        else if ((w % 2 == 0) && (ocnt == 0)) ans = true;
    }
    else {
        priority_queue<int> pq;
        for (auto x : m) pq.push(x.second);
        int ftimes, ttimes, otimes;
        if ((w % 2 == 0) && (h % 2 == 0)) {
            ftimes = (h * w) / 4; ttimes = 0; otimes = 0;
        }
        else if (w % 2 == 0) {
            ftimes = ((h / 2) * (w / 2)); ttimes = w / 2; otimes = 0;
        }
        else if (h % 2 == 0) {
            ftimes = ((h / 2) * (w / 2)); ttimes = h / 2; otimes = 0;
        }
        else {
            ftimes = ((h / 2) * (w / 2)); ttimes = (h + w - 2) / 2; otimes = 1;
        }
        rep(i, ftimes) {
            if (pq.top() < 4) {
                cout << "No" << endl;
                return 0;
            }
            int v = pq.top();
            pq.pop();
            v -= 4;
            pq.push(v);
        }
        rep(i, ttimes) {
            if (pq.top() < 2) {
                cout << "No" << endl;
                return 0;
            }
            int v = pq.top();
            pq.pop();
            v -= 2;
            pq.push(v);
        }
        if (otimes == 1) {
            if ((sz(pq) == 0) || (pq.top() != 1)) {
                cout << "No" << endl;
                return 0;
            }
        }
        ans = true;
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
