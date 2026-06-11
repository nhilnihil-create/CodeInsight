#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,(n))
typedef long long ll;
using namespace std;

int main() {
    ll N, sum = 0;
    cin >> N;
    int A[N];
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    ll k = sum / (N * (N + 1) / 2);
    if (k * N * (N + 1) / 2 != sum) {
        cout << "NO" << endl;
        return 0;
    }
    int d[N];
    ll cnt = 0;
    rep(i, N) {
        d[i] = A[(i+1)%N] - A[i];
        d[i] -= k;
        if (d[i] % N) {
            cout << "NO" << endl;
            return 0;
        }
        cnt += abs(d[i] / N);
    }
    if (cnt != k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}