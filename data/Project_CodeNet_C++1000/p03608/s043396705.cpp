#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, R;

    cin >> N >> M >> R;

    vector<int> r(R);
    vector<vector<int> > x(N, vector<int>(N, 1000000000));

    for(int i = 0; i < N; i++) {
        x[i][i] = 0;
    }

    for(int i = 0; i < R; i++) {
        cin >> r[i];
        r[i]--;
    }

    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        x[A][B] = C;
        x[B][A] = C;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                x[j][k] = min(x[j][k], x[j][i] + x[i][k]);
            }
        }
    }

    sort(r.begin(), r.end());

    int ans = 1000000000;

    do {
        int a = 0;
        for(int i = 0; i < r.size() - 1; i++) {
            a += x[r[i]][r[i + 1]];
        }
        ans = min(ans, a);
    } while(next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}