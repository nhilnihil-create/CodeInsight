//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi sum(n+1);
    int mi = 0;
    rep(i, n) {
        if(s[i] == '(') {
            sum[i+1] = sum[i]+1;
        } else {
            sum[i+1] = sum[i]-1;
            mi = min(mi, sum[i+1]);
        }
    }
    int x = sum[0] - mi;
    int y = sum[n] - mi;

    rep(i, x) {
        cout << '(';
    }
    cout << s;
    rep(i, y) {
        cout << ')';
    }
    cout << '\n';
}