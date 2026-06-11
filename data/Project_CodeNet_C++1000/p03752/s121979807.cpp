#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(long long int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1LL << 60);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    fill((T*)array, (T*)(array + N), val);
}
int main() {
    ll n, k, a[15], sum, ans = INF; cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, (1 << n)) {
        int cnt = 0;
        rep(j, n) {
            if (i & (1 << j))cnt++;
        }
        if (cnt == k) {
            sum = 0; ll h = a[0];
            req(l, n - 1) {
                if (i & (1 << l)) {
                    sum += max((ll)0, h - a[l] + 1);
                    h = max(h + 1, a[l]);
                }
                else h = max(h, a[l]);
            }
            ans = min(ans, sum);
        }
    }cout << ans << endl;
}