#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> r(n+1);
    rep(i, n){
        int p;
        cin >> p;
        r[p] = i+1;
    }

    const ll p = 3e4;
    rep(i, n) cout << p * (i + 1) << " ";
    cout << endl;
    rep(i, n) cout << p * (n-i-1) + r[i+1] << " ";
    cout << endl;
}