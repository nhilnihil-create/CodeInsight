#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N, M;
        cin >> N >> M;
        vector<bool> A(N, false);
        vector<bool> B(N, false);
        for (int i = 0; i < M; ++i) {
                ll a, b; cin >> a >> b;
                if (a == 1) {
                        A[b-1] = true;
                }
                if (b == N) {
                        B[a-1] = true;
                }
        }
        for (int i = 0; i < N; ++i) {
                if (A[i] == true && B[i] == true) {
                        cout << "POSSIBLE" << endl;
                        exit(0);
                }
        }
        cout << "IMPOSSIBLE" << endl;
}
