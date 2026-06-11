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
    string S;
    cin >> S;
    int cntS = 0, cntT = 0;
    int ans = S.size();
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'S') cntS++;
        else if (cntS > 0) cntS--, ans-= 2;
    }
    cout << ans << '\n';
}
