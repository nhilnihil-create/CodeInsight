#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 29);
ll k, m, n,h,w,v;
const ll MOD= 1000000007;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    cin >> n >> h >> w;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    ll sum = 0,co;
    rep(i, n - 1) {
        co = min((x[i + 1] - x[i])*h, w);
        sum += co;
    }cout << sum << endl;
}