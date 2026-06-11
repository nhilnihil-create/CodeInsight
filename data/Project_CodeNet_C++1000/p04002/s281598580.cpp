#pragma region include
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <cstdio>
#include <tuple>
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
#define MOD (1e9+7)
#define INF (1e9)
#define LLINF (4e18)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
void input() {}
template<typename... R> void input(int& f, R&... r) { scanf("%d", &f); input(r...); }
template<typename... R> void input(double& f, R&... r) { scanf("%lf", &f); input(r...); }
template<typename... R> void input(ll& f, R&... r) { scanf("%lld", &f); input(r...); }
template<typename... R> void input(char& f, R&... r) { scanf("%c", &f); input(r...); }
template<typename... R> void input(string& f, R&... r) { cin >> f; input(r...); }
template<typename T, typename... R> void input(vector<T>& f, R&... r) { REP(i, f.size())input(f[i]); input(r...); }
#pragma endregion

int main() {
    int h, w, n; input(h,w,n);
    vector<int> a(n), b(n);
    map<PII, ll> mp;
    int dx[] = {-1,0,1,-1,0,1,-1,0,1}, dy[] = {-1,-1,-1,0,0,0,1,1,1};
    REP(i, n) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        REP(j, 9) {
            int x = a[i] + dx[j], y = b[i] + dy[j];
            if (x > 0 && x < h - 1 && y > 0 && y < w - 1) mp[PII(x, y)]++;
        }
    }
    vector<ll> cnt(10, 0);
    ll sum = 0;
    for (auto p : mp) {
        cnt[p.second]++;
        sum++;
    }
    cnt[0] = (ll)(h - 2)*(w - 2) - sum;
    REP(i, 10) {
        cout << cnt[i] << endl;
    }
    getchar(); getchar();
}