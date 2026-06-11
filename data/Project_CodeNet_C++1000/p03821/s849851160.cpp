#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];
    
    ll sum = 0;
    for(int i = n-1; i >= 0; i--) {
        a[i] += sum;
        if (a[i] % b[i] == 0) sum = sum;
        else sum += b[i] - (a[i] % b[i]);
    }

    cout << sum << endl;
    
    return 0;
}