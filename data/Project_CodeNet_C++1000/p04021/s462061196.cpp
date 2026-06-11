#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int A[100005], B[100005];
    int cnt = 0;
    cin >> N;
    for ( int i = 0; i < N; i++ ) { cin >> A[i]; B[i] = A[i]; }
    sort(B, B + N);
    for ( int i = 0; i < N; i++ ) cnt += (i + lower_bound(B, B + N, A[i]) - B) % 2;
    cout << cnt / 2 << endl;
    return ( 0 );
}