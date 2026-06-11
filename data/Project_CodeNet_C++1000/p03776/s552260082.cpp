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
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(ll i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e18;
const double eps = 1e-8;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MOD = 1000000007;
ll COM[51][51];
void COMint() {
    Fill(COM, 0);
    rep(i, 51) {
        rep(j, i+1) {
            if (j == 0 || i == j) COM[i][j] = 1LL;
            else COM[i][j] = COM[i - 1][j - 1] + COM[i - 1][j];
        }
    }
}
int main(void) {
    ll n, a, b; cin >> n >> a >> b;
    COMint();
    vector<ll> v(n); map<ll, int> mp,m;
    rep(i, n) {
        cin >> v[i]; mp[v[i]]++;
    }
    sort(RALL(v)); ll ans = 0,sum =0;
    rep(i, a)  ans += v[i],m[v[i]]++;
    if (v[0] == v[a - 1]) {
        for (int i = a; i <= b; i++) {
            int r = mp[v[a - 1]];
            sum += COM[r][i];
        }
    }
    else {
        sum = COM[mp[v[a - 1]]][m[v[a - 1]]];
    }cout << fixed << setprecision(10) << (ld)ans / a << endl;
    cout << sum << endl;
}