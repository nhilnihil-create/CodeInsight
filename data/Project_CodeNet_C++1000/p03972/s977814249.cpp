#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <regex>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;

int main() {
    long w, h;
    cin >> w >> h;
    
    vector<P> v;
    REP(i,w) {
        long a;
        cin >> a;
        v.push_back(P(a,0));
    }
    REP(i,h) {
        long a;
        cin >> a;
        v.push_back(P(a,1));
    }
    
    sort(v.begin(), v.end());
    
    long ans = 0;
    long vc = 0, cc = 0;
    long ec = 0;
    REP(i,v.size()) {
        if (ec == (w + 1) * (h + 1) - 1) {
            break;
        }
        if (v[i].second == 0) {
            cc++;
            ans += v[i].first * (h + 1 - vc);
            ec += h + 1 - vc;
        } else {
            vc++;
            ans += v[i].first * (w + 1 - cc);
            ec += w + 1 - cc;
        }
    }
    cout << ans << endl;
}
