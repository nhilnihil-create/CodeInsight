#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int w, h, n;
    cin >> w >> h >> n;

    int x, y ,a;
    int wl, wr, hu, hd;
    wl = 0;
    wr = w;
    hu = h;
    hd = 0;
    for(int in=0;in<n;in++) {
        cin >> x >> y >> a;
        if(a==1) wl = max(wl, x);
        if(a==2) wr = min(wr, x);
        if(a==3) hd = max(hd, y);
        if(a==4) hu = min(hu, y);
    }
    int ans;
    ans = (wr-wl)*(hu-hd);
    cout << ((wr-wl>0&&hu-hd) ? ans : 0);
    cout << endl;
    return 0;
}
