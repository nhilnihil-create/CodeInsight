#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

const ll MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;

    if(abs(n - m) > 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    if(n == m) {
        rep(i, n) {
            ans *= (n - i);
            ans %= MOD;
        }
        rep(i, m) {
            ans *= (m - i);
            ans %= MOD;
        }
        ans *= 2;
        ans %= MOD;
    } else {
        rep(i, n) {
            ans *= (n - i);
            ans %= MOD;
        }
        rep(i, m) {
            ans *= (m - i);
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
