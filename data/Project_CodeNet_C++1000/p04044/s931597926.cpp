#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n,l;
    cin >> n >> l;
    vector<string> s(n);
    rep(i,n) cin >> s.at(i);

    sort(all(s));
    rep(i,n) cout << s.at(i);
}