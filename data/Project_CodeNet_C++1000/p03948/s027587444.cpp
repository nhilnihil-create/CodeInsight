#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
typedef pair<int, int> P;
typedef pair<int, P> Pi;
typedef pair<P, P> PP;
 
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
 
template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int A[100000];
int maxi[100000], mini[100000];

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, T;
    cin >> N >> T;
    for(int i = 0; i < N; ++i) cin >> A[i];
    maxi[N - 1] = A[N - 1];
    for(int i = N - 2; i >= 0; --i) maxi[i] = max(maxi[i + 1], A[i]);
    int latte = 0;
    for(int i = 0; i < N; ++i) chmax(latte, maxi[i] - A[i]);
    int res = 0;
    for(int i = 0; i < N; ++i) if(latte == maxi[i] - A[i]) ++res;
    cout << res << endl;
    return 0;
}