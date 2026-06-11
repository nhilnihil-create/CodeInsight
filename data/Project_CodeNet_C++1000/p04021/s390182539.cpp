#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    map<int, bool> c;
    for(int i=0; i<N; ++i) c[A[i]] = (i & 1);
    sort(begin(A), end(A));

    int res = 0;
    for(int i=0; i<N; ++i) {
        if(c[A[i]] != (i & 1)) ++res;
    }
    cout << res / 2 << endl;
}