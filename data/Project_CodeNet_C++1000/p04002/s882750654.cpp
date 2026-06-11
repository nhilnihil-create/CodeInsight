#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const int MOD = 1000000007;
const int inf = 1<<31-1;
int dx[9] = { -1,0,1,-1,0,1,-1,0,1 }, dy[9] = { -1,-1,-1,0,0,0,1,1,1 };
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(void) {
    int h, w,n,a,b; cin >> h >> w>>n;
    map<pair<int, int>, int> mp;
    vector<ll> ans(10, 0);
    rep(i, n) {
        cin >> a >> b; a--; b--;
        rep(j, 9) {
            int nx = b + dx[j], ny = a + dy[j];
            if (nx < 1 || ny < 1 || nx >= w - 1 || ny >= h - 1) continue;
            mp[pair<int,int>{ny, nx}]++;
        }
    }ll k = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans[it->second]++;
    }rep(i, 10) k += ans[i];
    cout <<(ll) (h-2)*(w-2) - k<<endl;
    req(i, 9) cout << ans[i]<<endl;
}