#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    // cout << 3 * N << endl;

    vector<long> A(3 * N);

    for (int i = 0; i < (3 * N); i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    long result = 0;
    for (int i = 1; i <= N; i++)
    {
        result+= A[2*i-1];
    }
    cout << result << endl;
}