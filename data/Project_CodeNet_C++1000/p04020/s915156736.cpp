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
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    
    ll sum = 0;
    int pre = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) {
            pre = 0;
            continue;
        }
        sum += (a[i] + pre) / 2;
        if ((a[i]+pre) % 2 == 0) pre = 0;
        else pre = 1;

        cerr << i << " " << sum << " " << pre << endl;
        
    }

    cout << sum << endl;
    
    return 0;
}