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
    int n;
    cin >> n;
    vector<pii> v(n);
    for (pii &p : v) {
        int a, b;
        cin >> a >> b;
        p = pii(a, b);
    }
    sort(v.rbegin(), v.rend());
    cout << v[0].first + v[0].second << endl;

}
