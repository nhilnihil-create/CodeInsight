#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> a(M);
    vector<int> b(M);
    vector<int> c(M);

    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    vector<vector<int> > v(N, vector<int>(N, 10000000));

    for(int i = 0; i < M; i++) {
        v[a[i]][b[i]] = c[i];
        v[b[i]][a[i]] = c[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < M; i++) {
        if(v[a[i]][b[i]] != c[i]) ans++;
    }

    cout << ans << endl;
}