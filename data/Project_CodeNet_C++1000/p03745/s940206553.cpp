#include <bits/stdc++.h>

using namespace std;

int N;
int A[100000];

void solve() {
    int num = 0;
    reverse(A, A + N);
    for (int i = 0; i < N; ++i) {
        while (i + 1 < N && A[i] == A[i + 1]) ++i;
        if (i + 1 < N && A[i] < A[i + 1]) {
            while (i + 1 < N && A[i] <= A[i + 1])++i;
        } else if (i + 1 < N && A[i] > A[i + 1]) {
            while (i + 1 < N && A[i] >= A[i + 1]) ++i;
        }
        ++num;
    }
    printf("%d\n", num);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    solve();
    return 0;
}