#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> x(N), y(N);
    vector<ll> nx(M), ny(M);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < M; i++) cin >> nx[i] >> ny[i];

    for (int i = 0; i < N; i++) {
        int ans = 0;
        ll mi = LINF;
        for (int j = 0; j < M; j++) {
            ll dist = abs(x[i] - nx[j]) + abs(y[i] - ny[j]);
            if (dist < mi) {
                mi = dist;
                ans = j;
            }
        }
        cout << ans + 1 << '\n';
    }
}
