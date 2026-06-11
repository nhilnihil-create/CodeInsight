
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const long long INF = 2e18;
const long long MOD = 1e9+7;

#define sx(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i = 0; i < n; i++)
#define ALL(a) begin(a),end(a)

int main(void) {
    ll N;
    cin >> N;
    ll ok = 1e9+10;
    ll ng = -1;
    while(abs(ok-ng) > 1) {
        ll mid = (ok+ng)/2;
        if (mid*(mid+1)/2 >= N) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}