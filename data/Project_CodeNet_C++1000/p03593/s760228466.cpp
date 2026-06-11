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

int cnt[26];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    string S[110];
    rep(i, H) cin >> S[i];
    rep(i, H) {
        rep(j, W) {
            cnt[S[i][j] - 'a']++;
        }
    }
    int cnt1 = 0, cnt2 = 0, cnt4 = 0;
    rep(i, 26) {
        int tmp = cnt[i] / 4;
        cnt4 += tmp;
        cnt[i] -= tmp * 4;
        tmp = cnt[i] / 2;
        cnt2 += tmp;
        cnt[i] -= tmp * 2;
        cnt1 += cnt[i];
        cnt[i] = 0;
    }
    //cout << cnt1 << " " << cnt2 << " " << cnt4 << endl;
    int need1 = 0, need2 = 0, need4 = 0;
    if(H % 2 && W % 2) need1++;
    if(H % 2) need2 += W / 2;
    if(W % 2) need2 += H / 2;
    need4 += (H/2) * (W/2);
    //cout << need1 << " " << need2 << " " << need4 << " " << need1 + need2 * 2 + need4 * 4 << " " << H * W << endl;
    if(need4 < cnt4) {
        cnt4 -= need4;
        need4 = 0;
        cnt2 += cnt4 * 2;
        cnt4 = 0;
    }
    if(need2 < cnt2) {
        cnt2 -= need2;
        need2 = 0;
        cnt1 += cnt2 * 2;
        cnt2 = 0;
    }
    //cout << need1 << " " << need2 << " " << need4 << " " << need1 + need2 * 2 + need4 * 4 << " " << H * W << endl;
    if(need1 == cnt1 && need2 == cnt2 && need4 == cnt4) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
