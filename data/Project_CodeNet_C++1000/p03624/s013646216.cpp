#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string s;
    cin >> s;
    vector<int>arr(26,0);
    for (auto ss: s) {
        arr[ss - 'a']++;
    }
    rep(i, 26) {
        if (arr[i] == 0) {
            cout << char('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
