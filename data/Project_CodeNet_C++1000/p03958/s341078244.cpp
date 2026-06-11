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
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    for (int i = 0; i < T; i++) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    int remain = K - mx;
    int ans = mx - remain - 1;
    cout << (ans > 0 ? ans : 0) << '\n';
}
