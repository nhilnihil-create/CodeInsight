#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

vll dx = {1, 0, -1, 0};
vll dy = {0, 1, 0, -1};

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll x, y;
    cin >> x >> y;

    // 0 - 0 : B, 1 - 1 : B, 2 - 1 : B, 2 - 2 : B, 3 - 2 : B
    // 2 - 0 : A, 3 - 0 : A, 3 - 1 : A, 4 - 0 : A, 4 - 1 : A, 4 - 2 : A,  5 - 0 : A, 6 - 0 : A
    ll z = abs(x - y);
    if (z <= 1) cout << "Brown" << endl;
    else cout << "Alice" << endl;
    return 0;
}