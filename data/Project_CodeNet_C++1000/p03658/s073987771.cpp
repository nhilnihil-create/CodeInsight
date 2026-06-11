#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int result = 0;
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    for (int i = 0; i < K; i++)
    {
        result += A[i];
    }
    cout << result << endl;
}