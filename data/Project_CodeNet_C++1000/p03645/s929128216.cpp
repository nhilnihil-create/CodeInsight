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
    vector<int> fromSt(N+1), toEnd(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == 1) fromSt[b] = 1;
        if (b == N) toEnd[a] = 1;
    }
    for (int i = 1; i < N; i++) {
        if (fromSt[i] && toEnd[i]) {
            cout << "POSSIBLE" << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
