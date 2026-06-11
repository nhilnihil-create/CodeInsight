#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    vector<int> b(N);

    vector<int> c(M);
    vector<int> d(M);

    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> c[i] >> d[i];
    }

    for(int i = 0; i < N; i++) {
        int ans = 1;
        int count = pow(10, 9);
        for(int j = 0; j < M; j++) {
            if(abs(a[i] - c[j]) + abs(b[i] - d[j]) < count) {
                count = abs(a[i] - c[j]) + abs(b[i] - d[j]);
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
}