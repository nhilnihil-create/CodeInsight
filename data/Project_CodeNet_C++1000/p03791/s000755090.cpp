#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int N = 1e5 + 100;

int n, a[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n; forn(i,n) cin >> a[i];

    ll ans = 1;

    int j = 0, start = a[0];
    forn(i,n) {
        while (j < n-1) {
            start = min(start, a[j] - 2*(j-i));
            if (start <= 0) break;
            j++;
        }
        ans = ans * (j+1-i) % MOD;
        start += 2;
    }
    ans %= MOD; if (ans < 0) ans += MOD;
    cout << ans << endl;
        


    return 0;
}
