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
    int N, T; input(N, T);
    vector<int> a(N),m(N,0); input(a);
    m[N - 1] = a[N - 1];
    FOR(i, 1, N) {
        m[N - 1 - i] = max(a[N - 1 - i], m[N - i]);
    }
    int cnt = 0, t = -1;
    REP(i, N) {
        if (t == m[i] - a[i]) {
            cnt++;
        }
        else if (t < m[i] - a[i]){
            cnt = 1;
            t = m[i] - a[i];
        }
    }
    cout << cnt << endl;
    getchar(); getchar();
}