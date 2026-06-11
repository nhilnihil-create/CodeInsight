#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int n, l;
    cin >> n >> l;
    vector<string> vec(n);
    rep(i, n) cin >> vec[i];
    sort(all(vec));
    for (auto &x : vec) cout << x;
    cout << "\n";
}