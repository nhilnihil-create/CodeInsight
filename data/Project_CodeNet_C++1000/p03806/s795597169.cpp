#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <bitset>
#include <iomanip>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, const char * argv[]) {
    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    struct Ch { int a, b, c; };
    vector<Ch> ch(N);
    for (int i = 0; i < N; i++) cin >> ch[i].a >> ch[i].b >> ch[i].c;

    int upper_bound = 1000000;
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(400+1, vector<int>(400+1, upper_bound)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int a = 0; a <= 10*40; a++) {
            for (int b = 0; b <= 10*40; b++) {
                if (a >= ch[i].a && b >= ch[i].b) {
                    dp[i+1][a][b] = min(dp[i][a-ch[i].a][b-ch[i].b] + ch[i].c, dp[i][a][b]);
                } else {
                    dp[i+1][a][b] = dp[i][a][b];
                }
            }
        }
    }
    int ans = upper_bound;
    for (int a = 1; a <= 400; a++) {
        for (int b = 1; b <= 400; b++) {
            if (a * Mb == b * Ma) ans = min(ans, dp[N][a][b]);
        }
    }
    cout << (ans < upper_bound ? ans : -1) << endl;

    return 0;
}