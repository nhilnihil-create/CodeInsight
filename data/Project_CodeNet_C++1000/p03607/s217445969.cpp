#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> ans;
    rep(i, n) ans[a[i]]++;
    int count = 0;
    for(auto p : ans) {
        if(p.second % 2 == 1) count++;
    }
    cout << count << endl;
}
