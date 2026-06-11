# include <bits/stdc++.h>

# define fr first
# define sc second
# define ll unsigned long long
# define mk make_pair
# define pb emplace_back
# define sz(s) (int)s.size()
# define all(s) s.begin(), s.end()

using namespace std;

const int N = 2e5+10;
const int inf = 1e9+7;

int n, m, ans;
int x[N], y[N], z[N];

int main () {
    scanf("%d%d", &n, &m);
    for(int i = 1, l; i <= n; i++) {
        scanf("%d", &l);
        x[l]++;
        y[l % m]++;
    }
    for(int i = 1; i <= 100001; i++) {
        z[i % m] += x[i] / 2;
    }

    for(int i = 0; i <= m / 2; i++) {
        if(i == (m - i) % m) {
            ans += y[i] / 2;
            continue;
        }
        int o = (m - i) % m;
        ans += min(y[i], y[o]);
        if(y[i] > y[o]) {
            ans += min((y[i] - y[o]) / 2, z[i]);
        }
        else {
            ans += min((y[o] - y[i]) / 2, z[o]);
        }
    }
    cout << ans << endl;
}

