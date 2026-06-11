#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    int ans1 = A * 100, ans2 = 0;
    rep(i, 31) {
        rep(j, 31) {
            int water = 100 * A * i + 100 * B * j;
            if(water > F) break;
            int limit = (water/100) * E;
            rep(s, 1501) {
                rep(t, 1501) {
                    int sugar = C * s + D * t;
                    if(water + sugar > F) break;
                    if(sugar > limit) break;
                    if(100 * sugar * (ans1 + ans2) > 100 * ans2*(sugar + water)) {
                        ans1 = water;
                        ans2 = sugar;
                    }

                }
            }
        }
    }
    cout << ans1 + ans2 << " " << ans2 << endl;

    return 0;
}
// 100b/(a + b) > 100B/(A + B)
// 100b(A + B) > 100B(a + b);