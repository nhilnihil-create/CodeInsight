#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#pragma warning(disable:4996) 

typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define LINF3 1000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

char str[200005];
pair<int,pair<int,int> > dp[200005];    // dp0[i],dp1[i]: i文字目までについて、部分列に現れないベストの文字列の長さ、prev, 最後の文字
int dp0[200005];

void solve()
{
    scanf("%s", str);
    int n = strlen(str);
    int save[26] = { 0 };
    int i, k;
    for (i = 0; i <= n; i++) {
        pair<int,pair<int,int> > z = make_pair(INF, make_pair(INF, INF));
        for (k = 0; k < 26; k++) {
            int id=save[k] - 1;
            if (id >= 0) {
                int nextlen = dp[id].first + 1;
                pair<int,pair<int,int> > ztmp = make_pair(nextlen, make_pair(id, k));
                if (ztmp.first < z.first) {
                    z = ztmp;
                }
                else if (ztmp.first == z.first) {
                    int prev = z.second.first;
                    int prevtmp=ztmp.second.first;
                    if (dp0[prev] > dp0[prevtmp]) {
                        z = ztmp;
                    }
                }
            }
            else {
                int nextlen = 1;
                pair<int,pair<int,int> > ztmp = make_pair(nextlen, make_pair(id, k));
                z = MIN(z, ztmp);
            }
        }
        dp[i] = z;
        if (i > 0) {
            if (dp[i] != dp[i - 1]) {
                dp0[i] = dp0[i - 1] + 1;
            }
            else {
                dp0[i] = dp0[i - 1];
            }
        }
        if (i < n) {
            save[str[i] - 'a'] = i + 1;
        }
    }

    vector<char> s;
    int curr = n;
    while (dp[curr].first > 0) {
        s.push_back('a' + dp[curr].second.second);
        curr = dp[curr].second.first;
    }
    reverse(s.begin(), s.end());
    s.push_back('\0');
    printf("%s\n", &s[0]);

    return;
}


int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}
