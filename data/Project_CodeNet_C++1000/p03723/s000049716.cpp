#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 1 && b % 2 == 1 && c % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (a == b && a == c) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        int tmpa, tmpb, tmpc;
        tmpa = a; tmpb = b; tmpc = c;
        a = tmpb/2 + tmpc/2;
        b = tmpa/2 + tmpc/2;
        c = tmpa/2 + tmpb/2;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
