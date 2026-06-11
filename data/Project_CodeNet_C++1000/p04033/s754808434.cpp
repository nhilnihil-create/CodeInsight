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
    int a, b;
    cin >> a >> b;
    if (b < 0) {
        int d = abs(a - b) + 1;
        if (d % 2 == 1) cout << "Negative" << '\n';
        else cout << "Positive" << '\n';
    }
    else if (a <= 0 && 0 <= b) cout << "Zero" << '\n';
    else if (0 < a) cout << "Positive" << '\n';
}
