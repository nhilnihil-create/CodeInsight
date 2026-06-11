#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 < A[i] && A[A[i] - 1] == i + 1) cnt++;
    }
    cout << cnt << endl;
}
