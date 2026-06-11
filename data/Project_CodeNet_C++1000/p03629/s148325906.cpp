#include <iostream>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <fstream>
#include <bitset>
#include <time.h>
#include <random>
#include <assert.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <stdexcept>
#include <iomanip>

#define LL long long
#define VI vector<int>
#define VL vector<long long>
#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define EPS 1e-14

using namespace std;



int main() {
    string A;
    cin >> A;
    auto n = A.size();

    // iの後ろではじめでてくる文字cのindex
    vector<vector<int>> next(n + 1, vector<int>(26, n));
    for(int i = n - 1; i >= 0; --i) {
        int c = A[i] - 'a';
        next[i] = next[i + 1];
        next[i][c] = i;
    }

    vector<int> dp(n + 2, 0);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; --i) {
        int l = INT_MAX;
        FOR(j, 0, 26) {
            l = min(l, dp[next[i][j] + 1] + 1);
        }
        dp[i] = l;
    }

    string ans;
    int p = 0;
    for (int i = dp[0] - 1; i >= 0; --i) {
        FOR(j, 0, 26) {
            if (dp[next[p][j] + 1] == i) {
                ans += char('a' + j);
                p = next[p][j] + 1;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
