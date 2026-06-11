#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, ll> pcl;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(mp(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define mp make_pair
#define pb push_back
#define INF (1 << 29)
const int mod = 1000000007;

int main() {
    string s;
    cin >> s;

    int n = s.size() - 1;
    ll ans = 0;
    for(int bit = 0; bit < (1 << n); bit++) {
        ll sum = 0, pre = 0;
        for(int i = 0; i <= n; i++) {
            pre *= 10;
            pre += s[i] - '0';
            if(i == n) {
                sum += pre;
                break;
            }
            if(bit & (1 << i)) {
                sum += pre;
                pre = 0;
            }
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}