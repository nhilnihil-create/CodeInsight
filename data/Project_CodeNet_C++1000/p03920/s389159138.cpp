// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

const int MAX_N = 100000;
int main(){
    iostream_init();
    LL N;
    cin >> N;
    LL sum[MAX_N] = {};
    LL first = -1;
    for(LL i = 1; i <= N; i++) {
        sum[i] = sum[i-1] + i;
        if(sum[i] >= N) {
            first = i;
            break;
        }
    }
    int idx = first;
    while(N > 0) {
        while(sum[idx-1] >= N) {
            idx--;
        }
        cout << idx << endl;
        N -= idx;
        idx--;
    }
    return 0;
}
