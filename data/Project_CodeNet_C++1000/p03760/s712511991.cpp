#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string O, E;
    cin >> O >> E;

    string ans;

    int i = 0;
    while (i < O.size() || i < E.size()) {
        if (i < O.size()) ans.push_back(O.at(i));
        if (i < E.size()) ans.push_back(E.at(i));
        i++;
    }

    cout << ans << endl;

    return 0;
}