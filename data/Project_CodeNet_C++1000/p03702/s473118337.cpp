#pragma region include
#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
#define MOD (int)(1e9+7)
#define INF (int)(1e9)
#define LLINF (int)(4e18)
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

ll N, A, B;
vector<ll> h;

bool f(int k) {
    vector<ll> a = h;
    ll cnt = 0;
    REP(i, N) {
        a[i] -= B * k;
        if (a[i] > 0) {
            cnt += (a[i] + (A - B - 1)) / (A - B);  
        }
    }
    return cnt <= k;
}

// FFFFFTTTTT の時境界の右側を返す
int binarysearch() {
    int l = 0, r = INF;
    while (r - l > 1) {
        int k = (l - r) / 2 + r;
        if (f(k)) {
            r = k;
        }
        else {
            l = k;
        }
    }
    return r;
}

int main() {
    input(N,A,B);
    h.resize(N); input(h);
    cout << binarysearch() << endl;
    getchar(); getchar();
}