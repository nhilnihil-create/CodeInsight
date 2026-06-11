#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, ma, mb;
    cin >> N >> ma >> mb;

    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);

    for(int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<vector<int> > > v(N, vector<vector<int> >(401, vector<int>(401, 10000)));

    v[0][0][0] = 0;
    v[0][a[0]][b[0]] = c[0];

    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= 400; j++) {
            for(int k = 0; k <= 400; k++) {
                v[i][j][k] = v[i - 1][j][k];
            }
        }
        for(int j = 0; j < 400; j++) {
            int as = j + a[i];
            if(as > 400) break;
            for(int k = 0; k < 400; k++) {
                int bs = k + b[i];
                if(bs > 400) break;
                v[i][as][bs] = min(v[i][as][bs], c[i] + v[i - 1][j][k]);
            }
        }
    }

    int ans = 10000;

    for(int i = 1; i <= 400; i++) {
        int as = ma * i;
        int bs = mb * i;
        if(as > 400 || bs > 400) break;
        ans = min(ans, v[N - 1][as][bs]);
    }

    if(ans >= 10000) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}