#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define for1(i,n) for (ll i=0;i<(n);i++)
#define for2(i,m,n) for (ll i=(m);i<(n);i++)
#define for3(i,m,n,d) for (ll i=(m);i<(n);i+=(d))
#define DEBUG 0

const ll MOD = 1000000007;

ll solve()
{
    ll N;
    string S1,S2;
    cin >> N;
    cin >> S1;
    cin >> S2;
    ll ans = 0;
    ll pre = 0;
    for1 (i, N) {
        if (S1[i] == S2[i]) {
            if (i == 0) {
                ans = 3;
            } else if (pre == 1) {
                ans = (ans * 2) % MOD;
            } else {
                ans = (ans * 1) % MOD;
            }
            pre = 1;
        } else {
            if (i == 0) {
                ans = 6;
            } else if (pre == 1) {
                ans = (ans * 2) % MOD;
            } else {
                // 1 22 22 33
                // 2 11 33 11
                ans = (ans * 3) % MOD;
            }
            i += 1;
            pre = 2;
        }
    }

    return ans;
}

int main()
{
    do {
        cout << solve() << endl;
    } while (DEBUG);
}
