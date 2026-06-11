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
ll f(int x, vector<ll> a) {
    ll sum = 0, cost = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if (i % 2 == x) {
            if (sum <= 0) {
                cost += 1 - sum;
                sum = 1;
            }
        }
        else {
            if (sum >= 0) {
                cost += 1 + sum;
                sum = -1;
            }
        }
    }
    return cost;
}
/* main */
int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];


    // min(+-+-.... or -+-+....)
    cout << min(f(0, a), f(1, a)) << '\n';
}
