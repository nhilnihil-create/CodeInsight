#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string a, b;
    cin >> a >> b;
    rep(i,min(a.size(), b.size())) {
        cout << a[i] << b[i];
    }
    if (a.size() > b.size())cout << a[a.size() - 1] << endl;
    else if(a.size() < b.size()) cout << b[b.size() - 1] << endl;
}