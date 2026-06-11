#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n,maxs = 0, cnt=0;
    string s;
    cin >>n>> s;
    for (auto ss : s) {
        if (ss == 'I')cnt++;
        else cnt--;
        maxs = max(cnt, maxs);
    }
    cout << maxs << endl;
    return 0;
}