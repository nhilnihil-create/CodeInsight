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
    int K, S;
    cin >> K >> S;

    int ans = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int z = S - (x + y);
            if (0 <= z && z <= K) ans++;
        }
    }

    cout << ans << '\n';
}
