#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string a;
    int ai, zi;
    bool ba = true,bz = false;
    cin >> a;
    rep(i, a.size()) {
        if (ba && a[i] == 'A') {
            ba = false;
            ai = i;
        }
        if (a[i] == 'Z')zi = i;
    }

    cout << zi - ai+1 << endl;
}