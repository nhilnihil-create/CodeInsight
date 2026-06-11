#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long N, ans = 1;
    vector<long> A;

    cin >> N;
    for (int i = 0; i < N; i++) {
        long a;
        cin >> a;
        A.push_back(a);
    }

    int flag = 0;
    for (int i = 0; i < N-1; i++) {
        if (A[i] < A[i+1]) flag |= 1;
        if (A[i] > A[i+1]) flag |= 2;
        if (flag == 3) {
            ans++;
            flag = 0;
        }
    }

    cout << ans <<endl;

    return 0;
}