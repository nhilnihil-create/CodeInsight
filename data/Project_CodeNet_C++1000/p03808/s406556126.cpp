#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

long long N;

int main() {
    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    if (sum % (N * (N + 1) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
    }
    long long cnt = sum * 2 / N / (N + 1);
    vector<long long> D(N);
    D[0] = A[0] - A[N - 1] - cnt;
    for (int i = 1; i < N; i++) {
        D[i] = A[i] - A[i - 1] - cnt;
    }
    for (int i = 0; i < N; i++) {
        if (D[i] == 0) continue;
        if (D[i] % N != 0 || D[i] > 0) {
            cout << "NO" << endl;
            return 0;
        }
        cnt += D[i] / N;
    }
    cout << (cnt == 0? "YES": "NO") << endl;
}


