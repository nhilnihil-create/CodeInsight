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
    vector<int> cnt(100005, 0);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        cnt[a+1]++;
    }
    int mx = 0;
    for (int i = 1; i <= 100001; i++) {
        mx = max(mx, cnt[i-1] + cnt[i] + cnt[i+1]);
    }
    cout << mx << '\n';
}
