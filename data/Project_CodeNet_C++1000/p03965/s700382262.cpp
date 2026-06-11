#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    string s; cin >> s;
    int len = s.size();
    int ans = 0, gnum = 0;
    // pnum <= gnum
    // 常にgnum>=0
    // gnum>0の時のみpを出せる
    rep(i,len) {
        if (s[i]=='g') {
            if (gnum) {
                // p
                gnum--;
                ans++;
            } else {
                // g
                gnum++;
            }
        } else {
            if (gnum) {
                // p
                gnum--;
            } else {
                gnum++;
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
