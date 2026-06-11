#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    int M = 0;
    int ans;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        if (M < A) {
            M = A;
            ans = A+B;
        }
    }
    cout << ans << endl;
}