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
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= b; i++) {
        if ((i*a) % b == c) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}
