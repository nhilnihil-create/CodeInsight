#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    pair < int , int > A[100005];
    int cnt = 0;
    cin >> N;
    for ( int i = 0; i < N; i++ ) { cin >> A[i].first; A[i].second = i; }
    sort(A, A + N);
    for ( int i = 0; i < N; i++ ) cnt += ((A[i].second + i) & 1);
    cout << cnt / 2 << endl;
    return ( 0 );
}
