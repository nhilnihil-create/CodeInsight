#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, l;
    cin >> n >> l;
    vector<string> ss(n);
    rep(i, n) { cin >> ss[i]; }

    sort(ss.begin(), ss.end());
    rep(i, n) { cout << ss[i]; }
    cout << endl;
}