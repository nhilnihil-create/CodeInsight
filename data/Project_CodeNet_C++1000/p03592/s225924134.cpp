#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const int int_inf = 100000000;
const double eps = 1e-9;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if ((m-j)*i + (n-i)*j == k) {
                cout << "Yes" << endl;
                return 0;
            }  
        }
    }
    cout << "No" << endl;
    return 0;
}

