#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    string o, e;
    cin >> o >> e;
    if (o.size() == e.size()) {
        rep(i, o.size()) {
            cout << o[i] << e[i];
        }
    } else {
        rep(i, e.size()) {

            cout << o[i] << e[i];
        }
        cout<<o[o.size()-1];
    }

    return 0;
}
