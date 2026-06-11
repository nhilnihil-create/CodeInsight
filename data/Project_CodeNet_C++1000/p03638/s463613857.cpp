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
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    int h, w; cin >> h >> w;
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    vector<vector<int>> ans(h,vector<int>(w));
    int now = 0;
    rep(i,h) {
        if (i%2==0) {
            rep(j,w) {
                if (a[now]==0) now++;
                ans[i][j] = now+1;
                a[now]--;
            }
        } else {
            repr(j,w-1) {
                if (a[now]==0) now++;
                ans[i][j] = now+1;
                a[now]--;
            }
        }
    }

    rep(i,h) {
        rep(j,w) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}