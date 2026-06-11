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
int man(pii p1, pii p2) { return abs(p1.first - p2.first) + abs(p1.second - p2.second); }
/* main */
int main(){
    int n, m;
    cin >> n >> m;
    vector<pii> stu(n), ch(m);

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        stu[i] = pii(a, b);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ch[i] = pii(a, b);
    }

    for (int i = 0; i < n; i++) {
        int minD = INF;
        int minI = 0;
        for (int j = 0; j < m; j++) {
            if (minD > man(stu[i], ch[j])) {
                minD = man(stu[i], ch[j]);
                minI = j+1;
            }
        }
        cout << minI << '\n';
    }
}
