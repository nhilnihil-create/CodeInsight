#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const int MOD = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    string s;
    cin >> s;
    if (s.size() < 4) cout << "No" << '\n';
    else cout << (s.substr(0, 4) == "YAKI" ? "Yes" : "No") << '\n';
}
