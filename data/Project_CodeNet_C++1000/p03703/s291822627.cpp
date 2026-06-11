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
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
class BIT{
private:
    vector<int> bit;
    int size_;
public:
    BIT() {
        size_ = 0;
        bit = vector<int>(0);
    }
    BIT(int size__) {
        size_ = size__;
        bit.resize(size_ + 1);
    }
    int sum(int i) {
        int ret = 0;
        while(i > 0) {
            ret += bit[i];
            i -= i & (-i);
        }
        return ret;
    }
 
    void add(int i, int x) {
        while(i <= size_) {
            bit[i] += x;
            i += i & (-i);
        }
    }
};
int sum[200010];
int tmp[200010];
map<int, int> mp;


signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int a[200010];
    rep(i, N) cin >> a[i];
    rep(i, N) a[i] -= K;
    rep(i, N) sum[i + 1] = sum[i] + a[i];
    rep(i, N + 1) tmp[i] = sum[i];
    sort(tmp, tmp + N + 1);
    int order = 1;
    rep(i, N + 1) {
        mp[tmp[i]] = order;
        if(i + 1 < N + 1 && tmp[i] < tmp[i + 1]) order++;
    }
    // rep(i, N + 1) cout << mp[sum[i]] << " ";
    // cout << endl;
    BIT B(N + 1);
    int ans = 0;
    rep(i, N + 1) {
        ans += i - B.sum(mp[sum[i]]);
        B.add(mp[sum[i]], 1);
        //cout << i << " " << ans << endl;
    }
    cout << N * (N + 1) / 2 - ans<< endl;


    return 0;
}
//0 -16 -22 -18 -4 0 -6 -22  
//6  3   1   2   5 6  4  1
