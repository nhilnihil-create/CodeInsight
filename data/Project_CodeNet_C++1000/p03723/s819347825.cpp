// 有點不耐煩會破壞偉大的計劃

#include <bits/stdc++.h>

#define append push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

void debug() {
	cerr << "\n";
}
template<typename Type1, typename... Type2>
void debug(Type1 a, Type2... b) {
    cerr << a << " ";
    debug(b...);
}

long long slow(long long &a, long long &b, long long &c) {
    long long cnt = 1000, ans = 0;
    while(cnt--){
        if((a & 1) + (b & 1) + (c & 1) > 0) break;
        long long x = (a & 1 ? 0 : a / 2);
        long long y = (b & 1 ? 0 : b / 2);
        long long z = (c & 1 ? 0 : c / 2);
        a = a + y + z - x * 2;
        b = b + x + z - y * 2;
        c = c + x + y - z * 2;
        ans++;
    }
    return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;

    long long ans = slow(a, b, c);

    if(ans == 1000) ans = -1;

    cout << ans;

    return 0;
}
