#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 100000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, K;
    cin >> N >> K;
    vector<bool> D(10);
    for (int i = 0; i < K; i++) {
        int d; cin >> d;
        D[d] = true;
    }
    for (int ans = N; ans <= MAX; ans++) {
        int tmp = ans;
        bool can = true;
        while (tmp > 0) {
            if (D[tmp%10]) {
                can = false;
                break;
            }
            tmp /= 10;
        }
        if (can) {
            cout << ans << '\n';
            return 0;
        }
    }
}
