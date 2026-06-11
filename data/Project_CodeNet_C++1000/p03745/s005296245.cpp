#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 1;
    for (int i = 1; i < N; i++) {
        while (i < N && A[i - 1] == A[i]) i++;
        if (i >= N) break;
        if (A[i - 1] < A[i]) {
            while (i < N && A[i - 1] <= A[i]) i++;
        } else {
            while (i < N && A[i - 1] >= A[i]) i++;
        }
        if (i >= N) break;
        ans++;
    }

    cout << ans << endl;
}