#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

const ll MOD = 1e9 + 7;
vll m(1010, 0);

void f(ll n) {
    for(ll i = 1; i <= n; i++) {
        ll t = i;
        for(ll j = 2; j * j <= n; j++) {
            if(t % j != 0) continue;
            ll ex = 0;
            while(t % j == 0) {
                ex++;
                t /= j;
            }
            m[j] += ex;
        }
        if(t != 1) m[t] += 1;
    }
    
    return;
}

int main() {
    ll n;
    cin >> n;

    f(n);

    ll ans = 1;
    rep(i, m.size()) {
        if(m[i] > 0) {
            ans *= (m[i] + 1);
            ans %= MOD;
        } 
    }

    cout << ans << endl;

    return 0;
}
