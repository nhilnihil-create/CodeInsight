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
    sort(a.rbegin(), a.rend());
    ll sum = accumulate(a.begin(), a.end(), 0LL);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        sum -= a[i];
        ans++;
        if (a[i] > 2 * sum) break;
    }
    cout << ans << '\n';
}
