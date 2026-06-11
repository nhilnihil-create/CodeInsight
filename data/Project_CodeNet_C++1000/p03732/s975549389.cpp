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
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj),rend(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1LL << 60);
const int INf = 1e9;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    fill((T*)array, (T*)(array + N), val);
}
int main() {   
    ll n, w, a = 0, b,e,sum,ans = 0,wei; cin >> n >> w;
    vector<ll> v1, v2, v3, v4;
    rep(i, n) {
        cin >> a >> e;
        if (i == 0) {
            b = a;
            v1.push_back(e);
        }
        else if (b == a) v1.push_back(e);
        else if (b + 1 == a)v2.push_back(e);
        else if (b + 2 == a)v3.push_back(e);
        else v4.push_back(e);
    }sort(RALL(v1)); sort(RALL(v2)); sort(RALL(v3)); sort(RALL(v4));
    rep(i, v1.size() - 1) v1[i + 1] += v1[i];
    rep(i, v2.size() - 1)v2[i + 1] += v2[i];
    rep(i, v3.size() - 1)v3[i + 1] += v3[i];
    rep(i, v4.size() - 1) v4[i + 1] += v4[i];
    v1.push_back(0); v2.push_back(0); v3.push_back(0); v4.push_back(0);
    rotate(v1.rbegin(), v1.rbegin() + 1, v1.rend());
    rotate(v2.rbegin(), v2.rbegin() + 1, v2.rend());
    rotate(v3.rbegin(), v3.rbegin() + 1, v3.rend());
    rotate(v4.rbegin(), v4.rbegin() + 1, v4.rend());
    rep(i, v1.size()) {
        rep(j, v2.size()) {
            rep(k, v3.size()) {
                rep(l, v4.size()) {
                    wei = b * i + (b + 1) * j + (b + 2) * k + (b + 3) * l;
                    if (wei > w) continue;
                    sum = v1[i] + v2[j] + v3[k] + v4[l];
                    ans = max(ans, sum);

                }
            }
        }
    }cout << ans << endl;
}