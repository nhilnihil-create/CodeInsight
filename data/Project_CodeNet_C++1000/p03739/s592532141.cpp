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
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    ll sum1 = 0, sum2 = 0;
    ll cost1 = 0, cost2 = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            if (sum1 + a[i] <= 0) {
                cost1 += 1 - sum1 - a[i];
                sum1 = 1;
            }
            else { sum1 += a[i]; }
            if (sum2 + a[i] >= 0) {
                cost2 += abs(-1 - sum2 - a[i]);
                sum2 = -1;
            }
            else { sum2 += a[i]; }
        }
        else {
            if (sum1 + a[i] >= 0) {
                cost1 += abs(-1 - sum1 - a[i]);
                sum1 = -1;
            }
            else { sum1 += a[i]; }
            if (sum2 + a[i] <= 0) {
                cost2 += 1 - sum2 - a[i];
                sum2 = 1;
            }
            else { sum2 += a[i]; }
        }
    }
    cout << min(cost1, cost2) << '\n';
}
