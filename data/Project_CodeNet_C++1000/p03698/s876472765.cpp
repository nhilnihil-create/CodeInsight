#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string n;
    bool ans = true;
    cin >> n;
    vector<int>ss(26,1);
    for (auto s : n) {
        ss[s - 'a']--;
    }
    for (auto a : ss)if (a < 0)ans = false;
    if (ans) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}
