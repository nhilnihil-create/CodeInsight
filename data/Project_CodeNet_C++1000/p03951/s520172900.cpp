#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int a,index=0;
    string b, c;
    bool ans = false;
    cin >> a >> b >> c;
    index = a;
    rep(i, a) {
        ans = true;
        for (int j = 0; j < a - i; j++) {
            if (b[i + j] != c[j]) {
                ans = false;
                break;
            }
        }
        if (ans)break;
        else index ++;
    }
    cout << index << endl;
    return 0;
}